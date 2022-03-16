/*

Archivo: Robot.h
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
Clase: Robot
Responsabilidad: Representar a un Robot del juego y su funcionamiento
Relaciones: 
- Es un Personaje.h
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