import sys
import math

print("Este código permite que el usuario elija una figura para poder calcular su área.")

#Menu inicio
while True:
    print("\n¿De qué figura deseas obtener su área?")
    print("\n 1. Ingresa A para triángulo. \n 2. Ingresa B para rectángulo.\n 3. Ingresa C para cuadrado.\n 4. Ingresa X para salir.")

    opcion=input("\n  Elige la figura que deseas usar: ")

    #Triángulo
    if opcion == "1" or opcion.upper() == "A":
        while True:
            try:
                b1=float(input("\n   Ingresa el valor de la base: "))
                a1=float(input("   Ingresa el valor de la altura: "))
                area_triangulo= (b1 * a1) / 2
                print(f"\n    El área del triángulo es: {round(area_triangulo,4)}")
                break
            except ValueError:
                print("Ingresa un número válido, puedes usar decimales, pero no letras.")

    #Círculo
    elif opcion == "2" or opcion.upper() == "B":
        while True:
            try:
                r2=float(input("\n   Ingresa el valor del radio: "))
                area_circulo = math.pi * (r2**2)            
                print(f"\n    El área del círculo es: {round(area_circulo,4)}")
                break
            except ValueError:
                print("Ingresa un número válido, puedes usar decimales, pero no letras.")

    #Rectángulo
    elif opcion == "3" or opcion.upper() == "C":
        while True:
            try:
                b3= float(input("\n   Ingresa el valor de la base del rectángulo: "))
                a3= float(input("   Ingresa el valor de la altura del rectángulo: "))
                area_rectangulo=b3*a3
                print(f"\n    El área del círculo es: {round(area_rectangulo,4)}")
                break
            except ValueError:
                print("Ingresa un número válido, puedes usar decimales, pero no letras.")

    # Opción salir   
    elif opcion == "4" or opcion.upper() == "X":
        print("\nSaliendo del código.")
        sys.exit()

    # Mensaje para opciones no válidas
    else:
        print("\nIngresaste algo erróneo, vuelve a intentarlo en el menú principal.")

    for i in range(1):
        input("\n\nPresiona Enter para regresar al menú principal...")
    