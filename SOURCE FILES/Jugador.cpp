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
    // Var con el numero de personajes por defecto
    int numPersonajes = 4;
    // Var para recibir cuantos personajes extra desea el jugador
    int aux;
    cout << "¿ Deseas agregar personajes extra ?" << endl;
    cout << "Digita cuantos (en caso de no querrer digita 0): ";
    cin >> aux;
    // Se le suma los personajes extra al numero de personajes por defecto
    numPersonajes += aux;

    //Se establece el tablero
    this->tablero = new Tablero(numPersonajes);

    // Var que contiene el numero de personajes extra
    int numPersonajesExtra = numPersonajes - 4;

    // Puntero auxiliar que apunta a un Personaje
    Personaje *personajeExtra = nullptr;

    // Se hace repite el ciclo segun el numero de personajes extra a añadir
    for (int i = 0; i < numPersonajesExtra; i++)
    {
        // Var que representara el indice o posicion donde se añadira el personaje extra
        // Se le suma 4 por que los personaje por defecto ocupan las posiciones anteriores
        int pos = i + 4;
        cout << "1. Robot\n"
             << "2. Zorro\n"
             << "3. Lechuga\n"
             << "4. Conejo" << endl;
        cout << "Digite el numero del personaje que desea: ";
        cin >> aux;

        // Segun la opcion digitada se le asigna un personaje al puntero auxiliar PersonajeExtra
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
        else
        {
            cout << ("Por favor escoga una opcion correcta !");
        }

        // Var auxiliar que guarda un numero en string
        string auxStr = to_string(i + 1);

        // Se le añade el auxStr al nombre y el ID del personajeExtra
        personajeExtra->addToNombre(auxStr); // Se le añade (el numero, como diferenciador) al nombre y el ID que ya tiene.

        // Se agrega al personajeExtra en la orilla y en la posicion dada por la var auxiliar pos
        tablero->setPersonajeEnLugar(0, pos, personajeExtra);
        // Notese que siempre se agrega en la orilla, por ello el primer parametro es 0 siempre
        personajeExtra = nullptr;
    }
    // Se establecen los IDS de los personajes en el vector idsPersonajes
    tablero->setIdsPersonajes();
    // Se establecen los nombres de los personajes en el vector nombresPersonajes
    tablero->setNombresPersonajes();
}

// Dibuja el tablero
void Jugador::verTablero()
{
    //tablero realiza su metodo para dibujar el tablero
    tablero->dibujarTablero();
}

// Mueve el personaje del idPersonaje dado
void Jugador::moverPersonaje(string idPersonaje)
{
    // Var auxiliar que contendra la posicion(lugar) donde se movera el personaje
    int auxPos;
    
    // Var auxiliar que dira si se ha encontrado el personaje
    bool encontrado = false;

    // Se recorre cada lugar
    for (int i = 0; i < 4; i++)//i representara el indice de cada lugar
    {
        // Se recorre cada personaje
        for (int j = 0; j < tablero->getLugar(i)->getNumPersonajes(); j++)//i representara el indice de cada personaje
        {
            // Se verfica que el puntero personaje no apunte a nullptr
            if (tablero->getLugar(i)->getPersonaje(j) != nullptr)
            {
                //Se verifica que el ID del personaje sea igual al recibido como parametro
                if (tablero->getLugar(i)->getPersonaje(j)->getId() == idPersonaje)
                {
                    // Se crea un puntero personaje auxiliar que apunta al personaje encontrado
                    Personaje *aux = tablero->getLugar(i)->getPersonaje(j);

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
                    if (tablero->getLugar(auxPos)->lleno() == false)
                    {
                        // Se pone el personaje en el lugar dado, y en el mismo indice donde se encontro
                        tablero->setPersonajeEnLugar(auxPos, j, aux);//aux es el personaje

                        // Se remueve el personaje del lugar en el que estaba
                        tablero->getLugar(i)->removerPersonaje(j);
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

// Mueve el lugar Barca
void Jugador::moverBarca()
{
    // Puntero auxiliar que apunta a un lugar
    Lugar *auxLugar = nullptr;

    // Var auxiliar que contendra la posicion donde se movera la barca
    int posAux;

    // Se recorre los lugares desde el indice 1 hasta el 2, ya que esas son las posiciones donde puede estar la barca
    for (int i = 1; i < 3; i++)// i representara el indice de cada lugar
    {
        // Se le asigna al puntero auxiliar un lugar del tablero
        auxLugar = tablero->getLugar(i);

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
                Lugar *aux = tablero->getLugar(posAux);

                // Se remueve el lugar donde se movera la barca
                tablero->removerLugar(posAux);

                // Se mueve la barca al lugar dado por posAux
                tablero->setLugar(posAux, auxLugar);

                // Se remueve la barca de su posicion anterior
                tablero->removerLugar(i);

                // Se pone el lugar anteroriormente guardado donde estaba la barca
                tablero->setLugar(i, aux);

                //En palabras sencillas, la barca y el lugar donde se mueve se intercambian
            }
            
            // Se termina el for
            break;
        }
    }
}

// Devulve true si el juego esta en curso, o false si termino
bool Jugador::estadoDelJuego()
{
    // Var auxiliar
    bool auxEstado = true;

    // Se recorre cada lugar
    for (int i = 0; i < 4; i++)
    {
        // Se verifica si alguien fue comido en cada lugar
        if (tablero->getLugar(i)->alguienFueComido())
        {
            cout << "Fin del juego" << endl;
            // Se cambia la var auxiliar a false
            auxEstado = false;

            // Y se le asigna false al atributo winOrLoser de Jugador.h
            winOrLoser = false;

            // Se termina el for
            break;
        }
    }

    // Se recorre desde el lugar 1 hasta el lugar 2, ya que en estas posiciones es donde puede estar la barca
    for (int j = 1; j < 3; j++)
    {
        // Se verfica si cad lugar alguien cayo al rio
        if (tablero->getLugar(j)->alguienCayoAlRio())
        {
            // Se cambia la var auxiliar a false
            auxEstado = false;

            // Y se le asigna false al atributo winOrLoser de Jugador.h
            winOrLoser = false;
        }
    }

    // Se verifica si el ultimo lugar(La Meta) esta lleno, es decir si todos los personajes estan ahi
    if (tablero->getLugar(3)->lleno())
    {
        // Se cambia la var auxiliar a false
        auxEstado = false;

        // Y se le asigna true al atributo winOrLoser de Jugador.h
        winOrLoser = true;
    }

    // Finalmente se retorna la var auxiliar
    return auxEstado;
}

// Muestra los IDS de los persoanjes
void Jugador::verIdsPersonajes()
{
    tablero->mostrarIdsPersonajes();
}

// Retorna el atributo winOrLoser de Jugador.h
bool Jugador::getWinOrLoser()
{
    return winOrLoser;
}