/*

Archivo: Menu.h
Autor: 
Getial Getial Juan Sebastian
<getial.juan@correounivalle.edu.co>
Calderon Prieto Brandon
<bcalderonprieto@gmail.com>
Huertas Cadavid Nicolas Fernando
<nicolas.huertas@correounivalle.edu.co>
Cordoba Collazos Angie Natalia
<natalia8cordoba1908@gmail.com>
Fecha Creacion: 2022-01-29
Fecha Ultima Modificacion: 2022-01-29
Licencia: GNU-GPL

*/

/**

Clase: Menu
Responsabilidad: Representar el funcionamiento basico del menu del juego
Relaciones:
- Contiene Lugar.h
- Conoce Jugador.h

*/

#pragma once
#ifndef MENU_H
#define MENU_H
#include "Jugador/Jugador.h"
#include "Lugares/Clases/Lugar.h"
#include "Lugares/Clases/Barca.h"
#include "Lugares/Clases/Orilla_D.h"
#include "Lugares/Clases/Orilla_I.h"

class Menu
{
  private:
    Lugar *lugares;//Matriz o tablero del juego
};

#else
class Menu;
#endif