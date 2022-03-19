/*

Archivo: Jugador.cpp
Autor:
Huertas Cadavid Nicolas Fernando
<nicolas.huertas@correounivalle.edu.co>
Fecha Creación: 2022-03-19
Fecha Ultima Modificación: 2022-01-19
Licencia: GNU-GPL

*/

/**
Clase: Jugador
Responsabilidad: Representar al jugador y las acciones que puede realizar dentro del juego
Relaciones:
- Conoce un Tablero
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