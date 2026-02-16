#include "utilidades.h"
#include <iostream>

//función auxiliar para creación de personajes desde input
int validarInput(std::string mensaje, int min, int max) {
//               mensaje a mostrar    rango de valores mínimos y máximos
    int valor;
    
    std::cout << mensaje;
    while (true){
        try{
            if (!(std::cin >> valor)){ //si hay un error en cin
                throw "Ingresa solo números!";
            }
            if(valor < min || valor > max) {
                throw valor;
            }

            return valor;
        }
        catch (const char* msg) {
            std::cout << "Error: " << msg << std::endl;
            std::cin.clear(); 
            std::cin.ignore(10000, '\n');
            std::cout << "Intenta de nuevo.\n";
        }
        catch (int val) {
            std::cout << "\nError: " << val << " está fuera del rango de mínimos y máximos: (" << min << "-" << max << ")\n" << std::endl;
        }
    }
}

//creación de personajes por el usuario
/*
para cada parte, como la variable se guarda llamando la funcion de verificación de input, se puede mostrar el mensaje de que no está 
dentro del rango un valor ingresado o qube no es un número al momento de crear un personaje
la estructura general se mantiene para cada personaje, junto a sus habilidades
*/
Guerrero crearGuerrero() {
    std::cout << "\n   --- CREAR GUERRERO ---" << std::endl;
    
    int salud = validarInput(" Salud máxima (75 - 300): ", 75, 300);
    int vida = salud; //inicial vs durante ataque, se matienen igual paar el resto de personajes
    int ataque = validarInput(" Ataque (10-50): ", 10, 50);
    int nivel = validarInput(" Nivel (1-25): ", 1, 25);
    int fuerza = validarInput(" Fuerza (1-10): ", 1, 10);
    
    return Guerrero(vida, salud, ataque, nivel, fuerza); //regresa el objeto creado, igual con el resto de los personajes
}

Arquero crearArquero() {
    std::cout << "\n   --- CREAR ARQUERO ---" << std::endl;
    
    int salud = validarInput(" Salud máxima (40-210): ", 40, 210);
    int vida = salud;
    int ataque = validarInput(" Ataque (20-40): ", 20, 40);
    int nivel = validarInput(" Nivel (1-25): ", 1, 25);
    int precision = validarInput(" Nivel de presición (20-55): ", 20, 55); //para hacer más daño
    int agilidad = validarInput(" Nivel de agilidad (0-50): ", 0, 50); //esquivar ataque, con suerte...
    
    return Arquero(vida, salud, ataque, nivel, precision, agilidad);
}

Mago crearMago() {
    std::cout << "\n   --- CREAR MAGO ---" << std::endl;
    
    int salud = validarInput(" Salud maxima (30-215): ", 30, 215);
    int vida = salud;
    int ataque = validarInput(" Ataque (25-50): ", 25, 50);
    int nivel = validarInput(" Nivel (1-25): ", 1, 25);
    int energia = validarInput(" Energía (33-120): ", 33, 120); //como no se puede ganar (aún energia), se permite crear al personaje con mayor cantidad desde un inicio
    
    return Mago(vida, salud, ataque, nivel, energia);
}

//función para ejecutar combates y verificar si ha muerto un personaje
void ejecutarCombate(Personaje* atacante, Personaje* defensor, std::string nombreAtacante, std::string nombreDefensor, int numCombate) {
    //               personaje atacante   personaje defensor   guardar nombre de los personajes                        contador del combate
    std::cout << "\n  COMBATE " << numCombate << std::endl;
    std::cout << nombreAtacante << " vs " << nombreDefensor << ":" << std::endl;
    atacante->atacar(*defensor);
    std::cout << "\n";
    defensor->imprimir();
    
    //comprobación de si muere un personaje durante el combate
    if (defensor->getVida() <= 0) {
        std::cout << "\n*** " << nombreDefensor << " HA MUERTO ***\n";
    }
};