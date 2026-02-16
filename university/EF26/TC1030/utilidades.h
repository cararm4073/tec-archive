#ifndef UTILIDADES_H
#define UTILIDADES_H

//para el manejo de la creación y validación de personajes
#include "personaje.h"
#include "guerrero.h"
#include "arquero.h"
#include "mago.h"
#include <string>

//validación de personajes
int validarInput(std::string mensaje, int min, int max);

//creación de personajes
Guerrero crearGuerrero();
Arquero crearArquero();
Mago crearMago();

//ejecutar combates
void ejecutarCombate(Personaje* atacante, Personaje* defensor, std::string nombreAtacante, std::string nombreDefensor, int numCombate);
#endif