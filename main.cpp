#include <iostream>
#include "Jugador/Jugador.h"
using namespace std;

int main()
{
    string id;
    Jugador jugador;
    jugador.setPersonajes();
    cout << "Bienvenido al juego" << endl;
    while (jugador.estadoDelJuego())
    {
        system("clear");
        jugador.verTablero();
        cout << "-------------------------------------------------------" << endl;
        jugador.verIdsPersonajes();
        cout << "Digite el id del elemento que desee mover: ";
        cin >> id;
        if (id == "B")
        {
            jugador.moverBarca();
        }
        else
        {
            jugador.moverPersonaje(id);
        }
    }
    if (jugador.getWinOrLoser())
    {
        cout << "Felicidades, ganaste el juego" << endl;
    }
    else
    {
        cout << "Has perdido" << endl;
    }

    cout << "El programa finalizo correctamente" << endl;
    return 0;
}