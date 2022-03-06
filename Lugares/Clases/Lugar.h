/*

Archivo: Lugar.h
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


/**
Clase: Lugar
Responsabilidad: Representar cada uno de los lugares del juego y su funcionamiento
Relaciones: 
- Contiene Personaje.h (Zorro.h, Conejo.h, Lechuga.h, Robot.h)
*/

#pragma once
#ifndef LUGAR_H
#define LUGAR_H
#include <iostream>
#include "../../Personajes/Clases/Personaje.h"
#include "../../Personajes/Clases/Conejo.h"
#include "../../Personajes/Clases/Zorro.h"
#include "../../Personajes/Clases/Robot.h"
#include "../../Personajes/Clases/Lechuga.h"
using namespace std;

class Lugar
{
    protected:
        Personaje **personajes;
        int numPersonajes;
        string nombre;
    public:
        Lugar(int _numPersonajes);
        Lugar();
        ~Lugar();
        string getNombre();
        void mostrarPersonajes();
        void addPersonaje(int indice, Personaje* personaje);
        Personaje* getPersonaje(int indice);
        int getNumPersonajes();
        void removerPersonaje(int indice);
        bool alguienFueComido();
        virtual bool movimientoPermitido();
        virtual bool lleno();
        virtual bool alguienCayoAlRio();
};

#else
class Lugar;
#endif