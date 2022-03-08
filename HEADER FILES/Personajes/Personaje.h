
/*

Archivo: Personaje.h
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
Clase: Personaje
Responsabilidad: Representar a un personaje del juego y su funcionamiento
Relaciones: Ninguna
*/

#pragma once
#ifndef PERSONAJE_H
#define PERSONAJE_H
#include <iostream>
#include <string>
using namespace std;


class Personaje
{
    protected:
        string nombre;
        string ID;
    public:
        Personaje();
        ~Personaje();
        string getNombre();
        void addToNombre(string nombre);
        string getId();
};

#else
class Personaje;
#endif