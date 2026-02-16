import os                                                          #Para interactuar directamente con el sistema operativo de la Raspberry
import time                                                        #Para los sleep
import threading                                                   #Necesario para el de varias acciones simultaneas (web y mediciones)
import subprocess                                                  #Necesario para el manejo de acciones entre el código y el sistema (guardar un archivo temporal)
import smbus2                                                      #Necesario para la comunicación I2C (sensores)
import bme280                                                      #Sensor de humedad, temperatura y presión
import RPi.GPIO as GPIO                                            #Manejo de GPIO de la placa
import speech_recognition as sr                                    #Reconocimiento de voz
from flask import Flask, jsonify, request, render_template_string  #Necesario para el servidor web local

#   CONFIGURACION PINES
BUTTON1_PIN      = 16  # botón 1: encender/apagar sistema
BUTTON2_PIN      = 18  # botón 2: cambiar modo de medición
VOICE_BUTTON_PIN = 32  # botón para la detección de voz
TRIG_PIN         = 26  # sensor proximidad
ECHO_PIN         = 24  # sensor proximidad
LED_ON_PIN       = 31  # LED que indica sistema encendido

#   LED DE DATOS
LED_PINS = [37,35,33,29,40,38]  

#   VARIABLES GLOBALES
onoff_sistema = False
medicion       = 0  # 0=temp,1=presión,2=humedad
datos_actuales = {"tipo":"desconocido","valor":0.0,"timestamp":"00:00:00"}

#   CONFIG GPIO DE LA RASP
GPIO.setmode(GPIO.BOARD)
for pin in (BUTTON1_PIN, BUTTON2_PIN, VOICE_BUTTON_PIN):
    GPIO.setup(pin, GPIO.IN, pull_up_down=GPIO.PUD_UP)
GPIO.setup(LED_ON_PIN, GPIO.OUT)
for pin in LED_PINS:
    GPIO.setup(pin, GPIO.OUT)
GPIO.setup(TRIG_PIN, GPIO.OUT)
GPIO.setup(ECHO_PIN, GPIO.IN)
GPIO.output(LED_ON_PIN, GPIO.LOW)

#   CONFIGURACION INICIO BME280
bus     = smbus2.SMBus(1)
address = 0x76
calib   = bme280.load_calibration_params(bus, address)

#   CONFIG PARA FLASK APP
#nos podemos conectar a la IP local de la rasp para ver las mediciones y cambiar entre los diferentes modos de medición
app = Flask(__name__)
import logging
log = logging.getLogger('werkzeug')
log.setLevel(logging.ERROR)

#HTML (página) a mostrar al conectarnos a la IP local. Se ocupó inteligencia artificial para poder implementar de la mejor forma el sitio con el manejo del código en la rasp
INDEX_HTML = """
<!doctype html>
<html>
<head>
  <meta charset="utf-8">
  <title>Mediciones RPi</title>
  <style>
    body { font-family:sans-serif; text-align:center; padding:40px; }
    .card { display:inline-block; padding:20px; border:1px solid #ccc; border-radius:8px; }
    button { margin:5px;padding:10px 20px;font-size:16px; }
  </style>
</head>
<body>
  <h1>Medición Actual</h1>
  <div class="card">
    <p><strong>Tipo:</strong> <span id="tipo">–</span></p>
    <p><strong>Valor:</strong> <span id="valor">–</span></p>
    <p><strong>Hora:</strong> <span id="hora">–</span></p>
  </div>
  <div style="margin-top:20px;">
    <button onclick="fetch('/toggle',{method:'POST'}).then(actualizar)">Encender/Apagar</button>
    <button onclick="fetch('/cambiar',{method:'POST'}).then(actualizar)" >Cambiar Modo</button>
  </div>
  <script>
    function actualizar(){
      fetch('/datos')
        .then(r=>r.json())
        .then(d=>{
          document.getElementById('tipo').innerText = d.tipo;
          document.getElementById('valor').innerText = d.valor;
          document.getElementById('hora').innerText = d.timestamp;
        });
    }
    setInterval(actualizar,2000);
    actualizar();
  </script>
</body>
</html>
"""

@app.route('/')
def index():
    return render_template_string(INDEX_HTML)

@app.route('/datos')
def datos():
    return jsonify(datos_actuales)

@app.route('/toggle', methods=['POST'])
def web_toggle():
    toggle_sistema()
    return ('',204)

@app.route('/cambiar', methods=['POST'])
def web_cambiar():
    cambiar_medicion()
    return ('',204)

def iniciar_flask():
    app.run(host='0.0.0.0',port=5000,debug=False,use_reloader=False)

#       FUNCIONES GENERALES
#   prender y apagar sistema
def toggle_sistema():
    global onoff_sistema
    onoff_sistema = not onoff_sistema
    GPIO.output(LED_ON_PIN, GPIO.HIGH if onoff_sistema else GPIO.LOW)
    if not onoff_sistema:
        for p in LED_PINS: GPIO.output(p, False)
    print("Sistema ENCENDIDO" if onoff_sistema else "Sistema APAGADO")

#   cambiar modo medición
def cambiar_medicion():
    global medicion
    if not onoff_sistema: return
    medicion = (medicion+1)%3 # suma uno a la variable, y cuando llega a 3 se resetea a 0
    nombres = ['Temperatura','Presión','Humedad'] 
    print(f"Modo cambiado a: {nombres[medicion]}") #Shell
    # parpadeo de LEDs 2 veces al cambiar de modo de medición
    for _ in range(2):
        for p in LED_PINS: GPIO.output(p, True)
        time.sleep(0.15)
        for p in LED_PINS: GPIO.output(p, False)
        time.sleep(0.15)

#   prender x cantidad de leds dependiendo del umbral de datos en el modo de medición
def leds_sistema(valor, umbrales):
    encendidos = sum(valor>=u for u in umbrales)
    for i,p in enumerate(LED_PINS):
        GPIO.output(p, i<encendidos)

#   tipos de mediciones y sus umbrales
def tomar_medicion():
    global datos_actuales
    try:
        data = bme280.sample(bus,address,calib)
    except Exception as e:
        print("Error sensor:",e)
        return
    if medicion==0:
        valor=data.temperature
        umbrales=[13,19,23,27,31,35]
        tipo="temperatura"
    elif medicion==1:
        valor=data.pressure
        umbrales=[700,720,740,760,780,800]
        tipo="presion"
    else:
        valor=data.humidity
        umbrales=[20,40,60,80,100,120]
        tipo="humedad"
    leds_sistema(valor,umbrales)
    datos_actuales.update({
        "tipo": tipo,
        "valor": round(valor,2),
        "timestamp": time.strftime("%H:%M:%S")
    })
    print(f"{tipo.capitalize()}: {valor:.2f}")

#   proximidad
#NO FUNCIONA, aunque se conecte el sensor, no se logra que funcione el cambio de modos con el sensor de proximidad

def medir_distancia():
    GPIO.output(TRIG_PIN,True)
    time.sleep(0.00001)
    GPIO.output(TRIG_PIN,False)
    start=time.time()
    while GPIO.input(ECHO_PIN)==0:
        start=time.time()
    while GPIO.input(ECHO_PIN)==1:
        end=time.time()
    dist=(end-start)*17150
    return dist

#   reconocimiento de voz usando un archivo wav grabado temporalmente, usando Google API (internet obligatorio para que funcione
#falta implementar la verificación de conectividad de internet para evitar cosas raras

recognizer = sr.Recognizer()
def escuchar_voz():
    if not onoff_sistema: return #solo "escucha" si el sistema está prendido
    print("Escuchando voz...")
    # grabar 4s a WAV temporal
    cmd = ["arecord","-D","plughw:2,0","-f","cd","-t","wav","-d","4","-q","/tmp/comando.wav"] #direccion del archivo temporal
    subprocess.run(cmd,stderr=subprocess.DEVNULL)
    try:
        with sr.AudioFile("/tmp/comando.wav") as source:
            audio = recognizer.record(source)
        txt = recognizer.recognize_google(audio,language="es-ES").lower()
        #manejo como tal lo que regresa la API de deteccion de voz en nuestro codigo, dependiendo del comando escuchado y el return en string
        print("Voz detectada:",txt)
        if "temperatura" in txt: medicion_set(0)
        elif "presión" in txt or "presion" in txt: medicion_set(1)
        elif "humedad" in txt: medicion_set(2)
        elif "apagar" in txt: toggle_sistema()
    except Exception as e:
        print("Error al detectar tu voz:",e)

#   reconocimiento de voz y cambio de modos con esta
def medicion_set(m):
    global medicion
    medicion=m
    print("Modo por voz:",["Temperatura","Presión","Humedad"][m])
    # parpadeo LEDs
    for _ in range(2):
        for p in LED_PINS: GPIO.output(p,True)
        time.sleep(0.15)
        for p in LED_PINS: GPIO.output(p,False)
        time.sleep(0.15)

#   loop principal del sistema

def main():
    tiempo_med= time.time()
    prev1, prev2 = True, True

    while True:
        b1 = GPIO.input(BUTTON1_PIN)
        b2 = GPIO.input(BUTTON2_PIN)
        vbtn = GPIO.input(VOICE_BUTTON_PIN)

        # Botón 1: toggle on/off del sistema
        if prev1 and not b1:
            print("Botón 1: toggle")
            toggle_sistema()
            time.sleep(0.3)
        # Botón 2: cambiar modo de medición
        if prev2 and not b2 and onoff_sistema:
            print("Botón 2: cambiar modo")
            cambiar_medicion()
            time.sleep(0.3)

        # empezar el reconocimiento de voz al presionar el botón 3
        if vbtn==GPIO.LOW:
            escuchar_voz()
            time.sleep(0.3)

        # mediciones periódicas generales
        if onoff_sistema and time.time()-tiempo_med>=2:
            tomar_medicion()
            tiempo_med=time.time()

        # oroximidad: cambia modo si <10cm (no funciona)
        if onoff_sistema and time.time()-tiempo_med>=2:
            d = medir_distancia()
            if d<10:
                print("Proximidad <10cm: cambiar modo")
                cambiar_medicion()
                time.sleep(0.5)

        prev1, prev2 = b1, b2
        time.sleep(0.05)

#UN poco más de configuración de threading para la continua ejecución del web local
if __name__=="__main__":
    try:
        threading.Thread(target=iniciar_flask,daemon=True).start()
        main()
    #Cuando se para manualmente el código, se libera el bus y los GPIO de la placa
    finally:
        bus.close()
        GPIO.cleanup()
        print("BUS y GPIO liberados...") #liberar los GPIO y BUSs de la placa para evitar problemas raros al volver a iniciar el codigo sin apagar el sistema como tal