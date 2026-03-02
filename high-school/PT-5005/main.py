print("Este código permite mostrar al usuario diferentes menús para que eliga su bebida.")

#Menu inicio
while True:
    print("\n¿Qué desea ordenar?")
    print("\n 1 Ingresa A para agua. \n 2 Ingresa R para refresco.\n 3 Ingresa X para salir.")
    
    opcion=input("Escribe tu elección: ")
    #Opción agua
    if opcion == "A" or opcion == "a" or opcion == "1":
        while True:
            print("\n ¿Cómo desea su bebida?")
            print(" 1 Mineral.\n 2 Sin gas.")
            opcion=input("Escribe tu elección: ")
            
            while True:
                if opcion == "A" or opcion == "a" or opcion == "1":
                    print("\n Elegiste agua mineral. ¿Agregamos hielo?")
                    print(" 1 Con hielo.\n 2 Sin hielo.")
                    opcion=input("Escribe tu elección: ")
                    if opcion == "A" or opcion == "a" or opcion == "1":
                        print("\n  Seleccionaste agua mineral con hielo. En un momento tendrás tu bebida.")
                    elif opcion == "B" or opcion == "b" or opcion == "2":
                        print("\n  Seleccionaste agua mineral sin hielo. En un momento tendrás tu bebida.")
                    else:
                        print("Selección incorrecta. Inténtalo de nuevo.")
                        break
                    break
                    
                elif opcion == "B" or opcion == "b" or opcion == "2":
                    print("\n Elegiste agua sin gas. ¿Agregamos hielo?")
                    print(" 1 Con hielo.\n 2 Sin hielo.")
                    opcion=input("Escribe tu elección: ")
                else:
                    print("Selección incorrecta. Inténtalo de nuevo.")
                    if opcion == "A" or opcion == "a" or opcion == "1":
                        print("\n  Seleccionaste agua sin gas con hielo. En un momento tendrás tu bebida.")
                    elif opcion == "B" or opcion == "b" or opcion == "2":
                        print("\n  Seleccionaste agua sin gas y sin hielo. En un momento tendrás tu bebida.")
                    else:
                        print("Selección incorrecta. Inténtalo de nuevo.")
                        break
                    break 
            break

    #Opción refresco
    elif opcion == "R" or opcion == "r" or opcion == "2":
        while True:
            print("\n ¿De qué sabor lo desea?")
            print(" 1 Manzanita.\n 2 Sprite.")
            opcion=input("Escribe tu elección: ")
            
            while True:
                if opcion == "A" or opcion == "a" or opcion == "1":
                    print("\n Elegiste refresco de Manzanita. ¿Agregamos hielo?")
                    print(" 1 Con hielo.\n 2 Sin hielo.")
                    opcion=input("Escribe tu elección: ")
                    if opcion == "A" or opcion == "a" or opcion == "1":
                        print("\n  Seleccionaste refresco de Manzanita con hielo. En un momento tendrás tu bebida.")
                    elif opcion == "B" or opcion == "b" or opcion == "2":
                        print("\n  Seleccionaste refresco de Manzanita sin hielo. En un momento tendrás tu bebida.")
                    else:
                        print("Selección incorrecta. Inténtalo de nuevo.")
                        break
                    break
                
                elif opcion == "B" or opcion == "b" or opcion == "2":
                    print("\n Elegiste refresco Sprite. ¿Agregamos hielo?")
                    print(" 1 Con hielo.\n 2 Sin hielo.")
                    opcion=input("Escribe tu elección: ")
                else:
                    print("Selección incorrecta. Inténtalo de nuevo.")
                    if opcion == "A" or opcion == "a" or opcion == "1":
                        print("\n  Seleccionaste refresco Sprite con hielo. En un momento tendrás tu bebida.")
                    elif opcion == "B" or opcion == "b" or opcion == "2":
                        print("\n  Seleccionaste refresco Sprite sin hielo. En un momento tendrás tu bebida.")
                    else:
                        print("Selección incorrecta. Inténtalo de nuevo.")
                        break
                    break
     
     #Opción salir   
    elif opcion == "X" or opcion == "x" or opcion == "3":
        print("\n Gracias, esperamos su visita nuevamente.")
        break
        ("Escribe tu elección: ")
    
    else:
        print("\n  Ingresaste algo erróneo, vuelve a intentarlo.")
        input("Teclea cualquier caracter para continuar. ")
