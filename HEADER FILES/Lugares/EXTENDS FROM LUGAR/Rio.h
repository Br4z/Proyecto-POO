/*

Archivo: Rio.h
Autor: 
Getial Getial Juan Sebastian
<getial.juan@correounivalle.edu.co>
Calderon Prieto Brandon
<bcalderonprieto@gmail.com>
Huertas Cadavid Nicolas Fernando
<nicolas.huertas@correounivalle.edu.co>
Fecha Creacion: 2022-02-19
Fecha Ultima Modificacion: 2022-02-19
Licencia: GNU-GPL

*/

/**
Clase: Rio
Responsabilidad: Representar la orilla izquierda hacía la que se dirige la barca
Relaciones: 
- Es un Lugar.h
- Contiene Personaje.h (Conejo.h, Robot.h, Zorro.h, Lechuga.h )
*/

#pragma once
#ifndef RIO_H
#define RIO_H
#include "../Lugar.h"
using namespace std;

class Rio : public Lugar
{
    private:

    public:
        Rio(int _numPersonajes);
        virtual ~Rio();
        virtual bool alguienCayoAlRio();
};

#else
class Rio;
#endif