/*

Archivo: Lugar.cpp
Autor: 
Calderon Prieto Brandon
<bcalderonprieto@gmail.com>
Fecha Creación: 2022-01-29
Fecha Ultima Modificación: 2022-03-19
Licencia: GNU-GPL

*/

#include "../../HEADER FILES/Lugares/Lugar.h"
#include <iostream>
using namespace std;

// Constructor de Lugar
Lugar::Lugar(int _numPersonajes)
{
    // Se establece cuantos personajes tendrá la lista de punteros(personajes)
    personajes = new Personaje*[_numPersonajes];

    // Se establece el atributo numPersonajes
    numPersonajes = _numPersonajes;

    // Se recorre cada personaje de la lista de punteros(personajes)
    for(int i = 0; i < numPersonajes; i++)//i representara el indice de cada personaje
    {
        //Se le asigna nullptr a cada puntero
        personajes[i] = nullptr;
    }
}

Lugar::~Lugar()
{
    for(int i = 0; i < numPersonajes; i++)
    {
        delete personajes[i];
        personajes[i] = nullptr;
    }
    delete personajes;
}


int Lugar::getNumPersonajes()
{
    return numPersonajes;
}

// Añade un personaje a la lista de punteros(personajes)
void Lugar::addPersonaje(int indice, Personaje* personaje)//indice sera donde se añadirá el personaje
{
    // Se añade el personaje dado en el indice dado
    personajes[indice] = personaje;
}

// Retorna el puntero(personaje) del indice dado
Personaje* Lugar::getPersonaje(int indice)//indice sera donde se encuentra el personaje a retornar
{
    return personajes[indice];
}


string Lugar::getNombre()
{
    return nombre;
}

// Remueve el personaje del indice dado
void Lugar::removerPersonaje(int indice)
{
    // Se le asigna nullptr al puntero del indice correspondiente
    personajes[indice] = nullptr;
    // Cabe recalcar que no elimina el personaje al que estuviera apuntando
}

// Retorna true si alguien fue comido, si no false
bool Lugar::alguienFueComido()
{
    // Var auxiliar que dice si alguien fue comido
    bool alguienFueComido = true;

    // String auxiliar que contendrá el ID de un persoanje
    string aux;

    // Contadores de la cantidad de cada personaje en lugar
    int zorros = 0;
    int lechugas = 0;
    int conejos = 0;

    // Se recorre los personajes
    for(int i = 0; i < numPersonajes; i++)//i representara el indice de cada persoanje
    {
        // Se verifica si el puntero(persoanje) no es igual a nullptr
        if(personajes[i] != nullptr)
        {
            // Se le asigna la primer letra del ID del personaje a aux
            aux = personajes[i]->getId().substr(0,1);

            // Se realiza una accion según el caso
            // Se verifica si hay un robot
            if(aux == "R")
            {
                // Se le asigna false a alguien fue comido
                alguienFueComido = false;
                // Se termina el for
                break;
                // Aclaración: Como hay un robot en el lugar, nadie puede ser comido
            }

            // Según el caso se aumentara el contador correspondiente
            else if(aux == "Z")
            {
                zorros += 1;
            }
            else if(aux == "L")
            {
                lechugas += 1;
            }
            else if(aux == "C")
            {
                conejos += 1;
            }
        }
    }

    // Se verifica si todavía hay la posibilidad de que alguien halla sido comido
    // Si anteriormente se halla un robot, esta accion se ignora
    if(alguienFueComido == true)
    {
        // Se verifica que halla al menos un conejo en el lugar
        if(conejos > 0)
        {
            // Se verifica que halla al menos un zorro
            if(zorros > 0)
            {
                cout << "El zorro se comió al conejo" << endl;
            }
            // Se verifica que halla al menos una lechuga
            else if(lechugas>0)
            {
                cout << "El conejo se comió la lechuga" << endl;
            }
            else
            {
                alguienFueComido = false;
            }
        }
        else
        {
            alguienFueComido = false;
        }
        // Aclaración: Se verifica primero que haya al menos un conejos ya que si no hay ninguno es claro nadie podrá ser comido
    }

    return alguienFueComido;
}

// Esta funcion solo tiene sentido para la barca
bool Lugar::movimientoPermitido()
{
    return true;
}

// Retorna true si el lugar esta lleno de personajes, si no false
bool Lugar::lleno()
{
    // Var auxiliar que indicara si el lugar esta lleno
    bool auxLleno = true;

    // Se recorre cada puntero(personaje) del lugar
    for(int i = 0; i < numPersonajes; i++)//i representara el indice de cada personaje
    {
        // Se verifica si el puntero(persoanje) es igual a nullptr
        if(personajes[i] == nullptr)
        {
            auxLleno = false;
            break;
            // Aclaración: como un puntero(personaje) es igual a nullptr, el lugar no esta lleno
        }
    }

    return auxLleno;
}

// Esta funcion solo tendrá sentido para Rio.h
bool Lugar::alguienCayoAlRio()
{
    return false;
}