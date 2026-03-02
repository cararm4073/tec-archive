from machine import Pin, ADC
from machine import Pin 
import utime

LedOn = machine.Pin(9, machine.Pin.OUT)
LedTemp = machine.Pin(12, machine.Pin.OUT)
LedHum = machine.Pin(13, machine.Pin.OUT)
LedPress = machine.Pin(14, machine.Pin.OUT)
LedLight = machine.Pin(15, machine.Pin.OUT)
LedV1 = machine.Pin(16, machine.Pin.OUT)
LedV2 = machine.Pin(17, machine.Pin.OUT)
LedA1 = machine.Pin(18, machine.Pin.OUT)
LedA2 = machine.Pin(19, machine.Pin.OUT)
LedR1 = machine.Pin(20, machine.Pin.OUT)
LedR2 = machine.Pin(21, machine.Pin.OUT)
boton1 = machine.Pin(6, machine.Pin.IN)
boton2 = machine.Pin(7, machine.Pin.IN)
potentiometer = ADC(26)

contador_onoff=0
contador_select=0

#Control de LEDs
def led_apagado():
    LedV1.off()
    LedV2.off()
    LedA1.off()
    LedA2.off()
    LedR1.off()
    LedR2.off()
    
def apagado():
    LedTemp.off()
    LedHum.off ()
    LedPress.off()	
    LedLight.off()

def prendido(num_leds):
    leds = [LedV1, LedV2, LedA1, LedA2, LedR1, LedR2]
    led_apagado()
    for i in range(num_leds):
        leds[i].on()   

#Sensor luz
def leer_sensor_luz():
    luz = potentiometer.read_u16() 
    print("Valor de luz: ",luz)
    if luz > 12000:
        prendido(6)
    elif luz > 8000:
        prendido(5)
    elif luz > 4000:
        prendido(4)
    elif luz > 1500:
        prendido(3)
    elif luz > 800:
        prendido(2)
    elif luz > 200:
        prendido(1)
    else:
        led_apagado()

#Botones, mediciones y variables
def button_handler(pin):
    global contador_onoff
    global contador_select
    
    #Boton onoff
    if pin is boton1:
        contador_onoff+=1
        if contador_onoff==1:
            print("\nSistema prendido\n")
            led_apagado()
            apagado()
            LedOn.on()
        elif contador_onoff==2:
            print("\nSistema apagado\n")
            contador_onoff=0
            contador_select==0
            led_apagado()
            apagado()
            LedOn.off()
    
    #Boton select
    if pin is boton2:

        if contador_onoff==1:
            contador_select += 1
           
            #Temperatura
            if contador_select == 1:
                apagado()
                led_apagado()
                LedTemp.on()
                print("\nBotón select: ",contador_select)

            #Humedad
            elif contador_select == 2:
                apagado()
                led_apagado()
                LedHum.on()
                print("\nBotón select: ",contador_select)
                    
            #Presión
            elif contador_select == 3:
                apagado()
                led_apagado()
                LedPress.on()
                print("\nBotón select: ",contador_select)
                    
            #Luz
            elif contador_select == 4:
                apagado()
                led_apagado()
                LedLight.on()
                print("\nBotón select: ",contador_select)
            
            #Resetea contador
            elif contador_select ==5:
                apagado()
                led_apagado()
                contador_select=0
                print("\nBotón select reset")
        else:
            apagado()

boton1.irq(trigger=machine.Pin.IRQ_FALLING, handler=button_handler)
boton2.irq(trigger=machine.Pin.IRQ_FALLING, handler=button_handler)

while True:
    if contador_onoff == 1 and contador_select == 1:
        utime.sleep(1) #CAMBIAR ESTE CODIGO
    elif contador_onoff == 1 and contador_select == 2:
        utime.sleep(1) #CAMBIAR ESTE CODIGO
    elif contador_onoff == 1 and contador_select == 3:
        utime.sleep(1) #CAMBIAR ESTE CODIGO
    elif contador_onoff == 1 and contador_select == 4:
        leer_sensor_luz()
        utime.sleep(1)
    elif contador_onoff == 1 and contador_select == 0:
        utime.sleep(1) #Evita sobrecarga y bucle innecesario
    
