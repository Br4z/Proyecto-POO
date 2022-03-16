/*

Archivo: Lechuga.h
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

Clase: Lechuga
Responsabilidad: Representar a una lechuga del juego y su funcionamiento
Relaciones: 
- Es un Personaje.h

*/

#pragma once
#ifndef LECHUGA_H
#define LECHUGA_H
#include <iostream>
#include "../Personaje.h"
using namespace std;

class Lechuga : public Personaje
{
    private:

    public:
        Lechuga();
        ~Lechuga();
};

#else
class Lechuga;
#endif