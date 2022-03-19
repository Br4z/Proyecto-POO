/*

Archivo: Tablero.h
Autor:
Getial Getial Juan Sebastian
<getial.juan@correounivalle.edu.co>
Calderon Prieto Brandon
<bcalderonprieto@gmail.com>
Huertas Cadavid Nicolas Fernando
<nicolas.huertas@correounivalle.edu.co>
Fecha Creacion: 2022-01-29
Fecha Ultima Modificacion: 2022-01-29
Licencia: GNU-GPL

*/

/**
Clase: Tablero
Responsabilidad: Representar el funcionamiento basico del Tablero del juego
Relaciones:
- Contiene Lugar.h
*/

#pragma once
#ifndef TABLERO_H
#define TABLERO_H
#include "Lugares/Lugar.h"
#include "Lugares/EXTENDS FROM LUGAR/Orilla.h"
#include "Lugares/EXTENDS FROM LUGAR/Barca.h"
#include "Lugares/EXTENDS FROM LUGAR/Meta.h"
#include "Lugares/EXTENDS FROM LUGAR/Rio.h"
#include <vector>

using namespace std;

class Tablero
{
    private:
        Lugar *lugares[4]; // Tablero o matriz
        vector<string> idsPersonajes;
        vector<string> nombresPersonajes;

    public:
        Tablero(int numPersonajes);
        ~Tablero();
        void dibujarTablero();
        void setPersonajeEnLugar(int cualLugar, int indice, Personaje *personaje);
        void setIdsPersonajes();
        void setNombresPersonajes();
        void mostrarIdsPersonajes();
        void moverPersonaje(string idPersonaje);
        void moverBarca();
        string estadoDelJuego();
};

#else
class Tablero;
#endif