/*

Archivo: Barca.cpp
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

#include "../Clases/Barca.h"
#include <iostream>
using namespace std;

Barca::Barca(int _numPersonajes) : Lugar(_numPersonajes)
{
    nombre = "Barca";
}

Barca::~Barca()
{
}

bool Barca::movimientoPermitido()
{
    bool auxPermiso = false;
    Personaje *auxPersonaje = nullptr;
    string auxId;
    for (int i = 0; i < numPersonajes; i++)
    {
        auxPersonaje = personajes[i];
        if (auxPersonaje != nullptr)
        {
            auxId = auxPersonaje->getId().substr(0, 1);
            if (auxId == "R")
            {
                auxPermiso = true;
                break;
            }
        }
    }
    if (auxPermiso == false)
    {
        cout << "El robot debe estar en la barca" << endl;
    }
    return auxPermiso;
}

bool Barca::lleno()
{
    int contador = 0;
    for (int i = 0; i < numPersonajes; i++)
    {
        if (personajes[i] != nullptr)
        {
            contador += 1;
        }
    }
    if (contador >= 2)
    {
        cout << "La barca esta llena" << endl;
        return true;
    }
    else
    {
        return false;
    }
}