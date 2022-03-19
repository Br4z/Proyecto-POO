/*

Archivo: Meta.cpp
Autor: 
Calderon Prieto Brandon
<bcalderonprieto@gmail.com>
Fecha Creación: 2022-01-29
Fecha Ultima Modificación: 2022-03-19
Licencia: GNU-GPL

*/

#include "../../../HEADER FILES/Lugares/EXTENDS FROM LUGAR/Meta.h"
#include <iostream>
using namespace std;

Meta::Meta(int _numPersonajes) : Lugar(_numPersonajes)
{
    nombre = "Meta";
}

Meta::~Meta()
{
}