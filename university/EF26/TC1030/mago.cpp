#include "mago.h"

/*
El mago tiene por habilidad la posibilidad de que si tiene por arriba de 20 puntos de energía, puede reducir a la mitad el daño recibido por otro personaje
Tiene un cost de 1 de energia
*/

//constructor
Mago::Mago(int vida, int salud, int ataque, int nivel, int energia): Personaje(vida, salud, ataque, nivel){
    this -> energia = energia;
}

//validación de constructor personajes
int validarInput(std::string mensaje, int min, int max);

//destructor
Mago::~Mago(){

};

//funciones
void Mago::recibeAtaque(int ptosAtaque){
    if(energia > 20){
        ptosAtaque = ptosAtaque /2;     //escudo: reduce a la mitad el daño recibido
        energia = energia -1;           //costo por uso de escudo: uno de energia
        std::cout << "El Mago usa su escudo de energía y reduce el daño a la mitad! Pero se le quita uno de energía." << std::endl;
    }
    setSalud(getSalud() - ptosAtaque);  //aplicar daño
};

int Mago::calculaAtaque(Personaje& objetivo){
    int daño;
    daño=Personaje::calculaAtaque(objetivo);
    if(energia > 5){ //aqui siempre se hace el doble de daño si la energia esta por arriba, más adelante lo cambiaré a que sea random dentro de un rango
        daño = daño*2;
        energia = energia-5;
    }
    return daño;
};

void Mago::imprimir(){
    std::cout << "\nEstado del Mago: " << std::endl;
    Personaje::imprimir();
    std::cout << "   Cantidad de energía: " << energia << std::endl;
};