# Importamos módulos necesarios
from sense_hat import SenseHat
from time import sleep
from random import randint

#Definimos variables ocupadas
sense = SenseHat()
white = (255, 255, 255)
black = (0, 0, 0)
green = (0, 255, 0)
red = (255, 0, 0)
score = 0
snake = [[2,4],[3,4], [4,4]]
vegetales = []
direction = "right"
counter = 0
score = 0
pausa = 0.6 #Variable para el aumento de velocidad

#Entradas joystick
def joystick_move(event):
    global direction
    if event.direction == "up" and direction != "down":
        direction = "up"
    elif event.direction == "down" and direction != "up":
        direction = "down"
    elif event.direction == "left" and direction != "right":
        direction = "left"
    elif event.direction == "right" and direction != "left":
        direction = "right"

#Mostrar serpiente en el SenseHat
def draw_snake():
    for segment in snake:
        sense.set_pixel(segment[0], segment[1], white)

#Movimientos generales de la serpiente
def move_snake():
    last = snake[-1]
    first = snake[0]
    next = list(last)

    if direction == "right":
        next[0] = (last[0] + 1) % 8
    elif direction == "left":
        next[0] = (last[0] - 1) % 8
    elif direction == "up":
        next[1] = (last[1] - 1) % 8
    elif direction == "down":
        next[1] = (last[1] + 1) % 8

    #Colisión con el cuerpo de la serpiente
    if next in snake:
        game_over()
        return

    # Puntuaje
    global counter, score, pausa
    if next in vegetales:
        vegetales.remove(next)
        counter += 1

        # Cada que se coma un vegetal, se le agrega un led a la longitud de la serpiente, también aumenta velocidad
        if counter % 3 == 0:
            snake.append(next)
            score += 1
            # Aumento de velocidad por cada tres alimentos ingeridos
            pausa = pausa / 1.1 #Divide la pausa que es el sleep, pero en realidad hace más rapido el "refresh" en el sensehat, y se ve que va más rápido todo al actualizar más rápido
            print("Score:", score)

    #Nuevos segmentos de la serpiente
    snake.append(next)
    sense.set_pixel(next[0], next[1], white)
    sense.set_pixel(first[0], first[1], black)
    snake.remove(first)

#Vegetales en la Sense Hat
def snake_veg():
    x = randint(0, 7)
    y = randint(0, 7)
    new = [x, y]
    sense.set_pixel(x, y, green)
    vegetales.append(new)

#Función para el fin del juego
def game_over():
    sense.show_message(f"Perdiste y tu score es:{score}")
    reset_game()

#Reiniciar el juego
def reset_game():
    global snake, vegetales, direction, score, pausa
    snake = [[2,4],[3,4], [4,4]]
    vegetales = []
    direction = "right"
    score = 0
    pausa = 0.6
    sense.clear()
    draw_snake()

#Inicializa la serpiente
sense.clear()
draw_snake() 
sense.stick.direction_any = joystick_move

#Llama las funciones en un bucle
while True:
    move_snake()
    sleep(pausa) #Aumento de velocidad
    if len(vegetales) < 3: #Solo aparecen 3 vegetales al mismo tiempo
        snake_veg()
