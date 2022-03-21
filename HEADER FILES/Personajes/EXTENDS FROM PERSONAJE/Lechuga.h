/*

Archivo: Lechuga.h
Autor:
Huertas Cadavid Nicolas Fernando
<nicolas.huertas@correounivalle.edu.co>
Fecha Creación: 2022-03-19
Fecha Ultima Modificación: 2022-01-19
Licencia: GNU-GPL

*/

/**

Clase: Lechuga
Responsabilidad: Representar a una lechuga del juego y su funcionamiento
Relaciones: 
- Es un Personaje

*/

#pragma once
#ifndef LECHUGA_H
#define LECHUGA_H
#include <iostream>
#include "../Personaje.h"
using namespace std;

class Lechuga : public Personaje
{


public:
    Lechuga();
    ~Lechuga();
};

#else
class Lechuga;
#endif