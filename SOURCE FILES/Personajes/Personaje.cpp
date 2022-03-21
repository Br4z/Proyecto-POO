/*

Archivo: Jugador.cpp
Autor:
Huertas Cadavid Nicolas Fernando
<nicolas.huertas@correounivalle.edu.co>
Fecha Creación: 2022-03-19
Fecha Ultima Modificación: 2022-01-19
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

// Le añade algún string al nombre y al ID del personaje
void Personaje::addToNombre(string strExtra)
{
    this->nombre += strExtra;
    this->ID += strExtra;
}

string Personaje::getId()
{
    return ID;
}