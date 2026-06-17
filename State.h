// Angel Leyton y Josefina Valdebenito 

#ifndef STATE_H
#define STATE_H

#include <vector>
#include <string>
#include <array>

struct InputException { }; //Excepcion para entradas invalidas

class State
{
public:

    enum Players
    {
        P2 = -1,
        P1 = 1
    };

    static const std::array<char, 3> DISP; //Array para imprimir el tablero

    State(int columnas, int filas, int k);

    bool full() const;
    void print() const;

    //Funciones para los movimientos

    bool make_move(int x, int y);

    int get_to_move() const;

    int get_square(int x, int y) const;

    bool is_valid_move(int x, int y) const;

    int get_rows() const;
    int get_cols() const;
    int get_k() const;

private:

    int to_move;

    int filas;
    int columnas;
    int k;

    int filled;

    std::vector<std::vector<signed char>> sq; //Tablero representado como una matriz de enteros (0, 1, -1)
};

#endif