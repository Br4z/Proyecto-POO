/*

Archivo: Personaje.cpp
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

#include "../../HEADER FILES/Personajes/Personaje.h"
#include <iostream>
using namespace std;

Personaje::Personaje()
{
}

Personaje::~Personaje()
{
}

string Personaje::getNombre()
{
    return nombre;
}

// Le añade algun string al nombre y al ID del personaje
void Personaje::addToNombre(string strExtra)
{
    this->nombre += strExtra;
    this->ID += strExtra;
}

string Personaje::getId()
{
    return ID;
}