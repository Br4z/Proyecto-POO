/*

Archivo: Jugador.cpp
Autor:
Huertas Cadavid Nicolas Fernando
<nicolas.huertas@correounivalle.edu.co>
Fecha Creación: 2022-03-19
Fecha Ultima Modificación: 2022-01-19
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
    delete tablero;
}

void Jugador::setPersonajes()
{
    // Var con el numero de personajes por defecto
    int numPersonajes = 4;
    // Var para recibir cuantos personajes extra desea el jugador
    int aux;
    cout << "¿ Deseas agregar personajes extra ?" << endl;
    cout << "Digitá cuantos (en caso de no querer digitá 0): ";
    cin >> aux;
    // Se le suma los personajes extra al numero de personajes por defecto
    numPersonajes += aux;

    //Se establece el tablero
    this->tablero = new Tablero(numPersonajes);

    // Var que contiene el numero de personajes extra
    int numPersonajesExtra = numPersonajes - 4;

    // Puntero auxiliar que apunta a un Personaje
    Personaje *personajeExtra = nullptr;

    //variable que indicara si se eligio una opcion permitida
    bool validador;
    // Se hace repite el ciclo según el numero de personajes extra a añadir
    for (int i = 0; i < numPersonajesExtra; i++)
    {
        validador = true;
        // Var que representara el indice o posición donde se añadirá el personaje extra
        // Se le suma 4 por que los personaje por defecto ocupan las posiciones anteriores
        int pos = i + 4;
        cout << "1. Robot\n"
             << "2. Zorro\n"
             << "3. Lechuga\n"
             << "4. Conejo" << endl;
        cout << "Digite el numero del personaje que desea: ";
        cin >> aux;

        // Según la opción digitada se le asigna un personaje al puntero auxiliar PersonajeExtra
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
            cout << "Por favor escoge una opción correcta !" <<endl;
            i--;
            validador = false;
        }

        //Se verifica que se halla elegido una opcion permitida
        if(validador)
        {
            // Var auxiliar que guarda un numero en string
            string auxStr = to_string(i + 1);

            // Se le añade el auxStr al nombre y el ID del personajeExtra
            personajeExtra->addToNombre(auxStr); // Se le añade (el numero, como diferenciador) al nombre y el ID que ya tiene.

            // Se agrega al personajeExtra en la orilla y en la posición dada por la var auxiliar pos
            tablero->setPersonajeEnLugar(0, pos, personajeExtra);
            // Nótese que siempre se agrega en la orilla, por ello el primer parametro es 0 siempre
            personajeExtra = nullptr;
        }
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
    tablero->moverPersonaje(idPersonaje);
}

// Mueve el lugar Barca
void Jugador::moverBarca()
{
    tablero->moverBarca();
}

// Devuelve true si el juego esta en curso, o false si termino
bool Jugador::estadoDelJuego()
{
    //Var auxiliar
    string estado = tablero->estadoDelJuego();

    //Se verifica cada caso
    if(estado != "En Juego")
    {
        if(estado == "Ganado")
        {
            winOrLoser = true;
        }
        else
        {
            winOrLoser = false;
        }
        return false;
    }
    else
    {
        return true;
    }
}

// Muestra los IDS de los personajes
void Jugador::verIdsPersonajes()
{
    tablero->mostrarIdsPersonajes();
}

// Retorna el atributo winOrLoser de Jugador.h
bool Jugador::getWinOrLoser()
{
    return winOrLoser;
}