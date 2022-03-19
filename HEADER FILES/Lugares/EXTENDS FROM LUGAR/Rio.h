/*

Archivo: Rio.h
Autor: 
Calderon Prieto Brandon
<bcalderonprieto@gmail.com>
Fecha Creación: 2022-01-29
Fecha Ultima Modificación: 2022-03-19
Licencia: GNU-GPL

*/

/**
Clase: Rio
Responsabilidad: Representar la orilla izquierda hacía la que se dirige la barca
Relaciones: 
- Es un Lugar
- Contiene Personajes (Conejo, Robot, Zorro y Lechuga)
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