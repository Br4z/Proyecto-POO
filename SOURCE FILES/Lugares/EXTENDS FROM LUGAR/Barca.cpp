/*

Archivo: Barca.cpp
Autor: 
Calderon Prieto Brandon
<bcalderonprieto@gmail.com>
Fecha Creación: 2022-01-29
Fecha Ultima Modificación: 2022-03-19
Licencia: GNU-GPL

*/
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
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
    // Var auxiliar que dirá si la barca puede moverse o no
    bool auxPermiso = false;

    // Puntero auxiliar que apuntara a un Personaje
    Personaje *auxPersonaje = nullptr;

    // String auxiliar que contendrá un ID de un personaje
    string auxId;

    // Se recorre cada personaje del lugar
    for (int i = 0; i < numPersonajes; i++)//i representara el indice de cada persoanje
    {
        // Se le asigna un persoanje al puntero auxiliar
        auxPersonaje = personajes[i];

        // Se verifica que auxPersonaje sea distinto de nullptr
        if (auxPersonaje != nullptr)
        {
            // Se le asigna la primera letra del ID del auxPersonaje a auxId
            auxId = auxPersonaje->getId().substr(0, 1);

            // Se verifica si el personaje es un robot
            if (auxId == "R")
            {
                //La barca puede moverse
                auxPermiso = true;
                break;
            }
        }
    }

    // Si anteriormente no se hallo ningún robot
    if (auxPermiso == false)
    {
        cout << "El robot debe estar en la barca" << endl;
        Sleep(1000);
    }

    return auxPermiso;
}

// Retorna true si la barca esta llena, si no false
bool Barca::lleno()
{
    // Contador del numero de personajes
    int contador = 0;

    // Se recorre cada puntero(persoanje) de la barca
    for (int i = 0; i < numPersonajes; i++)//i representara el indice de cada puntero(personaje)
    {
        // Se verifica que el puntero(personaje) no apunte a nullptr
        if (personajes[i] != nullptr)
        {
            // Se aumenta el contador
            contador += 1;
        }
    }

    // Según el caso dirá si esta llena o no
    if (contador >= 2)
    {
        cout << "La barca esta llena" << endl;
        Sleep(1000);
        return true;
    }
    else
    {
        return false;
    }
}