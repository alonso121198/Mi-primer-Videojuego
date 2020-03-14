#include <iostream>
#include <stdlib.h>   // esta libreria la usare para el limpiado de pantalla
#include "Player.h"
#include "GameMap.h"
#include "GameMap.h"
using namespace std;

char comienzo ; // esta variable sera util por mientras para iniciar partida
string finalizar ; // este string me servira para finalizar mi juego
int main()
{

    GameMap Map;  //define como a map un tipo de clase GameMap
    Player Hero;    // heroe es un tipo de clase Player

    cout << "Presiona cualquier tecla para comenzar"; // aca comienza todo mi juego
    cin >> comienzo ;

    Map.DrawIntro(); // dibuja el intro bien chingon

    //acuerdate que dentro de Map.DrawIntro hay un cin que para el programa

    system("CLS");  // borra lo escrito hasta ahora

    cout << "ENCUENTRA EL TESORO EN ESTE LABERINTO Y SERAS VICTORIOSO" << endl;

    Map.Draw();  // dibuja el mapa para que el jugador sepa a lo que va a resolver

    while(Map.isGAmeOver==false) // comienza con falso hasta que el jugador encuentre el simbolo '$'
    {

            cout << "Introduce el comando de movimiento 'w' 'a' 's' 'd': "<< endl ;
            //Aqui es el loop de nuestro juego

            Hero.CallInput(); //lamada al jugador para que presione una tecla (esta funcion no retorna nada , sino que modifica las variables globales "x,y" dentro de la funcion
            system("CLS");  // borra lo escrito hasta ahora

        //lee el estado actual del heroe , sus coordenas "x,y"
        if(Map.SetPlayerCell(Hero.x,Hero.y))//Actualizado de informacion heroe a Mapa (si esta en un espacio donde hay un cero se dibuja el mapa actualizado)
        {                                   //                                        (si esta en un espacio donde hay un 1 no se actualiza el mapa)
            if(Map.isGAmeOver == true) break  ; //este es para que si el juego finalizo , ya no se dibuje el mapa(quita esto y te daras cuenta por que pongo esto)
            Map.Draw();//Aqui dibujamos el mapa
        }
        else
        {

            Hero.ResetToSafePosition();
            Map.Draw();



        }

    }




    do
    {
        cout << "Escribe 'exit' para salir: "; //para que el jugador salga del juego cuando pueda
        cin >> finalizar ;
    }while(finalizar != "exit");

    return 0;
}
