/*

Archivo: Jugador.cpp
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
#include "../HEADER FILES/Jugador.h"
using namespace std;

Jugador::Jugador()
{
}

Jugador::~Jugador()
{
}

void Jugador::setPersonajes()
{
    int numPersonajes = 4;
    int aux;
    cout << "¿ Deseas agregar personajes extra ?" << endl;
    cout << "Digita cuantos (en caso de no querrer digita 0): ";
    cin >> aux;
    numPersonajes += aux;
    menu.setNumPersonajes(numPersonajes);

    int numPersonajesExtra = numPersonajes - 4;
    Personaje *personajeExtra = nullptr;
    for (int i = 0; i < numPersonajesExtra; i++)
    {
        int pos = i + 4;
        cout << "1. Robot\n"
             << "2. Zorro\n"
             << "3. Lechuga\n"
             << "4. Conejo" << endl;
        cout << "Digite el numero del personaje que desea: ";
        cin >> aux;
        if (aux == 1)
        {
            personajeExtra = new Robot();
        }
        else if (aux == 2)
        {
            personajeExtra = new Zorro();
        }
        else if (aux == 3)
        {
            personajeExtra = new Lechuga();
        }
        else if (aux == 4)
        {
            personajeExtra = new Conejo();
        }

        string auxStr = to_string(i + 1);
        personajeExtra->addToNombre(auxStr);
        menu.setPersonajeEnLugar(0, pos, personajeExtra);
        personajeExtra = nullptr;
    }
    menu.setIdsPersonajes();
    menu.setNombresPersonajes();
}

void Jugador::verTablero()
{
    menu.dibujarTablero();
}

void Jugador::moverPersonaje(string idPersonaje)
{
    int auxPos;
    bool encontrado = false;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < menu.getLugar(i)->getNumPersonajes(); j++)
        {
            if (menu.getLugar(i)->getPersonaje(j) != nullptr)
            {
                if (menu.getLugar(i)->getPersonaje(j)->getId() == idPersonaje)
                {
                    Personaje *aux = menu.getLugar(i)->getPersonaje(j);
                    if (i == 0 || i == 2)
                    {
                        auxPos = i + 1;
                    }
                    else
                    {
                        auxPos = i - 1;
                    }
                    if (menu.getLugar(auxPos)->lleno() == false)
                    {
                        menu.setPersonajeEnLugar(auxPos, j, aux);
                        menu.getLugar(i)->removerPersonaje(j);
                    }
                    encontrado = true;
                    break;
                }
            }
        }
        if (encontrado == true)
        {
            break;
        }
    }
}

void Jugador::moverBarca()
{
    Lugar *auxLugar = nullptr;
    int posAux;
    for (int i = 1; i < 3; i++)
    {
        auxLugar = menu.getLugar(i);
        if (auxLugar->getNombre() == "Barca")
        {
            if (auxLugar->movimientoPermitido())
            {
                if (i == 1)
                {
                    posAux = 2;
                }
                else
                {
                    posAux = 1;
                }
                Lugar *aux = menu.getLugar(posAux);
                menu.removerLugar(posAux);
                menu.setLugar(posAux, auxLugar);
                menu.removerLugar(i);
                menu.setLugar(i, aux);
            }
            break;
        }
    }
}

bool Jugador::estadoDelJuego()
{
    bool auxEstado = true;
    for (int i = 0; i < 4; i++)
    {
        if (menu.getLugar(i)->alguienFueComido())
        {
            cout << "Fin del juego" << endl;
            auxEstado = false;
            winOrLoser = false;
            break;
        }
    }
    for (int j = 1; j < 3; j++)
    {
        if (menu.getLugar(j)->alguienCayoAlRio())
        {
            auxEstado = false;
            winOrLoser = false;
        }
    }
    if (menu.getLugar(3)->lleno())
    {
        auxEstado = false;
        winOrLoser = true;
    }
    return auxEstado;
}

void Jugador::verIdsPersonajes()
{
    menu.mostrarIdsPersonajes();
}

bool Jugador::getWinOrLoser()
{
    return winOrLoser;
}