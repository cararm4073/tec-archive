#include "arquero.h"
#include <iostream>

/*
El arquero puede tener la suerte de esquivar totalmente un ataque si su agilidad es mayor a 25 en el momento del ataque
También tiene precisión, la cual varía en cada ataque para hacer más daño al enemigo
*/

//builder
Arquero::Arquero(int vida, int salud, int ataque, int nivel, int precision, int agilidad): Personaje(vida, salud, ataque, nivel){
    this -> precision = precision;
    this -> agilidad = agilidad;
    //verificación de agilidad
    if (agilidad > 50){
        std::cout << "El máximo de agilidad que puede tener es 50, estableciendo en 25" << std::endl;
        this -> agilidad=25;
    } else if (agilidad < 0){
        std::cout << "La agilidad no puede ser menor a 0, estableciendo en 25" << std::endl;
        this -> agilidad=25;
    }
};

//validación builder
int validarInput(std::string mensaje, int min, int max);

//destructor
Arquero::~Arquero(){
    
};

//Funciones
void Arquero::recibeAtaque(int ptosAtaque){
    if (agilidad > 25){
        int suerte = rand() %2;
        if (suerte == 1){
            std::cout << "El arquero esquiva el ataque! No recibe nada de ataque." << std::endl;
            ptosAtaque = 0;
        } else{
            std::cout << "El arquero no pudo esquivar el ataque" << std::endl;
        }
    }
    setSalud(getSalud() - ptosAtaque);
}

int Arquero::calculaAtaque(Personaje& objetivo){
    int daño;
    daño = Personaje::calculaAtaque(objetivo); // se cambió suerte por agilidad para hacer más lógica
    if(agilidad < precision){
        daño = daño*2;
    }
    return daño;
};

void Arquero::imprimir(){
    std::cout << "\nEstado del Arquero: " << std::endl;
    Personaje::imprimir();
    std::cout << "   Precisión para golpe crítico: " << precision << std::endl;
    std::cout << "   Agilidad para esquivar ataques: " << agilidad << std::endl;
};