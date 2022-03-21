/*

Archivo: Meta.h
Autor: 
Calderón Prieto Brandon
<bcalderonprieto@gmail.com>
Fecha Creación: 2022-01-29
Fecha Ultima Modificación: 2022-03-20
Licencia: GNU-GPL

*/

/**
Clase: Meta
Responsabilidad: Representar la meta(orilla izquierda) donde tienen que llegar los personajes
Relaciones: 
- Es un Lugar
- Conoce a  Personajes (Conejo, Robot, Zorro, Lechuga)

*/

#pragma once
#ifndef META_H
#define META_H
#include "../Lugar.h"
using namespace std;

class Meta : public Lugar
{
    private:

    public:
        Meta(int _numPersonajes);
        ~Meta();
};

#else
class Meta;
#endif