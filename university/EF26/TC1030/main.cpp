#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector> //para que el usuario pueda elegir los stats y cantidad de combates de los personajes

#include "personaje.h" 
#include "guerrero.h"
#include "arquero.h"
#include "mago.h"
#include "utilidades.h"


int main(){
    std::srand(time(0)); //semilla del tiempo

    char respuesta;
    std::cout << "Quieres personalizar tu personaje? Escribe 's' o 'S' para sí, cualquier otra cosa para continuar: ";
    std::cin >> respuesta;

    Guerrero guerrero1(150, 150, 25, 3, 6);
    Arquero arquero1(100,100,20,4,40,26);
    Mago mago1(90,90,30,5,50);

    if(respuesta == 's' || respuesta == 'S'){
        Guerrero guerrero1(crearGuerrero());
        Arquero arquero1(crearArquero());
        Mago mago1(crearMago());
    }

    std::cout << "\n  --- ---  ESTADO INICIAL DE LOS PERSONAJES  --- ---  " << std::endl;
    
    guerrero1.imprimir();
    arquero1.imprimir();
    mago1.imprimir();

    std::cout << "\n  --- ---  COMBATES  --- ---  " << std::endl;
        
    //pedir la cantidad de los combates
    int cantidadCombates = validarInput("\n¿Cuantos combates deseas simular? ", 1, 20); //limitando la cantidad de combates que puede haber   

    //vectores con referencias de personajes y sus nombres
    std::vector<Personaje*> personajes = {&guerrero1, &arquero1, &mago1};
    std::vector<std::string> nombres = {"Guerrero", "Arquero", "Mago"};

    //loop de combates
    for (int i = 1; i <= cantidadCombates; i++) {
        //se toma de manera aleatoria el index o posición de un personaje de los arrays arriba definidos como atacante
        int atacante = std::rand() % 3; 
        //comprobación de si sigue vivo el personaje que se va a elegir
        while (personajes[atacante]->getVida() <= 0) {
            atacante = std::rand() % 3;
        }
        //se toma de manera aleatoria el index, 0 1 ó 2, de un personaje como defensor de los vectores, pero se asegura de que el personaje no sea el mismo para atacar y defender; si son iguales repite el loop hasta que son diferentes y se sale
        //también se asegura que siga vivo
        int defensor;
        do {
            defensor = std::rand() % 3;
        } while (defensor == atacante || personajes[defensor]->getVida() <= 0);
        
        ejecutarCombate(personajes[atacante], personajes[defensor], nombres[atacante], nombres[defensor], i);
    }
    
    std::cout << "\n\n  FIN DE LOS COMBATES" << std::endl;

    std::cout << "\n  --- ---  ESTADO FINAL DE LOS PERSONAJES  --- ---  " << std::endl;
    guerrero1.imprimir();
    arquero1.imprimir();
    mago1.imprimir();
    
    return 0;
}