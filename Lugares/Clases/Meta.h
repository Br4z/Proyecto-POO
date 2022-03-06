/*

Archivo: Meta.h
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
Clase: Meta
Responsabilidad: Representar la orilla derecha hacía la que se dirige la barca
Relaciones: 
- Es un Lugar.h
- Contiene Personaje.h (Conejo.h, Robot.h, Zorro.h, Lechuga.h )
- 
*/

#pragma once
#ifndef META_H
#define META_H
#include "Lugar.h"
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