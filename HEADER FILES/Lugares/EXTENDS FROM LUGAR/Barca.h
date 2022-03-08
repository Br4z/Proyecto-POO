/*

Archivo: Barca.h
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
Clase: Barca
Responsabilidad: Representar el funcionamiento de la barca del juego
Relaciones: 
- Es un Lugar.h
- Contiene Personaje.h (Zorro.h, Conejo.h, Lechuga.h, Robot.h)
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
        ~Barca();
        virtual bool movimientoPermitido();
        virtual bool lleno();
};

#else
class Barca;
#endif