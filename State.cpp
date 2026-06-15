// Angel Leyton y Josefina Valdebenito 
#include "State.h"

#include <cassert>
#include <iostream>
#include <sstream>

using namespace std;

const array<char, 3> State::DISP = {{ 'o', '-', 'x' }};

State::State(int columnas_, int filas_, int k_)
{
    columnas = columnas_;
    filas = filas_;
    k = k_;

    sq.resize(filas);

    for (int y = 0; y < filas; y++)
    {
        sq[y].resize(columnas, 0);
    }

    to_move = P1;
    filled = 0;
}

bool State::full() const
{
    return filled >= filas * columnas;
}

void State::print() const
{
    for (int y = 0; y < filas; ++y)
    {
        for (int x = 0; x < columnas; ++x)
        {
            cout << DISP[sq[y][x] + 1];
        }

        cout << endl;
    }

    cout << DISP[to_move + 1]
         << " (" << filled << ")"
         << endl;
}

bool State::make_move(int x, int y)
{
    assert(x >= 0 && x < columnas &&
           y >= 0 && y < filas);

    auto& c = sq[y][x];

    if (c)
    {
        return false;
    }

    c = to_move;

    to_move = -to_move;

    ++filled;

    return true;
}

int State::get_to_move() const
{
    return to_move;
}

int State::get_square(int x, int y) const
{
    return sq[y][x];
}

bool State::is_valid_move(int x, int y) const
{
    return sq[y][x] == 0;
}

int State::get_rows() const
{
    return filas;
}

int State::get_cols() const
{
    return columnas;
}

int State::get_k() const
{
    return k;
}