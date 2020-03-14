#ifndef MAPCELL_H //con esto comienza
#define MAPCELL_H


class MapCell
{
    public:
        MapCell();
        char id;

        bool IsBlocked(); //funcion para no dejar a mi jugador que transpase las paredes

    protected:

    private:
};

#endif // MAPCELL_H con esto termina
