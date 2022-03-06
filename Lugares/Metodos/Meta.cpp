/*

Archivo: Meta.cpp
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

#include "../Clases/Meta.h"
#include <iostream>
using namespace std;

Meta::Meta(int _numPersonajes) : Lugar(_numPersonajes)
{
    nombre = "Meta";
}

Meta::~Meta()
{
}