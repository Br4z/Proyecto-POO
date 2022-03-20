/*

Archivo: Orilla.cpp
Autor: 
Calderón Prieto Brandon
<bcalderonprieto@gmail.com>
Fecha Creación: 2022-01-29
Fecha Ultima Modificación: 2022-03-20
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