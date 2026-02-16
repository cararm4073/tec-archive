#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <iostream>
//no se usa namespace std

class Personaje{
    private:
        //solo definir variables usadas en personaje
        int vida;
        int salud;
        int ataque; //cuántos puntos de ataque se hace hacia otro personaje
        int nivel;

        //variables globales para el juego

    public:
        //builders y destructor
        Personaje();
        Personaje(int vida, int salud, int ataque, int nivel);
        virtual ~Personaje();
        
        //seters
        void setVida(int vida);
        void setSalud(int salud);
        void setAtaque(int ataque);
        void setNivel(int nivel);
        
        //getters
        int getVida();
        int getSalud();
        int getAtaque();
        int getNivel();

        //funciones juego
        int calcularPorcentajeSalud();
        void imprimirBarra();
        virtual void recibeAtaque(int ptosAtaque); //modificación para las clases heredadas
        virtual int calculaAtaque(Personaje& objetivo); //implementación de virtual por si hay otra, como con el guerrero, con mayor fuerza, se pueda usar
        void atacar(Personaje& objetivo);
        virtual void imprimir();
    
    };

#endif