/*

Archivo: Lugar.cpp
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

#include "../../HEADER FILES/Lugares/Lugar.h"
#include <iostream>
using namespace std;

Lugar::Lugar(int _numPersonajes)
{
    personajes = new Personaje*[_numPersonajes];
    numPersonajes = _numPersonajes;
    for(int i = 0; i<numPersonajes; i++)
    {
        personajes[i] = nullptr;
    }
}

Lugar::Lugar()
{

}

Lugar::~Lugar()
{
    for(int i = 0; i<numPersonajes; i++)
    {
        delete personajes[i];
        personajes[i] = nullptr;
    }
    delete personajes;
}

void Lugar::mostrarPersonajes()
{
    for(int i = 0; i<numPersonajes; i++)
    {
        if(personajes[i] == nullptr)
        {
            cout<<"vacio"<<endl;
        }
        else
        {
            cout<<personajes[i]->getNombre()<<endl;
        }
    }
}


int Lugar::getNumPersonajes()
{
    return numPersonajes;
}


void Lugar::addPersonaje(int indice, Personaje* personaje) // Del vector de 
{
    personajes[indice] = personaje;
}


Personaje* Lugar::getPersonaje(int indice)
{
    return personajes[indice];
}

string Lugar::getNombre()
{
    return nombre;
}

void Lugar::removerPersonaje(int indice)
{
    personajes[indice] = nullptr;
}

bool Lugar::alguienFueComido()
{
    bool alguienFueComido = true;
    string aux;
    int zorros = 0;
    int lechugas = 0;
    int conejos = 0;

    for(int i = 0; i<numPersonajes; i++)
    {
        if(personajes[i] != nullptr)
        {
            aux = personajes[i]->getId().substr(0,1);
            if(aux == "R")
            {
                alguienFueComido = false;
                break;
            }
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

    if(alguienFueComido == true)
    {
        if(conejos>0)
        {
            if(zorros>0)
            {
                cout<<"El zorro se comio al conejo"<<endl;
            }
            else if(lechugas>0)
            {
                cout<<"El conejo se comio la lechuga"<<endl;
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
    }

    return alguienFueComido;
}

bool Lugar::movimientoPermitido()
{
    return NULL;
}

bool Lugar::lleno()
{
    bool auxLleno = true;
    for(int i = 0; i<numPersonajes; i++)
    {
        if(personajes[i] == nullptr)
        {
            auxLleno = false;
            break;
        }
    }
    return auxLleno;
}

bool Lugar::alguienCayoAlRio()
{
    return false;
}