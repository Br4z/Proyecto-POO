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
    //Se guarda el numero de persoanjes de caulquier lugar
    int numPersonajes = lugares[0]->getNumPersonajes();
    cout << "|"; // Primer caracter
    // Se recorre cada lugar de la lista de punteros lugares de Tablero.h
    for (int l = 0; l < 4; l++) // 4 por el numero de lugares
    {
        // Se imprime el nombre de cada lugar
        cout << "     " << lugares[l]->getNombre() << "\t|"; // El primer \t es para centrar los nombres de los lugares.
    }
    cout << endl << " --------------------------------------------------------------- " << endl;

    // Se recorre cada personaje
    for (int i = 0; i < numPersonajes; i++)// i representara el indice de cada personaje
    {
        cout << "|"; // Primer caracter
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
                if(auxLugar->getNombre() == " Rio")
                {
                    cout << "~~~~~~~~~~~~~~~|";

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


// Asigna un personaje en un lugar y indice dado
void Tablero::setPersonajeEnLugar(int cualLugar, int indice, Personaje *personaje)
{
    // Añade el personaje en lugar e indice dados
    lugares[cualLugar]->addPersonaje(indice, personaje);
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

//
void Tablero::moverBarca()
{
    // Puntero auxiliar que apunta a un lugar
    Lugar *auxLugar = nullptr;

    // Var auxiliar que contendra la posicion donde se movera la barca
    int posAux;

    // Se recorre los lugares desde el indice 1 hasta el 2, ya que esas son las posiciones donde puede estar la barca
    for (int i = 1; i < 3; i++)// i representara el indice de cada lugar
    {
        // Se le asigna al puntero auxiliar un lugar del tablero
        auxLugar = lugares[i];

        // Se verifica si auxLugar es la barca
        if (auxLugar->getNombre() == "Barca")
        {
            // Se verifica si la barca puede moverse
            if (auxLugar->movimientoPermitido())
            {
                // Deacuerdo al indice donde se encuentre la barca se le asigna el valor a posAux
                if (i == 1)
                {
                    // La barca se movera al indice 2
                    posAux = 2;
                }
                else
                {
                    //La barca se movera al indice 1
                    posAux = 1;
                }

                // Se guarda el lugar donde se movera la barca en un puntero auxiliar
                Lugar *aux = lugares[posAux];

                // Se remueve el lugar donde se movera la barca, NO SE ELIMINA 
                lugares[posAux] = nullptr;

                // Se mueve la barca al lugar dado por posAux
                lugares[posAux] = auxLugar;

                // Se remueve la barca de su posicion anterior, NO SE ELIMINA
                lugares[i] = nullptr;

                // Se pone el lugar anteroriormente guardado donde estaba la barca
                lugares[i] = aux;

                //En palabras sencillas, la barca y el lugar donde se mueve se intercambian
            }
            
            // Se termina el for
            break;
        }
    }
}

//
string Tablero::estadoDelJuego()
{
    //var aux Estado
    string estado = "En Juego";

    // Se verifica si el ultimo lugar(La Meta) esta lleno, es decir si todos los personajes estan ahi
    if (lugares[3]->lleno())
    {
        estado = "Ganado";
    }
    else
    {
        // Se recorre cada lugar
        for (int i = 0; i < 4; i++)
        {
            // Se verifica si alguien fue comido o cayo al rio en cada lugar
            if (lugares[i]->alguienFueComido() || lugares[i]->alguienCayoAlRio())
            {
                cout << "Fin del juego" << endl;

                estado = "Perdido";
                // Se termina el for
                break;
            }
        }
    }

    // Finalmente se retorna la var auxiliar
    return estado;
}