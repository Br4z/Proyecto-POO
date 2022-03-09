/*

Archivo: Rio.cpp
Autor: 
Getial Getial Juan Sebastian
<getial.juan@correounivalle.edu.co>
Calderon Prieto Brandon
<bcalderonprieto@gmail.com>
Huertas Cadavid Nicolas Fernando
<nicolas.huertas@correounivalle.edu.co>
Fecha Creacion: 2022-02-19
Fecha Ultima Modificacion: 2022-02-19
Licencia: GNU-GPL

*/

#include "../../../HEADER FILES/Lugares/EXTENDS FROM LUGAR/Rio.h"
#include <iostream>
using namespace std;

Rio::Rio(int _numPersonajes) : Lugar(_numPersonajes)
{
    nombre = "Rio";
}

Rio::~Rio()
{

}

//
bool Rio::alguienCayoAlRio()
{
    bool alguienCayoAlRio = false;
    for(int i = 0; i<numPersonajes; i++)
    {
        if(personajes[i] != nullptr)
        {
            cout<<personajes[i]->getNombre()<<" cayo al rio"<<endl;
            alguienCayoAlRio = true;
            break;
        }
    }
    return alguienCayoAlRio;
}