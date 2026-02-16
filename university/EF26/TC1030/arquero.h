#ifndef ARQUERO_H
#define ARQUERO_H

#include "personaje.h"

class Arquero: public Personaje{
    private:
        int precision, agilidad;
    public:
        //builder
        Arquero(int vida, int salud, int ataque, int nivel, int precision, int agilidad);
        //destuctor
        ~Arquero();

        //funciones
        void imprimir() override;
        void recibeAtaque(int ptosAtaque) override;
        int calculaAtaque(Personaje& objetivo) override; //mejora daño por la precision

};

#endif