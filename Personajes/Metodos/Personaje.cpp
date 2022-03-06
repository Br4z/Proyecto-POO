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

#include "../Clases/Personaje.h"
#include <iostream>
using namespace std;

Personaje::Personaje()
{
    nombre = "NoName";
}

Personaje::~Personaje()
{
}

string Personaje::getNombre()
{
    return nombre;
}

void Personaje::addToNombre(string _nombre)
{
    nombre += _nombre;
    id += _nombre;
}

string Personaje::getId()
{
    return id;
}