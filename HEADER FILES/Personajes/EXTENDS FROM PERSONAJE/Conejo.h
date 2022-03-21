/*

Archivo: Conejo.h
Autor:
Huertas Cadavid Nicolas Fernando
<nicolas.huertas@correounivalle.edu.co>
Fecha Creación: 2022-03-19
Fecha Ultima Modificación: 2022-01-19
Licencia: GNU-GPL

*/

/**
Clase: Conejo
Responsabilidad: Representar a un conejo del juego y su funcionamiento
Relaciones: 
- Es un Personaje
*/

#pragma once
#ifndef CONEJO_H
#define CONEJO_H
#include <iostream>
#include "../Personaje.h"
using namespace std;

class Conejo : public Personaje
{


public:
    Conejo();
    ~Conejo();
};

#else
class Conejo;
#endif