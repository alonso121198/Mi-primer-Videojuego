#include "MapCell.h"

MapCell::MapCell() //esto se ejecutara cuando se defina las cosas
{
    id = 0; // toda clase comienza con MapCell.id igual a cero ,pero xuando se invoque LoadMapFromFile() se cambiara cada espacio en 1 y 0
}

bool MapCell::IsBlocked() //  este me servira para que mi jugador(mi apuntador) no transpase las paredes)
{
    if(id =='1') //si hay un bloque ( si hay un 1 ) retorna 1
    {
        return true;
    }
    else //si no hay bloque (si hay un 0) retorna 0
    {
        return false;
    }
}
