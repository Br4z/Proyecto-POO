#include <string>
#include <iostream>
using namespace std;

int main()
{

// Se estandarizan los espacios para que no hayan saltos indeseados

    string tablero[5][4] = {
    {"ORILLA ","BARCA  ","       ","META   "}, 
    {"Robot  ","       ","       ","       "},
    {"Zorro  ","       ","       ","       "},
    {"Conejo ","       ","       ","       "},
    {"Lechuga","       ","       ","       "}
};

    char menu = 'S';
    char opcion = 'S';
    // Estados iniciales de los elementos, aprovechando que solo se mueven horizontalmente.
    int posicionBarca = 1;
    int posicionRobot = 0;
    int posicionZorro = 0;
    int posicionConejo = 0;
    int posicionLechuga = 0;
    // Inicialmente su movimiento es hacia la derecha ->
    string orientacionRobot =  "Derecha";
    string orientacionZorro =  "Derecha";
    string orientacionConejo =  "Derecha";
    string orientacionLechuga =  "Derecha";
    string finJuego = "";

    system("clear");

    do
    {
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                cout << tablero[i][j] << "\t\t";
            }
            cout << "\n";
        }

        cout << "---------------------------------------------" << endl;
        cout << "Estados en el juego:" << endl;
        cout << "Barca: " << posicionBarca << endl;
        cout << "Robot " << posicionRobot << endl;
        cout << "Zorro: " << posicionZorro << endl;
        cout << "Conejo: " << posicionConejo << endl;
        cout << "Lechuga: " << posicionLechuga << endl;
        cout << "*** Jugar ***" << endl;
        cout << "B - Barca se mueve a la orilla " << endl;
        cout << "R - El Robot salta a la barca" << endl;
        cout << "Z - El Zorro salta a la barca" << endl;
        cout << "C - El Conejo salta a la barca" << endl;
        cout << "L - El Lechuga salta a la barca" << endl;
        cout << "Digite su opción:";

        cin >> opcion;

        //Casos donde el jugador pierde y gana (proxima implementacion)

        if(posicionConejo == posicionLechuga && posicionRobot != posicionConejo)
        {
            finJuego = "Fin de juego, el Conejo se come la Lechuga.";
            menu = 'N';
            break;
        } else if (posicionConejo == posicionZorro && posicionRobot != posicionConejo)
        {
            finJuego = "Fin de juego, el Zorro se come al Conejo.";
            menu = 'N';
            break;
        } else if (posicionZorro == posicionConejo == posicionLechuga && posicionConejo == 3) // La comparacion se puede hacer con cualquiera
        {
            finJuego = "GANASTE"; // posicionZorro == 3 && posicionConejo == 3 && posicionLechuga == 3
            break;
        }

        switch (opcion)
        {
        // Barca
        case 'B':
        case 'b':
            // Casos para Ida (derecha a izquierda)
            if (posicionBarca == 1 && posicionRobot == 1) // La barca solo se mueve si el robot esta en ella
            {
                // La barca siempre se mueve asi no haya nadie en ella
                tablero[0][1] = "       "; // Guardamos el espacio de la barca, para que se alinee bien (7 por lechuga)
                tablero[0][2] = "BARCA  "; 
                posicionBarca = 2;
                posicionRobot = 2; // En todos lo casos esto se aplica, asi que nos ahorramos repetirlo.

                if (posicionConejo == 1)
                {
                    tablero[1][1] = "       ";
                    tablero[1][2] = "Robot  ";
                    tablero[3][1] = "       ";
                    tablero[3][2] = "Conejo ";

                    posicionConejo = 2;

                } else if (posicionZorro == 1)
                {
                    tablero[1][1] = "       ";
                    tablero[1][2] = "Robot  ";
                    tablero[2][1] = "       ";
                    tablero[2][2] = "Zorro  ";

                    posicionZorro = 2;

                } else if (posicionLechuga == 1)
                {
                    tablero[1][1] = "       ";
                    tablero[1][2] = "Robot  ";
                    tablero[4][1] = "       ";
                    tablero[4][2] = "Lechuga";

                    posicionLechuga = 2;

                } else  // Este es el caso cuando el robot esta solo
                {
                    tablero[1][1] = "       ";
                    tablero[1][2] = "Robot  ";                    
                }

            } else if (posicionBarca == 2 && posicionRobot == 2) // Casos para vuelta (izquierda a derecha)
            {   
                // La barca siempre se mueve asi no haya nadie en ella
                tablero[0][1] = "BARCA  ";
                tablero[0][2] = "       "; 
                posicionBarca = 1;
                posicionRobot = 1; // En todos lo casos esto se aplica, asi que nos ahorramos repetirlo.

                if (posicionConejo == 2)
                {
                    tablero[1][1] = "Robot  ";
                    tablero[1][2] = "       ";
                    tablero[3][1] = "Conejo ";
                    tablero[3][2] = "       ";

                    posicionConejo = 1;

                }else if (posicionZorro == 2)
                {
                    tablero[1][1] = "Robot  ";
                    tablero[1][2] = "       ";
                    tablero[2][1] = "Zorro  ";
                    tablero[2][2] = "       ";

                    posicionZorro = 1;

                } else if (posicionLechuga == 2)
                {
                    tablero[1][1] = "Robot  ";
                    tablero[1][2] = "       ";
                    tablero[4][1] = "Lechuga";
                    tablero[4][2] = "       ";

                    posicionLechuga = 1;  

                } else  // Este es el caso cuando el robot esta solo
                {
                    tablero[1][1] = "Robot  ";
                    tablero[1][2] = "       ";                    
                }
            } else 
            {
                cout << endl << "Recuerda que la barca no se mueve sin el robot" << endl;
            }
        

            menu = 'S';
            system("clear");

            break;
        // Robot
        case 'R':
        case 'r':
            // Todos los casos de movimiento del robot
            if(orientacionRobot == "Derecha")
            {
            // Movimientos de ida (derecha a izquierda)
                if (posicionRobot == 0 ) // Que haya espacio para el se comprueba con los otros personajes
                { 
                    // Hago el movimiento en todos los casos
                    tablero[1][0] = "       ";
                    tablero[1][1] = "Robot  ";
                    posicionRobot = 1; // Actualizo la varibale de control

                    // Pasa cuando no hay barco en el que pueda saltar
                    if (posicionBarca != 1)
                    {
                        finJuego = "Fin de juego, el Robot cae al agua.";
                        menu = 'N';
                        break;
                    }
                } else if (posicionRobot == 1)
                {
                    // Hago el movimiento en todos los casos
                    tablero[1][1] = "       ";
                    tablero[1][2] = "Robot  ";
                    posicionRobot = 2;

                    // El robot solo puede acceder a la posicion 2 moviendo la barca

                    finJuego = "Fin de juego, el Robot cae al agua.";
                    menu = 'N';
                    break;
                    
                } else if (posicionRobot == 2)
                {
                    tablero[1][2] = "       ";
                    tablero[1][3] = "Robot  ";

                    posicionRobot = 3;
                    orientacionRobot = "Izquierda";
                }
                } else // Cuando la orientacion cambia a la izquierda <-
                {
                if(posicionRobot == 3) // Que haya espacio para el se comprueba con los otros personajes
                {   
                    // Hago el movimiento en todos lo casos
                    tablero[1][2] = "Robot  ";
                    tablero[1][3] = "       ";
                    posicionRobot = 2; 

                    // Pasa cuando no hay barco en el que pueda saltar
                    if(posicionBarca != 2)
                    {
                        finJuego = "Fin de juego, el Robot cae al agua.";
                        menu = 'N';
                        break;                        
                    } 

                } else if (posicionRobot == 2) 
                {
                    tablero[1][2] = "Robot  ";
                    tablero[1][3] = "       ";
                    posicionRobot = 1;

                     // El robot solo puede acceder a la posicion 1 moviendo la barca

                    finJuego = "Fin de juego, el Robot cae al agua.";
                    menu = 'N';
                    break;
                
                } else if (posicionRobot == 1)
                {
                    tablero[1][0] = "Robot  ";
                    tablero[1][1] = "       ";
                    posicionRobot = 0; 
                    orientacionRobot = "Derecha"; // Al llegar a la orilla cambia de orientacion                   
                }
            }
            
            menu = 'S';
            system("clear");
            break;
        // Zorro
        case 'Z':
        case 'z':
            if (orientacionZorro == "Derecha")
            {
                if (posicionZorro == 0)
                {
                    if(posicionConejo != 1 && posicionLechuga != 1) //Solo se mueve si hay espacio en el barco para el.
                    {
                        tablero[2][0] = "       ";
                        tablero[2][1] = "Zorro  ";
                        posicionZorro = 1;

                        // Valido que la barca este en la orilla
                        if (posicionBarca != 1)
                        {
                            finJuego = "Fin de juego, el Zorro cae al agua.";
                            menu = 'N';
                            break;
                        } 
                    }
                } else if (posicionZorro == 1)
                {
                        tablero[2][1] = "      ";
                        tablero[2][2] = "Zorro ";
                        posicionZorro = 2; 

                    // Para el zorro solo es posible ir a la posicion 2 con la asigacion del barco 

                        finJuego = "Fin de juego, el Zorro cae al agua.";
                        menu = 'N';
                        break;                        
                } else if (posicionZorro == 2)
                {
                    tablero[2][2] = "       ";
                    tablero[2][3] = "Zorro  ";
                    posicionZorro = 3;

                    orientacionZorro = "Izquierda";
                }
            } else { // Caso orientacion izquierda
                if (posicionZorro == 3)
                {
                    if(posicionConejo != 2 && posicionLechuga != 2) //Solo se mueve si hay espacio en el barco para el.
                    {
                        tablero[2][2] = "Zorro  ";
                        tablero[2][3] = "       ";
                        posicionZorro = 2;

                        // Valido que la barca este en la orilla
                        if (posicionBarca != 2)
                        {
                            finJuego = "Fin de juego, el Zorro cae al agua.";
                            menu = 'N';
                            break;
                        } 
                    }
                } else if (posicionZorro == 2)
                {
                        tablero[2][1] = "Zorro  ";
                        tablero[2][2] = "       ";
                        posicionZorro = 1; 

                    // Para el zorro solo es posible ir a la posicion 1 con la asigacion del barco 

                        finJuego = "Fin de juego, el Zorro cae al agua.";
                        menu = 'N';
                        break;                        
                } else if (posicionZorro == 1)
                {
                    tablero[2][0] = "Zorro  ";
                    tablero[2][1] = "       ";
                    posicionZorro = 0;

                    orientacionZorro = "Derecha";
                }
            }
            menu = 'S';
            system("clear");
            break;

        // Conejo
        case 'C':
        case 'c':

            if (orientacionConejo == "Derecha")
            {
                if (posicionConejo == 0)
                {
                    if(posicionZorro != 1 && posicionLechuga != 1) //Solo se mueve si hay espacio en el barco para el.
                    {
                        tablero[3][0] = "       ";
                        tablero[3][1] = "Conejo ";
                        posicionConejo = 1;

                        // Valido que la barca este en la orilla
                        if (posicionBarca != 1)
                        {
                            finJuego = "Fin de juego, el Conejo cae al agua.";
                            menu = 'N';
                            break;
                        } 
                    }
                } else if (posicionConejo == 1)
                {
                        tablero[3][1] = "       ";
                        tablero[3][2] = "Conejo ";
                        posicionConejo = 2; 

                    // Para el Conejo solo es posible ir a la posicion 2 con la asigacion del barco 

                        finJuego = "Fin de juego, el Conejo cae al agua.";
                        menu = 'N';
                        break;                        
                } else if (posicionConejo == 2)
                {
                    tablero[3][2] = "       ";
                    tablero[3][3] = "Conejo ";
                    posicionConejo = 3;

                    orientacionConejo = "Izquierda";
                }
            } else { //  Caso orientacion izquierda
                if (posicionConejo == 3)
                {
                    if(posicionZorro != 2 && posicionLechuga != 2) //Solo se mueve si hay espacio en el barco para el.
                    {
                        tablero[3][2] = "Conejo ";
                        tablero[3][3] = "       ";
                        posicionConejo = 2;

                        // Valido que la barca este en la orilla
                        if (posicionBarca != 2)
                        {
                            finJuego = "Fin de juego, el Conejo cae al agua.";
                            menu = 'N';
                            break;
                        } 
                    }
                } else if (posicionConejo == 2)
                {
                        tablero[3][1] = "Conejo ";
                        tablero[3][2] = "       ";
                        posicionConejo = 1; 

                    // Para el Conejo solo es posible ir a la posicion 1 con la asigacion del barco 

                        finJuego = "Fin de juego, el Conejo cae al agua.";
                        menu = 'N';
                        break;                        
                } else if (posicionConejo == 1)
                {
                    tablero[3][0] = "Conejo ";
                    tablero[3][1] = "       ";
                    posicionConejo = 0;

                    orientacionConejo = "Derecha";
                }
            }
            menu = 'S';
            system("clear");
            break;

        // Lechuga
        case 'L':
        case 'l':
            if (orientacionLechuga == "Derecha")
            {
                if (posicionLechuga == 0)
                {
                    if(posicionConejo != 1 && posicionZorro != 1) // Solo se mueve si hay espacio en el barco para el.
                    {
                        tablero[4][0] = "       ";
                        tablero[4][1] = "Lechuga";
                        posicionLechuga = 1;

                        // Valido que la barca este en la orilla
                        if (posicionBarca != 1)
                        {
                            finJuego = "Fin de juego, el Lechuga cae al agua.";
                            menu = 'N';
                            break;
                        } 
                    }
                } else if (posicionLechuga == 1)
                {
                        tablero[4][1] = "      ";
                        tablero[4][2] = "Lechuga";
                        posicionLechuga = 2; 

                    //Para el Lechuga solo es posible ir a la posicion 2 con la asigacion del barco 

                        finJuego = "Fin de juego, el Lechuga cae al agua.";
                        menu = 'N';
                        break;                        
                } else if (posicionLechuga == 2)
                {
                    tablero[4][2] = "       ";
                    tablero[4][3] = "Lechuga";
                    posicionLechuga = 3;

                    orientacionLechuga = "Izquierda";
                }
            } else { //  Caso orientacion izquierda
                if (posicionLechuga == 3)
                {
                    if(posicionLechuga != 2 && posicionLechuga != 2) //Solo se mueve si hay espacio en el barco para el.
                    {
                        tablero[4][2] = "Lechuga";
                        tablero[4][3] = "       ";
                        posicionLechuga = 2;

                        // Valido que la barca este en la orilla
                        if (posicionBarca != 2)
                        {
                            finJuego = "Fin de juego, el Lechuga cae al agua.";
                            menu = 'N';
                            break;
                        } 
                    }
                } else if (posicionLechuga == 2)
                {
                        tablero[4][1] = "Lechuga";
                        tablero[4][2] = "       ";
                        posicionLechuga = 1; 

                    //Para el Lechuga solo es posible ir a la posicion 1 con la asigacion del barco 

                        finJuego = "Fin de juego, el Lechuga cae al agua.";
                        menu = 'N';
                        break;                        
                } else if (posicionLechuga == 1)
                {
                    tablero[4][0] = "Lechuga";
                    tablero[4][1] = "       ";
                    posicionLechuga = 0;

                    orientacionLechuga = "Derecha";
                }
            }

            menu = 'S';
            system("clear");
            break;

        default:
            menu = 'S';
            system("clear");
        }
    } while (menu == 'S' || menu == 's');

    system("clear");

    // Imprimo la tablero
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << tablero[i][j] << "\t\t";
        }
        cout << "\n";
    }

    cout << "---------------------------------------------" << endl;
    cout << "Estado del Juego: " << finJuego << endl;
}
