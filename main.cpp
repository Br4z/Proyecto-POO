#include <iostream>
#include <string.h>
#include "HEADER FILES/Jugador.h"
using namespace std;

int main()
{
    system("clear");
    string decoracion = " --------------------------------------------------------------- \n";
    string ID;
    Jugador jugador;
    // Se establecen los personajes
    jugador.setPersonajes();
    cout << "Bienvenido al juego" << endl;
    system("clear");
    // Se verifica el estado del juego en cada ciclo
    do
    {
        // Se dibuja el tablero
        cout << decoracion;
        jugador.verTablero();
        cout << decoracion;
        jugador.verIdsPersonajes();
        cout<< "Barco  \t\tB"<<endl;
        cout << "---------\t---" << endl; // Mas decoracion
        cout << "Digite el id del elemento que desee mover: ";
        cin >> ID;
        ID[0] = toupper(ID[0]); // Como las ids de los personajes están en mayúsculas
        // esto se asegura que la entrada siempre sea una mayúscula
        
        if (ID == "B")
        {
            jugador.moverBarca();
        }
        else
        {
            jugador.moverPersonaje(ID);
        }
        system("clear");
    }while (jugador.estadoDelJuego());

    if (jugador.getWinOrLoser())
    {
        jugador.verTablero(); // Imprimo la ultima jugada
        cout << "Felicidades, ganaste el juego !" << endl;
    }
    else
    {
        jugador.verTablero(); // Imprimo la ultima jugada
        cout << "Has perdido !" << endl;
    }

    cout << "El programa finalizo correctamente" << endl;
    return 0;
}
