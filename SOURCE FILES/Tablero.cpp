/*

Archivo: Tablero.cpp
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
#include "../HEADER FILES/Tablero.h"
using namespace std;

Tablero::Tablero(int numPersonajes)
{
    this->numPersonajes = numPersonajes;
    // Se crea un puntero(auxiliar) que apunta a un lugar
    Lugar *aux;

    // Se le asigna dinamicamente un objeto Orilla al puntero auxiliar
    aux = new Orilla(numPersonajes);
    // Se le asigna el puntero auxiliar a el indice 0 de la lista de punteros lugares de Tablero.h
    lugares[0] = aux;
    aux = nullptr;

    // Se le asigna dinamicamente un objeto Barca al puntero auxiliar
    aux = new Barca(numPersonajes);
    // Se le asigna el puntero auxiliar a el indice 1 de la lista de punteros lugares de Tablero.h
    lugares[1] = aux;
    aux = nullptr;

    // Se le asigna dinamicamente un objeto Rio al puntero auxiliar
    aux = new Rio(numPersonajes);
    // Se le asigna el puntero auxiliar a el indice 2 de la lista de punteros lugares de Tablero.h
    lugares[2] = aux;
    aux = nullptr;

    // Se le asigna dinamicamente un objeto Meta al puntero auxiliar
    aux = new Meta(numPersonajes);
    // Se le asigna el puntero auxiliar a el indice 3 de la lista de punteros lugares de Tablero.h
    lugares[3] = aux;
    aux = nullptr;
}

Tablero::~Tablero()
{
    // Se recorre la lista de punteros lugares
    for (int i = 0; i < 4; i++)
    {
        // Se elimina a lo que apunta cada puntero
        delete lugares[i];
        lugares[i] = nullptr;
    }
}

void Tablero::dibujarTablero()
{
    // Se recorre cada lugar de la lista de punteros lugares de Tablero.h
    for (int l = 0; l < 4; l++) // 4 por el numero de lugares
    {
        // Se imprime el nombre de cada lugar
        cout << lugares[l]->getNombre() << "\t\t|";
    }
    cout << endl;

    // Se recorre cada personaje
    for (int i = 0; i < numPersonajes; i++)//i representara el indice de cada personaje
    {
        // Se recorre cada lugar
        for (int j = 0; j < 4; j++)// j representara el indice de cada lugar
        {
            // Puntero auxiliar que apunta a un lugar j
            // Se le asigna al puntero auxiliar un lugar del tablero
            Lugar *auxLugar = lugares[j];

            // Se verifica si el puntero(personaje) apunta a nullptr
            if (auxLugar->getPersonaje(i) == nullptr)
            {
                // Simulando el agua donde esta el rio
                if(auxLugar->getNombre() == "Rio")
                {
                    cout << "~~~~~~~~~~\t|";

                } else {
                cout << "\t\t|";

                }
            }
            // Si el puntero(personaje) no apunta a nullptr
            else
            {
                // Se imprime el nombre del personaje
                cout << auxLugar->getPersonaje(i)->getNombre() << "   \t|";
            }
        }
        cout << endl;
    }
}

// Retorna el lugar(puntero) del indice que recibe
Lugar *Tablero::getLugar(int indice)//indice representara el indice de un lugar
{
    // Retorna el lugar(puntero) de la lista de punteros lugares de Tablero.h segun el indice dado
    return lugares[indice];
}

// Asigna un lugar a la lista de punteros lugares de Tablero.h en el indice dado
void Tablero::setLugar(int indice, Lugar *lugar)//indice representara el indice de un lugar y *lugar un puntero que apunta a un lugar
{
    // Se le asigna el lugar dado en el indice dado a la lista de punteros lugares de Tablero.h
    lugares[indice] = lugar;
}

// Asigna un personaje en un lugar y indice dado
void Tablero::setPersonajeEnLugar(int cualLugar, int indice, Personaje *personaje)
{
    // Añade el personaje en lugar e indice dados
    lugares[cualLugar]->addPersonaje(indice, personaje);
}

// Asigna nullptr a un puntero de la lista de punteros lugares de Tablero.h
void Tablero::removerLugar(int cualLugar)//cualLugar representara el indice de un puntero de lugares de Tablero.h
{
    // Se le asigna nullptr al puntero lugar del indice dado
    lugares[cualLugar] = nullptr;
    // cabe recalcar que el lugar al que estuviera apuntando no se elimina
}

// Agrega los IDS de cada personaje al vector idsPersonajes de Tablero.h
void Tablero::setIdsPersonajes()
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

// Agrega los nombres de cada personaje al vector nombresPersonajes de Tablero.h
void Tablero::setNombresPersonajes()
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
void Tablero::mostrarIdsPersonajes()
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


//
void Tablero::moverPersonaje(string idPersonaje)
{
    // Var auxiliar que contendra la posicion(lugar) donde se movera el personaje
    int auxPos;
    
    // Var auxiliar que dira si se ha encontrado el personaje
    bool encontrado = false;

    // Se recorre cada lugar
    for (int i = 0; i < 4; i++)//i representara el indice de cada lugar
    {
        // Se recorre cada personaje
        for (int j = 0; j < lugares[i]->getNumPersonajes(); j++)//j representara el indice de cada personaje
        {
            // Se verfica que el puntero personaje no apunte a nullptr
            if (lugares[i]->getPersonaje(j) != nullptr)
            {
                //Se verifica que el ID del personaje sea igual al recibido como parametro
                if (lugares[i]->getPersonaje(j)->getId() == idPersonaje)
                {
                    // Se crea un puntero personaje auxiliar que apunta al personaje encontrado
                    Personaje *aux = lugares[i]->getPersonaje(j);

                    // Segun el indice(lugar) donde fue encontrado se definira el lugar donde se movera
                    if (i == 0 || i == 2)
                    {
                        // Se le asigna a auxPos el indice(lugar) donde fue encontrado y se le suma 1
                        auxPos = i + 1;
                    }
                    else
                    {
                        // Se le asigna a auxPos el indice(lugar) donde fue encontrado y se le resta 1
                        auxPos = i - 1;
                    }

                    // Se verifica que el lugar donde se movera el personaje no este lleno
                    if (lugares[auxPos]->lleno() == false)
                    {
                        // Se pone el personaje en el lugar dado, y en el mismo indice donde se encontro
                        lugares[auxPos]->addPersonaje(j, aux);//aux es el personaje

                        // Se remueve el personaje del lugar en el que estaba
                        lugares[i]->removerPersonaje(j);
                    }
                    // Se le asigna true a la var encontrado
                    encontrado = true;
                    // Se termina el segundo for
                    break;
                }
            }
        }
        // Se verifica que se haya encontrado al personaje
        if (encontrado == true)
        {
            // Se termina el for principal
            break;
        }
    }
}