#include "Player.h"
#include <iostream>//se incluye para que el cin y cout funcione

using namespace std;

Player::Player() // de la clase player voy a definir el construcotr ,esto se ejecutara ni bien mi funcion comience
{
    x=1; //condiciones iniciales de mi jugador
    y=1;
}

void Player::CallInput() //escribes lo que hace las funciones
{
    char UserInput = ' '; //asigna espacio vacio por mientras
    cin >> UserInput ;  //espera la lectura del usuario

    switch(UserInput) //depende de lo que reciba (entrada por el jugador) hara lo siguiente
    {
    case 'w' :
        lastY = y; //se mantiene las coordenadas anterioes por si encuentra una pared
        y--;

        break;
     case 's' :
         lastY = y;//se mantiene las coordenadas anterioes por si encuentra una pared
         y++;

        break;
     case 'd' :
         lastX = x;//se mantiene las coordenadas anterioes por si encuentra una pared
         x++;

        break;
     case 'a' :
         lastX = x;//se mantiene las coordenadas anterioes por si encuentra una pared
         x--;

        break;
    }

}

void Player::ResetToSafePosition() //funcion que resetea el estado , es decir , si el jugador se mueve para un lugar donde hay bloques , entonces asigna las coordenadas al mismo lugar
{
    x = lastX;
    y = lastY;
}



