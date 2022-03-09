/*

Archivo: Orilla_I.h
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
Clase: Orilla_I
Responsabilidad: Representar la orilla izquierda hacía la que se dirige la barca
Relaciones: 
- Es un Lugar.h
- Contiene Personaje.h (Conejo.h, Robot.h, Zorro.h, Lechuga.h )
- 
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