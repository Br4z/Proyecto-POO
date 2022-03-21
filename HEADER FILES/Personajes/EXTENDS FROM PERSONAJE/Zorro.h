/*

Archivo: Zorro.h
Autor:
Huertas Cadavid Nicolas Fernando
<nicolas.huertas@correounivalle.edu.co>
Fecha Creación: 2022-03-19
Fecha Ultima Modificación: 2022-01-19
Licencia: GNU-GPL

*/

/**
Clase: Zorro
Responsabilidad: Representar a un Zorro del juego y su funcionamiento
Relaciones: 
- Es un Personaje
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