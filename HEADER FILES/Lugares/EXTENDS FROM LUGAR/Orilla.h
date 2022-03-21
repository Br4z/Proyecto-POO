/*

Archivo: Orilla.h
Autor: 
Calderón Prieto Brandon
<bcalderonprieto@gmail.com>
Fecha Creación: 2022-01-29
Fecha Ultima Modificación: 2022-03-19
Licencia: GNU-GPL

*/

/**
Clase: Meta
Responsabilidad: Representar la orilla (derecha) donde inicialmente aparecen los personajes
Relaciones: 
- Es un Lugar
- Conoce a  Personajes (Conejo, Robot, Zorro y Lechuga)

*/

#pragma once
#ifndef ORILLA_H
#define ORILLA_H
#include "../Lugar.h"
using namespace std;

class Orilla : public Lugar
{
    private:

    public:
        Orilla(int _numPersonajes);
        ~Orilla();
};

#else
class Orilla_I;
#endif