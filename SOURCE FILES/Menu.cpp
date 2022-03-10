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

// Establece el numero de personajes y define el tamaño de los lugares
void Menu::setNumPersonajes(int _numPersonajes)
{
    // Se le asigna el numero de personajes recibido al atributo numPersonajes de Menu.h
    numPersonajes = _numPersonajes;

    // Se crea un puntero(auxiliar) que apunta a un lugar
    Lugar *aux;

    // Se le asigna dinamicamente un objeto Orilla al puntero auxiliar
    aux = new Orilla(numPersonajes);
    // Se le asigna el puntero auxiliar a el indice 0 de la lista de punteros lugares de Menu.h
    lugares[0] = aux;
    aux = nullptr;

    // Se le asigna dinamicamente un objeto Barca al puntero auxiliar
    aux = new Barca(numPersonajes);
    // Se le asigna el puntero auxiliar a el indice 1 de la lista de punteros lugares de Menu.h
    lugares[1] = aux;
    aux = nullptr;

    // Se le asigna dinamicamente un objeto Rio al puntero auxiliar
    aux = new Rio(numPersonajes);
    // Se le asigna el puntero auxiliar a el indice 2 de la lista de punteros lugares de Menu.h
    lugares[2] = aux;
    aux = nullptr;

    // Se le asigna dinamicamente un objeto Meta al puntero auxiliar
    aux = new Meta(numPersonajes);
    // Se le asigna el puntero auxiliar a el indice 3 de la lista de punteros lugares de Menu.h
    lugares[3] = aux;
    aux = nullptr;
}

Menu::~Menu()
{
    // Se recorre la lista de punteros lugares
    for (int i = 0; i < 4; i++)
    {
        // Se elimina a lo que apunta cada puntero
        delete lugares[i];
        lugares[i] = nullptr;
    }
}

void Menu::dibujarTablero()
{
    // Se recorre cada lugar de la lista de punteros lugares de Menu.h
    for (int l = 0; l < 4; l++) // 4 por el numero de lugares
    {
        // Se imprime el nombre de cada lugar
        cout << "| " << lugares[l]->getNombre() << "\t\t";
    }
    cout << endl;

    // Se recorre cada personaje
    for (int i = 0; i < numPersonajes; i++)//i representara el indice de cada personaje
    {
        // Se recorre cada lugar
        for (int j = 0; j < 4; j++)// j representara el indice de cada lugar
        {
            // Puntero auxiliar que apunta a un lugar
            Lugar *auxLugar = nullptr;

            // Se verifica si el puntero(personaje) apunta a nullptr
            if (lugares[j]->getPersonaje(i) == nullptr)
            {
                // Se le asigna al puntero auxiliar un lugar del tablero
                auxLugar = lugares[j];
                // Simulando el agua donde esta el rio
                if(auxLugar->getNombre() == "Rio")
                {
                    cout << "~~~~~~\t";

                } else {
                cout << "\t\t";

                }
            }
            // Si el puntero(personaje) no apunta a nullptr
            else
            {
                // Se imprime el nombre del personaje
                cout << "| " << lugares[j]->getPersonaje(i)->getNombre() << "\t|";
            }
        }
        cout << endl;
    }
}

// Retorna el lugar(puntero) del indice que recibe
Lugar *Menu::getLugar(int indice)//indice representara el indice de un lugar
{
    // Retorna el lugar(puntero) de la lista de punteros lugares de Menu.h segun el indice dado
    return lugares[indice];
}

// Asigna un lugar a la lista de punteros lugares de Menu.h en el indice dado
void Menu::setLugar(int indice, Lugar *lugar)//indice representara el indice de un lugar y *lugar un puntero que apunta a un lugar
{
    // Se le asigna el lugar dado en el indice dado a la lista de punteros lugares de Menu.h
    lugares[indice] = lugar;
}

// Asigna un personaje en un lugar y indice dado
void Menu::setPersonajeEnLugar(int cualLugar, int indice, Personaje *personaje)
{
    // Añade el personaje en lugar e indice dados
    lugares[cualLugar]->addPersonaje(indice, personaje);
}

// Asigna nullptr a un puntero de la lista de punteros lugares de Menu.h
void Menu::removerLugar(int cualLugar)//cualLugar representara el indice de un puntero de lugares de Menu.h
{
    // Se le asigna nullptr al puntero lugar del indice dado
    lugares[cualLugar] = nullptr;
    // cabe recalcar que el lugar al que estuviera apuntando no se elimina
}

// Agrega los IDS de cada personaje al vector idsPersonajes de Menu.h
void Menu::setIdsPersonajes()
{
    // Var aux que tiene como valor el numero de personajes
    int aux = lugares[0]->getNumPersonajes(); // El numero de personajes siempre es igual a los que aparacen en la orilla

    // Se recorre cada personaje de la orilla
    for (int i = 0; i < aux; i++)//i representara el indice de cada personaje
    {
        // Se agrega el ID de cada personaje de la orilla, por ello "lugares[0]" no cambia
        idsPersonajes.push_back(lugares[0]->getPersonaje(i)->getId());
    }
}

// Agrega los nombres de cada personaje al vector nombresPersonajes de Menu.h
void Menu::setNombresPersonajes()
{
    // Var aux que tiene como valor el numero de personajes
    int aux = lugares[0]->getNumPersonajes();

    // Se recorre cada personaje de la orilla
    for (int i = 0; i < aux; i++)//i representara el indice de cada personaje
    {
        // Se agrega el nombre de cada personaje de la orilla, por ello "lugares[0]" no cambia
        nombresPersonajes.push_back(lugares[0]->getPersonaje(i)->getNombre());
    }
}

// Muestra los IDS de cada personaje
void Menu::mostrarIdsPersonajes()
{
    // Var aux que contiene el numero de IDS
    int aux = idsPersonajes.size();
    cout << "Personajes\tID's" << endl;
    cout << "---------\t---" << endl;

    // Se recorre la lista de nombresPersonajes y idsPersonajes
    for (int i = 0; i < aux; i++)//i representara el indice de cada ID y nombre
    {
        cout << nombresPersonajes[i] << "    \t" << idsPersonajes[i] << endl;
    }
}