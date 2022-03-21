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
Responsabilidad: Representar el rio en el juego
Relaciones: 
- Es un Lugar
- Conoce a  Personajes (Conejo, Robot, Zorro y Lechuga)
*/

#pragma once
#ifndef RIO_H
#define RIO_H
#include "../Lugar.h"
using namespace std;

class Rio : public Lugar
{

public:
    Rio(int _numPersonajes);
    virtual ~Rio();
    virtual bool alguienCayoAlRio();
};

#else
class Rio;
#endif