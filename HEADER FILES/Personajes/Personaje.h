
/*

Archivo: Personaje.h
Autor:
Huertas Cadavid Nicolas Fernando
<nicolas.huertas@correounivalle.edu.co>
Fecha Creación: 2022-03-19
Fecha Ultima Modificación: 2022-01-19
Licencia: GNU-GPL

*/

/**
Clase: Personaje
Responsabilidad: Representar a un personaje del juego y su funcionamiento
Relaciones: NINGUNA
*/

#pragma once
#ifndef PERSONAJE_H
#define PERSONAJE_H
#include <iostream>
#include <string>
using namespace std;


class Personaje
{
protected:
    string nombre;
    string ID;
public:
    Personaje();
    ~Personaje();
    string getNombre();
    void addToNombre(string nombre);
    string getId();
};

#else
class Personaje;
#endif