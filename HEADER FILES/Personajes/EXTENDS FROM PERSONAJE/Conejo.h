/*

Archivo: Conejo.h
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
Clase: Conejo
Responsabilidad: Representar a un conejo del juego y su funcionamiento
Relaciones: 
- Es un Personaje.h
*/

#pragma once
#ifndef CONEJO_H
#define CONEJO_H
#include <iostream>
#include "../Personaje.h"
using namespace std;

class Conejo : public Personaje
{
    private:

    public:
        Conejo();
        ~Conejo();
};

#else
class Conejo;
#endif