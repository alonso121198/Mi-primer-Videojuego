#ifndef GAMEMAP_H //con esto comienza el archivo
#define GAMEMAP_H

#include "MapCell.h"
class GameMap  //definimos cuales son nuestras herramientas sin especificar lo que realmente hacen , donde se especifica lo que hacen nuestras extensiones es en el archivo cpp del mismo nombre
{
    public:
        GameMap(); // para definir nuestras variables y lo que hara la clase internamente ni bien se defina la clase ((ver archivo .cpp)

        MapCell* PlayerCell; //define el apuntador Player«ell , este es el que correra ( apuntador que apunta a clase Mapcell)
        MapCell cells[20][70] ; //define la matriz que tiene el mismo orden de lo que escribi en el archivo  Map.txt y (es de clase Mapcell)

        void DrawIntro(); //el constructor que dibujara el intro.
        void DrawVictory(); // el constructor que dibujara la parte final cuando el jugador gane la partida.
        void Draw(); // el constructor para el dibujo del mapa

        //Esta funcion tiene las coordenadas de player y actualiza el mapa.
        bool SetPlayerCell(int PlayerX, int PlayerY);

        bool isGAmeOver = false; // Este servira para que la GameMap.isGAmeover comience siendo falso , y cuando el jugador encuentre el tesoro esto se volvera verdadero

    protected:
        void LoadMapFromFile(); //funcion que asigna lo que hay en mi mapa a mi arreglo de clases cells
    private:
};

#endif // GAMEMAP_H
