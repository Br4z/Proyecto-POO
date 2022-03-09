/*

Archivo: Menu.cpp
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

#include <iostream>
#include "../HEADER FILES/Menu.h"
using namespace std;

Menu::Menu()
{
    
}

void Menu::setNumPersonajes(int _numPersonajes)
{
    numPersonajes = _numPersonajes;

    Lugar *aux;

    aux = new Orilla(numPersonajes);
    lugares[0] = aux;
    aux = nullptr;

    aux = new Barca(numPersonajes);
    lugares[1] = aux;
    aux = nullptr;

    aux = new Rio(numPersonajes);
    lugares[2] = aux;
    aux = nullptr;

    aux = new Meta(numPersonajes);
    lugares[3] = aux;
    aux = nullptr;
}

Menu::~Menu()
{
    for (int i = 0; i < 4; i++)
    {
        delete lugares[i];
        lugares[i] = nullptr;
    }
}

void Menu::dibujarTablero()
{
    for (int l = 0; l < 4; l++) // 4 por el numero de lugares
    {
        cout << lugares[l]->getNombre() << "\t\t";
    }
    cout << endl;
    for (int i = 0; i < numPersonajes; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (lugares[j]->getPersonaje(i) == nullptr)
            {
                cout << ""
                     << "\t\t";
            }
            else
            {
                cout << lugares[j]->getPersonaje(i)->getNombre() << "\t\t";
            }
        }
        cout << endl;
    }
}

Lugar *Menu::getLugar(int indice)
{
    return lugares[indice];
}

void Menu::setLugar(int indice, Lugar *lugar)
{

    lugares[indice] = lugar;
}

void Menu::setPersonajeEnLugar(int cualLugar, int indice, Personaje *personaje)
{
    lugares[cualLugar]->addPersonaje(indice, personaje);
}

void Menu::removerLugar(int indice)
{
    lugares[indice] = nullptr;
}

void Menu::setIdsPersonajes()
{
    int aux = lugares[0]->getNumPersonajes(); // El numero de personajes siempre es igual a los que aparacen en la orilla
    for (int i = 0; i < aux; i++)
    {
        idsPersonajes.push_back(lugares[0]->getPersonaje(i)->getId());
    }
}

void Menu::setNombresPersonajes()
{
    int aux = lugares[0]->getNumPersonajes();
    for (int i = 0; i < aux; i++)
    {
        nombresPersonajes.push_back(lugares[0]->getPersonaje(i)->getNombre());
    }
}


void Menu::mostrarIdsPersonajes()
{
    int aux = idsPersonajes.size();
    cout << "Personaje\tID" << endl;
    cout << "---------\t--" << endl;
    for (int i = 0; i < aux; i++)
    {
        cout << nombresPersonajes[i] << "    \t" << idsPersonajes[i] << endl;
    }
}