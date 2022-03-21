/*

Archivo: Rio.cpp
Autor: 
Calderón Prieto Brandon
<bcalderonprieto@gmail.com>
Fecha Creación: 2022-01-29
Fecha Ultima Modificación: 2022-03-20
Licencia: GNU-GPL

*/

#include "../../../HEADER FILES/Lugares/EXTENDS FROM LUGAR/Rio.h"
#include <iostream>
using namespace std;

Rio::Rio(int _numPersonajes) : Lugar(_numPersonajes)
{
    nombre = " Rio";
}

Rio::~Rio()
{

}

// Retorna true si hay algún personaje en el rio, si no false
bool Rio::alguienCayoAlRio()
{
    // Var auxiliar
    bool alguienCayoAlRio = false;

    // Se recorre cada puntero(personaje) del rio
    for(int i = 0; i < numPersonajes; i++)//i representara el indice de cada personaje
    {
        // Se verifica si el puntero(persoanje) es diferente de nullptr, es decir, si hay un persoanje
        if(personajes[i] != nullptr)
        {
            cout << personajes[i]->getNombre() << " cayo al rio" << endl;
            alguienCayoAlRio = true;
            break;
        }
    }
    return alguienCayoAlRio;
}