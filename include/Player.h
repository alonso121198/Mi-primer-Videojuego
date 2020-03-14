#ifndef PLAYER_H // con esto comienza
#define PLAYER_H


class Player
{
    public:
        Player();

        void CallInput(); //defines las funciones
        void ResetToSafePosition();
        int x,y; //variables globales que me indicaran la ubicacion del jugador
        int lastX, lastY; //variables globales que me indicaran la ubicacion dejada antes de moverse(este me servira por si hay paredes)

    protected:

    private:
};

#endif // PLAYER_H con esto termina
