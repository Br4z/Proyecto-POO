/*

Archivo: Menu.h
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
Clase: Menu
Responsabilidad: Representar el funcionamiento basico del menu del juego
Relaciones:
- Contiene Lugar.h
- Conoce Jugador.h
*/

#pragma once
#ifndef MENU_H
#define MENU_H
#include "Lugares/Lugar.h"
#include "Lugares/EXTENDS FROM LUGAR/Orilla.h"
#include "Lugares/EXTENDS FROM LUGAR/Barca.h"
#include "Lugares/EXTENDS FROM LUGAR/Meta.h"
#include "Lugares/EXTENDS FROM LUGAR/Rio.h"
#include <vector>

using namespace std;

class Menu
{
    private:
        Lugar *lugares[4]; // Tablero o matriz
        int numPersonajes;
        vector<string> idsPersonajes;
        vector<string> nombresPersonajes;

    public:
        Menu();
        ~Menu();
        void dibujarTablero();
        Lugar *getLugar(int indice);
        void setLugar(int indice, Lugar *lugar);
        void removerLugar(int indice);
        void dibujarLugar(int indice);
        void setNumPersonajes(int _numPersonajes);
        void setPersonajeEnLugar(int cualLugar, int indice, Personaje *personaje);
        void setIdsPersonajes();
        void setNombresPersonajes();
        void mostrarIdsPersonajes();
};

#else
class Menu;
#endif