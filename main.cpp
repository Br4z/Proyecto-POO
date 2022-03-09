#include <iostream>
#include <string.h>
#include "HEADER FILES/Jugador.h"
using namespace std;

int main()
{
    string decoracion = "------------------------------------------------------- \n";
    string ID;
    Jugador jugador;
    jugador.setPersonajes();
    cout << "Bienvenido al juego" << endl;
    while (jugador.estadoDelJuego())
    {
        system("clear");
        jugador.verTablero();
        cout << decoracion;
        jugador.verIdsPersonajes();
        cout << "Digite el id del elemento que desee mover: ";
        cin >> ID;
        ID[0] = toupper(ID[0]);
        
        if (ID == "B")
        {
            jugador.moverBarca();
        }
        else
        {
            jugador.moverPersonaje(ID);
        }
    }
    if (jugador.getWinOrLoser())
    {
        cout << "Felicidades, ganaste el juego !" << endl;
    }
    else
    {
        cout << "Has perdido !" << endl;
    }

    cout << "El programa finalizo correctamente" << endl;
    return 0;
}