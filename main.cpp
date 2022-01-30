#include <string>
#include <iostream>
using namespace std;

int main() {
 
string matriz[5][4];
  char menu = 'S';
  char opcion = 'S';
  int pasoBarca = 1;
  int pasoRobot = 1;
  int pasoZorro = 1;
  int pasoConejo = 1;
  int pasoLechuga = 1;
  string finJuego = "";
  
  matriz[0][0] = "IZQUIER";
  matriz[1][0] = "Robot";
  matriz[2][0] = "Zorro";
  matriz[3][0] = "Conejo";
  matriz[4][0] = "Lechuga";

  matriz[0][1] = "BARCA";
  matriz[1][1] = "";
  matriz[2][1] = "";
  matriz[3][1] = "";
  matriz[4][1] = "";

  matriz[0][2] = "";
  matriz[1][2] = "";
  matriz[2][2] = "";
  matriz[3][2] = "";
  matriz[4][2] = "";

  matriz[0][3] = "DERECHA";
  matriz[1][3] = "";
  matriz[2][3] = "";
  matriz[3][3] = "";
  matriz[4][3] = "";
  
  system("clear");

  do{

    for(int i=0; i<5 ; i++)
    {
      for(int j=0; j<4; j++){
        cout << matriz[i][j] << "\t\t";
      }
      cout << "\n";
    }

    cout << "---------------------------------------------" << endl;
    cout << "*** Jugar ***" << endl;
    cout << "B - Barca se mueve a la orilla " << endl;
    cout << "R - El Robot salta a la barca" << endl;
    cout << "Z - El Zorro salta a la barca" << endl;
    cout << "C - El Conejo salta a la barca" << endl;
    cout << "L - El Lechuga salta a la barca" << endl;
    cout << "Digite su opción:";
    cin >> opcion;

    switch(opcion){
      // Barca
      case 'B':case 'b':
        if(pasoBarca == 1){
          matriz[0][1] = "";
          matriz[0][2] = "BARCA";

          if(matriz[1][1] == "\tRobot" && matriz[3][1] == "\tConejo"){
            matriz[1][1] = "";
            matriz[1][2] = "\tRobot";
            matriz[3][1] = "";
            matriz[3][2] = "\tConejo";
          }
        }

        if(pasoBarca == 2){
          matriz[0][2] = "BARCA";
          

          if(matriz[1][2] == "\tRobot" && matriz[3][2] == "\tConejo"){
            matriz[1][2] = "";
            matriz[1][3] = "\tRobot";
            matriz[3][2] = "";
            matriz[3][3] = "\tConejo";

            pasoRobot = 4;
          }
        }

        if(pasoBarca == 3){
          matriz[0][1] = "BARCA";
          matriz[0][2] = "";
          
          if(matriz[1][2] == "\tRobot"){
            matriz[1][1] = "\tRobot";
            matriz[1][2] = "";
          }
        }

        if(pasoBarca == 4){
          matriz[0][1] = "";
          matriz[0][2] = "BARCA";

          if(matriz[1][1] == "\tRobot" && matriz[2][1] == "\tZorro"){
            matriz[1][1] = "";
            matriz[1][2] = "\tRobot";
            matriz[2][1] = "";
            matriz[2][2] = "\tZorro";
          }

        }

        if(pasoBarca == 5){
          matriz[0][2] = "BARCA";
          
          if(matriz[1][2] == "\tRobot" && matriz[2][2] == "\tZorro"){
            matriz[1][2] = "";
            matriz[1][3] = "\tRobot";
            matriz[2][2] = "";
            matriz[2][3] = "\tZorro";

            pasoRobot = 4;
            pasoConejo = 4;
          }
        }

        if(pasoBarca == 6){
          matriz[0][1] = "BARCA";
          matriz[0][2] = "";
          
          if(matriz[1][2] == "\tRobot"){
            matriz[1][1] = "\tRobot";
            matriz[1][2] = "";
            matriz[3][1] = "\tConejo";
            matriz[3][2] = "";
          }

          pasoConejo = 5;
        }

        if(pasoBarca == 7){
          matriz[0][1] = "";
          matriz[0][2] = "BARCA";

          if(matriz[1][1] == "\tRobot" && matriz[4][1] == "\tLechuga"){
            matriz[1][1] = "";
            matriz[1][2] = "\tRobot";
            matriz[4][1] = "";
            matriz[4][2] = "\tLechuga";
          }

        }

        if(pasoBarca == 8){
          matriz[0][2] = "BARCA";
          
          if(matriz[1][2] == "\tRobot" && matriz[4][2] == "\tLechuga"){
            matriz[1][2] = "";
            matriz[1][3] = "\tRobot";
            matriz[4][2] = "";
            matriz[4][3] = "\tLechuga";
          }

          pasoRobot = 4;
        }

        if(pasoBarca == 9){
          matriz[0][1] = "BARCA";
          matriz[0][2] = "";
          
          if(matriz[1][2] == "\tRobot"){
            matriz[1][1] = "\tRobot";
            matriz[1][2] = "";
          }

          pasoConejo = 1;
        }

        if(pasoBarca == 10){
          matriz[0][1] = "";
          matriz[0][2] = "BARCA";

          if(matriz[1][1] == "\tRobot" && matriz[3][1] == "\tConejo"){
            matriz[1][1] = "";
            matriz[1][2] = "\tRobot";
            matriz[3][1] = "";
            matriz[3][2] = "\tConejo";
          }
        }

        if(pasoBarca == 11){
          matriz[0][2] = "BARCA";
          
          if(matriz[1][2] == "\tRobot" && matriz[3][2] == "\tConejo"){
            matriz[1][2] = "";
            matriz[1][3] = "\tRobot";
            matriz[3][2] = "";
            matriz[3][3] = "\tConejo";
          }

          if(matriz[1][3] == "\tRobot" && matriz[2][3] == "\tZorro" && matriz[3][3] == "\tConejo" && matriz[4][3] == "\tLechuga"){
            finJuego = "GANASTE";
          }
          
          menu = 'N';
          break;
        }

        pasoBarca += 1;
        menu = 'S';
        system("clear");
        
      break;
      // Robot
      case 'R': case 'r':
        if(pasoRobot == 1){
          matriz[1][0] = "";
          matriz[1][1] = "\tRobot";

          // Valido que la barca este en la orilla
          if(matriz[0][1] == ""){
            finJuego = "Fin de juego, el Robot cae al agua.";
            menu = 'N';
            break;
          }

          if(matriz[2][0] == "Zorro" && matriz[3][0] == "Conejo"){
          finJuego = "Fin de juego, el Zorro se come al Conejo.";
          menu = 'N';
          break;
        }
        
          if(matriz[3][0] == "Conejo" && matriz[4][0] == "Lechuga"){
            finJuego = "Fin de juego, el Conejo se come la Lechuga.";
            menu = 'N';
            break;
          }
        }

        if(pasoRobot == 2){
          matriz[1][1] = "";
          matriz[1][2] = "\tRobot";

          if(matriz[0][2] == ""){
            finJuego = "Fin de juego, el Robot cae al agua.";
            menu = 'N';
            break;
          }
        }

        if(pasoRobot == 3){
          matriz[1][2] = "";
          matriz[1][3] = "\tRobot";

          if(matriz[0][3] == ""){
            finJuego = "Fin de juego, el Robot cae al agua.";
            menu = 'N';
            break;
          }
        }

        if(pasoRobot == 4){
          matriz[1][2] = "\tRobot";
          matriz[1][3] = "";

          if(matriz[0][2] == ""){
            finJuego = "Fin de juego, el Robot cae al agua.";
            menu = 'N';
            break;
          }
        }

        pasoRobot += 1;
        menu = 'S';
        system("clear");
      break;
      // Zorro
      case 'Z': case 'z':
        if(pasoZorro == 1){
          matriz[2][0] = "";
          matriz[2][1] = "\tZorro";

          // Valido que la barca este en la orilla
          if(matriz[0][1] == ""){
            finJuego = "Fin de juego, el Zorro cae al agua.";
            menu = 'N';
            break;
          }
          // Si Conejo está en la misma columna con Lechuga
          // y no está el robot
          if(matriz[1][0] == "" && matriz[3][0] == "Conejo" && matriz[4][0] == "Lechuga"){
            finJuego = "El Conejo se come la Lechuga";
            menu = 'N';
            break;
          }

          if(matriz[2][1] == "\tZorro" && matriz[3][1] == "\tConejo"){
            finJuego = "El Zorro se come al conejo";
            menu = 'N';
            break;
          }
        }

        if(pasoZorro == 2){
          matriz[2][1] = "";
          matriz[2][2] = "\tZorro";

          // Valido que la barca este en la orilla
          if(matriz[0][2] == ""){
            finJuego = "Fin de juego, el Zorro cae al agua.";
            menu = 'N';
            break;
          }
        }

        if(pasoZorro == 3){
          matriz[2][2] = "";
          matriz[2][3] = "\tZorro";

          // Valido que la barca este en la orilla
          if(matriz[0][3] == ""){
            finJuego = "Fin de juego, el Zorro cae al agua.";
            menu = 'N';
            break;
          }
        }

        
        pasoZorro += 1;
        menu = 'S';
        system("clear");
      break;
      // Conejo 
      case 'C':case 'c':
        if(pasoConejo == 1){
          matriz[3][0] = "";
          matriz[3][1] = "\tConejo";

          // Valido que la barca este en la orilla
          if(matriz[0][1] == ""){
            finJuego = "Fin de juego, el Conejo cae al agua.";
            menu = 'N';
            break;
          }

          if(matriz[2][1] == "\tZorro" && matriz[3][1] == "\tConejo"){
            finJuego = "El Zorro se come al conejo";
            menu = 'N';
            break;
          }

        }

        if(pasoConejo == 2){
          matriz[3][1] = "";
          matriz[3][2] = "\tConejo";

          // Valido que la barca este en la orilla
          if(matriz[0][2] == ""){
            finJuego = "Fin de juego, el Conejo cae al agua.";
            menu = 'N';
            break;
          }

        }

        if(pasoConejo == 3){
          matriz[3][2] = "";
          matriz[3][3] = "\tConejo";

          // Valido que la barca este en la orilla
          if(matriz[0][3] == ""){
            finJuego = "Fin de juego, el Conejo cae al agua.";
            menu = 'N';
            break;
          }

        }

        if(pasoConejo == 4){
          matriz[3][2] = "\tConejo";
          matriz[3][3] = "";

          if(matriz[0][3] == ""){
            finJuego = "Fin de juego, el Robot cae al agua.";
            menu = 'N';
            break;
          }
        }

        if(pasoConejo == 5){
          matriz[3][0] = "\tConejo";
          matriz[3][1] = "";

          if(matriz[0][1] == ""){
            finJuego = "Fin de juego, el Robot cae al agua.";
            menu = 'N';
            break;
          }
        }

        pasoConejo += 1;
        menu = 'S';
        system("clear");
      break;
      // Lechuga
      case 'L':case 'l':
        if(pasoLechuga == 1){
          matriz[4][0] = "";
          matriz[4][1] = "\tLechuga";

          // Valido que la barca este en la orilla
          if(matriz[0][1] == ""){
            finJuego = "Fin de juego, la Lechuga cae al agua.";
            menu = 'N';
            break;
          }
        }

        if(pasoLechuga == 2){
          matriz[4][1] = "";
          matriz[4][2] = "\tLechuga";

          // Valido que la barca este en la orilla
          if(matriz[0][2] == ""){
            finJuego = "Fin de juego, la Lechuga cae al agua.";
            menu = 'N';
            break;
          }

        }

        if(pasoLechuga == 3){
          matriz[4][2] = "";
          matriz[4][3] = "\tLechuga";

          // Valido que la barca este en la orilla
          if(matriz[0][3] == ""){
            finJuego = "Fin de juego, la Lechuga cae al agua.";
            menu = 'N';
            break;
          }

        }

        pasoLechuga += 1;
        menu = 'S';
        system("clear");
      break;

      default: 
         menu = 'S';
         system("clear");
    }
  }while(menu == 'S' || menu == 's');

  system("clear");

  // Imprimo la matriz
  for(int i=0; i<5 ; i++)
    {
      for(int j=0; j<4; j++){
        cout << matriz[i][j] << "\t\t";
      }
      cout << "\n";
    }
  
  cout << "---------------------------------------------" << endl;
  cout << "Estado del Juego: " << finJuego << endl; 

}
