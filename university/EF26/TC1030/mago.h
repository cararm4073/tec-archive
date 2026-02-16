#ifndef MAGO_H
#define MAGO_H

#include "personaje.h"

class Mago: public Personaje{
    private:
        int energia;
    public:
        //constructor
        Mago(int vida, int salud, int ataque, int nivel, int energia);
        //destructor
        ~Mago();

        //fuciones
        void imprimir() override;
        int calculaAtaque(Personaje& objetivo) override; //mejora daño por la energia
        void recibeAtaque(int ptosAtaque) override;

};
#endif