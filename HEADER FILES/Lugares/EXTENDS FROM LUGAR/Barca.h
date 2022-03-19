/*

Archivo: Barca.h
Autor: 
Calderon Prieto Brandon
<bcalderonprieto@gmail.com>
Fecha Creación: 2022-01-29
Fecha Ultima Modificación: 2022-03-19
Licencia: GNU-GPL

*/

/**
Clase: Barca
Responsabilidad: Representar el funcionamiento de la barca en el juego
Relaciones: 
- Es un Lugar
- Contiene Personajes (Zorro, Conejo, Lechuga y Robot)
*/

#pragma once
#ifndef BARCA_H
#define BARCA_H
#include <iostream>
#include "../Lugar.h"
using namespace std;

class Barca : public Lugar
{
    private:

    public:
        Barca(int _numPersonajes);
        virtual ~Barca();
        virtual bool movimientoPermitido();
        virtual bool lleno();
};

#else
class Barca;
#endif