#include "GameMap.h"
#include<iostream>
#include<fstream>

using namespace std;

GameMap::GameMap() //se define las variables y lo que hace la clase cuando se define
{
    //ctor
    PlayerCell =NULL;   // mi puntero inicialmente apunta a un espacio vacio
    LoadMapFromFile(); //se convierte mi Map.txt en arreglo asignandolo a cell[][]
    isGAmeOver = false ; //se comienza falso y se convertira verdadero cuando el jugador encuentre el tesoro.
}

void GameMap::Draw() // dibujara el mapa actualizado
{
    for(int i = 0; i< 20 ; i++)
    {
       for(int p=0 ; p<70;p++)
       {    //imprimira lo que hay en ese espacio de ese arreglo bidimensional
           cout <<cells[i][p].id;  // acuerdate que el arreglo cell es un arreglo de clases (ver el GameMap.h) y acuerdade lo que hizo LoadMapFromFile() de asignarle lo que hay en Map.txt a cells.
       }
       cout << endl ; // salto de linea para escribir tal como esta en Map.txt
    }
}

bool GameMap::SetPlayerCell(int PlayerX , int PlayerY) // funcion que retorna True si se ubica en un espacio cero y false si se encuentra en un espacio 1
{    //cells[i][j],isBlocked es una funcion que retorna verdadero si el id de la clase cell[i][j] es 1 y falso si es cero
    if(cells[PlayerY][PlayerX].IsBlocked() == false)  // si cell[][].isBlocked es 0 esto verdadero y si es 1 esto es falso (acuerdate que en LoadMapFromFile() cada Cell[i][j] tiene un .id diferente
    {
        if(cells[PlayerY][PlayerX].id == '$') // si el jugador esta ubicado en '$' entonces dibuja que gano y pon isGAmeOver igual a true para finalizar el juego
        {
            DrawVictory(); //dibuja el mapa
            isGAmeOver = true ; // como el jugador encontro el tesoro entonces el juego se acabo
            return true;
        }

        //la actualizacion de mi movimiento , justo ntes de moverme , debo poner cero en el lugar que me encuentreo
          if(PlayerCell != NULL ) // si mi apuntador apunta a un lugar diferente de nulo entonce hazlo que
        {
            PlayerCell->id = 0; //en lo que este apuntando PlayerCell , su id lo transforma a cero ( en este caso donde esta
        }

        PlayerCell = &cells[PlayerY][PlayerX]; // da la direccion de mi ubicacion actual
        PlayerCell->id = '3' ; // a mi ubicacion actual lo pone el simbolo '3' para indicar que mi apuntador(y mi jugador se encuentra alli)
        return true;
    }

    else
    {
        return false;
    }


   // cout << "Las coordenadas del jugador estan en: "<< PlayerX<<"," <<PlayerY ;
}

void GameMap::DrawIntro() // dibujara el intro bien chingon de dragones
{
        string line; // esto sirve para leer linea por linea el archivo "Intro.txt"
        ifstream MyFile("Intro.txt"); // Aca  abre el arvhivo que se va a leer  y tipear (esto es de la libreria fstream.


       if(MyFile.is_open()) // solo si esta abierto el archivo (osea si funciono el comando de arriba)
        {
            while(getline(MyFile,line)) // lectura linea por linea , esto es verdadero hasta que mi archivo se quede sin lineas por leer
            {
                cout << line << endl;
            }
            cin >> line ; // Este me sirve para parar el programa y decirle al jugador si desea continuar
        }
        else
        {
            cout <<"FATAL ERROR: INTRO COULD NOT BE LOADED " << endl ; // esto se imprimira si el comando ifstream Myfile("In....txt") no se pudo abrir
        }
}


void GameMap::DrawVictory() //dibujara el intro bien chingon con cofres
{
        string line; // me servira para leer linea por linea el archivo "Victory.txt".
        ifstream MyFile("Victory.txt");// Aca  abre el arvhivo que se va a leer  y tipear (esto es de la libreria fstream.


       if(MyFile.is_open())// solo si esta abierto el archivo (osea si funciono el comando de arriba)
        {
            while(getline(MyFile,line))// lectura linea por linea , esto es verdadero hasta que mi archivo se quede sin lineas por leer
            {
                cout << line << endl;
            }
            cin >> line ; // Este me sirve para parar el programa y decirle al jugador si desea continuar
        }
        else
        {
            cout <<"FATAL ERROR:VICTORY COULD NOT BE LOADED!  :c" << endl ;// esto se imprimira si el comando ifstream Myfile("Vic....txt") no se pudo abrir
        }
}





void GameMap::LoadMapFromFile() // convierte mi Map.txt en un arreglo ,que lo asigna a cells(arreglo de clases)
{
        /* ofstream FileCreated("Map.txt"); //crea el archivo */


        string line;// me servira para leer linea por linea el archivo "Map.txt".
        int row=0; // me servira para correr filas
        ifstream MyFile("Map.txt");// Aca  abre el arvhivo que se va a leer  y tipear (esto es de la libreria fstream.

        if(MyFile.is_open())// solo si esta abierto el archivo (osea si funciono el comando de arriba)
        {
            while(getline(MyFile,line)) // lectura linea por linea , esto es verdadero hasta que mi archivo se quede sin lineas por leer
            {
                for(int p=0; p<line.length() ; p++)
                {
                    if(line[p] == '0') // la linea es un string y toma la fila de Map.txt ( asi que line[p] es la columna p correspondiente a esa fila
                    cells[row][p].id = 0; // reitero // acuerdate que el arreglo cell es un arreglo de clases (ver el GameMap.h) // aca se reemplaza '0' por 0(nulo)
                    else
                        {
                            cells[row][p].id = line[p]; // se asigna lo que hay en la  ubicacion de mi Map.txt en el arreglo de clases cells
                        }
                                    }
                row++; //Se suma uno para poder seguir asignando, de acuerdo a la forma de lectura de Map.txt , a cells[row][p]
            }
        }
        else
        {
            cout <<"FATAL ERROR: MAP FILE COULD NOT BE LOADED " << endl ;// esto se imprimira si el comando ifstream Myfile("Map.txt") no se pudo abrir
        }
}
