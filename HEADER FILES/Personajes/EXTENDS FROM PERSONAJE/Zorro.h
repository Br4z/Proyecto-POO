/*

Archivo: Zorro.h
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
Clase: Zorro
Responsabilidad: Representar a un Zorro del juego y su funcionamiento
Relaciones: 
- Es un Personaje.h
*/

#pragma once
#ifndef ZORRO_H
#define ZORRO_H
#include <iostream>
#include "../Personaje.h"
using namespace std;


class Zorro : public Personaje
{

    private:

    public:
        Zorro();
        ~Zorro();
};

#else
class Zorro;
#endif