/*

Archivo: Jugador.h
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
Clase: Jugador
Responsabilidad: Representar al jugador y las acciones que puede realizar
Relaciones:
- Conoce un Tablero.h
*/

#pragma once
#ifndef JUGADOR_H
#define JUGADOR_H
#include <iostream>
#include "Tablero.h"
using namespace std;

class Jugador
{
    private:
        Tablero *tablero;
        bool winOrLoser;

    public:
        Jugador();
        ~Jugador();
        void setPersonajes();
        void verTablero();
        void moverPersonaje(string idPersonaje);
        void moverBarca();
        bool estadoDelJuego();
        void verIdsPersonajes();
        bool getWinOrLoser();
};

#else
class Jugador;
#endif