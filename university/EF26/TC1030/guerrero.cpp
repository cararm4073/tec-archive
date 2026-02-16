#include "guerrero.h"
#include <iostream>

/*
Su nivel va del 1 al 25. SI el nivel es mayor a 15, no recibe daño adicional al recibido, pero si es menor por cada nivel, el porcentaje aumenta 2%
Nivel 14 es un 2%, nivel 13 un 4%, nivel 12 un 6% y así sucesivamente.
*/

//builder
Guerrero::Guerrero(int vida, int salud, int ataque, int nivel, int fuerza): Personaje(vida,salud,ataque,nivel){
    this -> fuerza = fuerza;
};

//validación builder
int validarInput(std::string mensaje, int min, int max);

//destructor
Guerrero::~Guerrero(){
    
};

//funciones
void Guerrero::recibeAtaque(int ptosAtaque){
    if(getNivel()<15){
        float porcentaje= 2*(15-getNivel());
        ptosAtaque = ptosAtaque + (ptosAtaque * (porcentaje / 100));
        std::cout << "El Guerrero tiene nivel bajo y recibe " << porcentaje << "% más de daño!" << std::endl;
    } else {
        
    }
    setSalud(getSalud() - ptosAtaque);

}

int Guerrero::calculaAtaque(Personaje& objetivo){
    int daño;
    daño = Personaje::calculaAtaque(objetivo) + fuerza;
    
    return daño;
};

void Guerrero::imprimir(){
    std::cout << "\nEstado del Guerrero: " << std::endl;
    Personaje::imprimir(); //usar la de la clase padre, personaje, para evitar loops raros
    std:: cout << "   Fuerza: " << fuerza << std::endl;
};