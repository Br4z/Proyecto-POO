
/*
Archivo: main.cpp
Autores: 
Getial Juan Sebastian 
<getial.juan@correounivalle.edu.co>
Calderón Prieto Brandon
<bcalderonprieto@gmail.com>
Huertas Cadavid Nicolas Fernando
<nicolas.huertas@correounivalle.edu.co>
Fecha Creacion: 2022-03-19
Fecha Ultima Modificacion: 2022-03-19
Licencia: GNU-GPL
*/
#include <iostream>
#include <string.h>
#include "HEADER FILES/Jugador.h"
using namespace std;

/*
Historia:Hay un robot que debe transportar un zorro, un conejo y una lechuga desde un lado del 
río hasta la otra orilla, usando una barca. En la barca solo cabe uno de los tres individuos, 
además del robot. El problema es que si el robot deja solos al zorro y al conejo, el zorro se 
comerá el conejo. Y si deja solos al conejo y la lechuga, el conejo se comerá la lechuga. 
El jugador debe controlar qué órdenes dar, para lograr que el robot transporte los tres 
individuos a la otra orilla, sanos y salvos.
*/

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
