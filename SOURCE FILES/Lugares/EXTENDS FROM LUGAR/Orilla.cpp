/*

Archivo: Orilla.cpp
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

#include "../../../HEADER FILES/Lugares/EXTENDS FROM LUGAR/Orilla.h"
#include <iostream>
using namespace std;

// Contructor de Orilla
Orilla::Orilla(int _numPersonajes) : Lugar(_numPersonajes)
{
    nombre = "Orilla";

    // Se agregan los personajes por defecto
    personajes[0] = new Robot();
    personajes[1] = new Zorro();
    personajes[2] = new Lechuga();
    personajes[3] = new Conejo();
}

Orilla::~Orilla()
{

}