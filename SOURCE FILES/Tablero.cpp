/*

Archivo: Tablero.cpp
Autor:
Getial Getial Juan Sebastian
<getial.juan@correounivalle.edu.co>
Fecha Creación: 2022-03-19
Fecha Ultima Modificación: 2022-03-19
Licencia: GNU-GPL

*/

#include <iostream>
#include "../HEADER FILES/Tablero.h"
using namespace std;

Tablero::Tablero(int numPersonajes)
{
    // Se agregan los lugares por defecto
    lugares[0] = new Orilla(numPersonajes);
    lugares[1] = new Barca(numPersonajes);
    lugares[2] = new Rio(numPersonajes);
    lugares[3] = new Meta(numPersonajes);
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
    // Se guarda el numero de personajes de cualquier lugar
    int numPersonajes = lugares[0]->getNumPersonajes();
    cout << "|"; // Primer carácter
    // Se recorre cada lugar de la lista de punteros lugares de Tablero.h
    for (int l = 0; l < 4; l++) // 4 por el numero de lugares
    {
        // Se imprime el nombre de cada lugar
        cout << "     " << lugares[l]->getNombre() << "\t|"; // El primer \t es para centrar los nombres de los lugares.
    }
    cout << endl << " --------------------------------------------------------------- " << endl; // Parte de la decoracion

    // Se recorre cada personaje
    for (int i = 0; i < numPersonajes; i++)// i representara el indice de cada personaje
    {
        cout << "|"; // Primer carácter
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

                } else 
                {
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
    int aux = lugares[0]->getNumPersonajes(); // El numero de personajes siempre es igual a los que aparecen en la orilla

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
    for (int i = 0; i < aux; i++)// i representara el indice de cada personaje
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
    // Var auxiliar que contendrá la posición(lugar) donde se movera el personaje
    int auxPos;
    
    // Var auxiliar que dirá si se ha encontrado el personaje
    bool encontrado = false;

    // Var con numero de personajes
    int numPersonajes = lugares[0]->getNumPersonajes();

    // Se recorre cada lugar
    for (int i = 0; i < 4; i++)//i representara el indice de cada lugar
    {
        // Se recorre cada personaje
        for (int j = 0; j < numPersonajes; j++)//j representara el indice de cada personaje
        {
            // Se verifica que el puntero personaje no apunte a nullptr
            if (lugares[i]->getPersonaje(j) != nullptr)
            {
                //Se verifica que el ID del personaje sea igual al recibido como parametro
                if (lugares[i]->getPersonaje(j)->getId() == idPersonaje)
                {
                    // Se crea un puntero personaje auxiliar que apunta al personaje encontrado
                    Personaje *personajeEncontrado = lugares[i]->getPersonaje(j);

                    // Según el indice(lugar) donde fue encontrado se definirá el lugar donde se movera
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
                        // Se pone el personaje en el lugar dado, y en el mismo indice donde se encontró
                        lugares[auxPos]->addPersonaje(j, personajeEncontrado);//aux es el personaje

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


void Tablero::moverBarca()
{
    // Puntero auxiliar que apunta a un lugar
    Lugar *auxLugar = nullptr;

    // Var auxiliar que contendrá la posición donde se movera la barca
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
                // De acuerdo al indice donde se encuentre la barca se le asigna el valor a posAux
                if (i == 1)
                {
                    // La barca se movera al indice 2
                    posAux = 2;
                }
                else
                {
                    // La barca se movera al indice 1
                    posAux = 1;
                }

                // Se guarda el lugar donde se movera la barca en un puntero auxiliar
                Lugar *aux = lugares[posAux];

                // Se remueve el lugar donde se movera la barca, NO SE ELIMINA 
                lugares[posAux] = nullptr;

                // Se mueve la barca al lugar dado por posAux
                lugares[posAux] = auxLugar;

                // Se remueve la barca de su posición anterior, NO SE ELIMINA
                lugares[i] = nullptr;

                // Se pone el lugar anteriormente guardado donde estaba la barca
                lugares[i] = aux;

                //En palabras sencillas, la barca y el lugar donde se mueve se intercambian
            }
            
            // Se termina el for
            break;
        }
    }
}


string Tablero::estadoDelJuego()
{
    //var aux Estado
    string estado = "En Juego";

    // Puntero auxiliar que apunta a un lugar
    Lugar *auxLugar = nullptr;

    // Se verifica si el ultimo lugar(La Meta) esta lleno, es decir si todos los personajes están ahi
    if (lugares[3]->lleno())
    {
        estado = "Ganado";
    }
    else
    {
        // Se recorre cada lugar
        for (int i = 0; i < 4; i++)
        {
            // Se le asigna al puntero auxiliar un lugar del tablero
            auxLugar = lugares[i];
            // Se verifica si alguien cayo en el rio
            if(auxLugar->getNombre() == " Rio")
            {
                if(auxLugar->alguienCayoAlRio())
                {
                    cout << "Fin del juego" << endl;

                    estado = "Perdido";
                    // Se termina el for
                    break;                    
                }
            // Se verifica si alguien fue comido    
            }else if (auxLugar->alguienFueComido())
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
