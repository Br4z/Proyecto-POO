/*

Archivo: Robot.h
Autor:
Huertas Cadavid Nicolas Fernando
<nicolas.huertas@correounivalle.edu.co>
Fecha Creación: 2022-03-19
Fecha Ultima Modificación: 2022-01-19
Licencia: GNU-GPL

*/

/**
Clase: Robot
Responsabilidad: Representar a un Robot del juego y su funcionamiento
Relaciones: 
- Es un Personaje
*/

#pragma once
#ifndef ROBOT_H
#define ROBOT_H
#include <iostream>
#include "../Personaje.h"
using namespace std;

class Robot : public Personaje
{
    private:
    public:
        Robot();
        ~Robot();
};

#else
class Robot;
#endif