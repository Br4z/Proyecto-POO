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

#include "../../../HEADER FILES/Lugares/EXTENDS FROM LUGAR/Barca.h"
#include <iostream>
using namespace std;

Barca::Barca(int _numPersonajes) : Lugar(_numPersonajes)
{
    nombre = "Barca";
}

Barca::~Barca()
{
}

// Retorna true si hay un robot en la barca, si no false
bool Barca::movimientoPermitido()
{
    // Var auxiliar que dira si la barca puede moverse o no
    bool auxPermiso = false;

    // Puntero auxiliar que apuntara a un Personaje
    Personaje *auxPersonaje = nullptr;

    // String auxiliar que contendra un ID de un personaje
    string auxId;

    // Se recorre cada personaje del lugar
    for (int i = 0; i < numPersonajes; i++)//i representara el indice de cada persoanje
    {
        // Se le asigna un persoanje al puntero auxiliar
        auxPersonaje = personajes[i];

        // Se verfica que auxPersonaje sea distinto de nullptr
        if (auxPersonaje != nullptr)
        {
            // Se le asigna la primera letra del ID del auxPersonaje a auxId
            auxId = auxPersonaje->getId().substr(0, 1);

            // Se verfica si el personaje es un robot
            if (auxId == "R")
            {
                //La barca puede moverse
                auxPermiso = true;
                break;
            }
        }
    }

    // Si anteroriormente no se hallo ningun robot
    if (auxPermiso == false)
    {
        cout << "El robot debe estar en la barca" << endl;
    }

    return auxPermiso;
}

// Retorna true si la barca esta llena, si no false
bool Barca::lleno()
{
    // Contador del numero de persoanjes
    int contador = 0;

    // Se recorre cada puntero(persoanje) de la barca
    for (int i = 0; i < numPersonajes; i++)//i representara el indice de cada puntero(personaje)
    {
        // Se verfica que el puntero(personaje) no apunte a nullptr
        if (personajes[i] != nullptr)
        {
            // Se aumenta el contador
            contador += 1;
        }
    }

    // Segun el caso dira si esta llena o no
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