#ifndef GUERRERO_H
#define GUERRERO_H

#include "personaje.h"

class Guerrero: public Personaje{
    private:
        int fuerza; //habilidada especial
    public:
        //constructor
        Guerrero(int vida, int salud, int ataque, int nivel, int fuerza);
        //destructor
        ~Guerrero();

        //setters y getters
        void recibeAtaque(int ptosAtaque) override;
        void imprimir() override;

        //funciones
        int calculaAtaque(Personaje& objetivo) override;
        
};

#endif