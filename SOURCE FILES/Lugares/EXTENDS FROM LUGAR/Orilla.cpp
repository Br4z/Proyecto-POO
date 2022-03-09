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

//Contructor de Orilla
Orilla::Orilla(int _numPersonajes) : Lugar(_numPersonajes)
{
    nombre = "Orilla";

    //Puntero auxiliar que apuntara a un personaje
    Personaje *aux;

    //Se le asigna un personaje al puntero auxiliar
    aux = new Robot();

    //Se agrega el puntero(persoanje) al indice indicado
    personajes[0] = aux;
    aux = nullptr;

    //Se repiten los pasos anteriores con cada tipo de personaje

    aux = new Zorro();
    personajes[1] = aux;
    aux = nullptr;

    aux = new Lechuga();
    personajes[2] = aux;
    aux = nullptr;

    aux = new Conejo();
    personajes[3] = aux;
    aux = nullptr;
}

Orilla::~Orilla()
{

}