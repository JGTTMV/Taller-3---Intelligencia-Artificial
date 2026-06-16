// Angel Leyton y Josefina Valdebenito 
#include "Jugador.h"

#include <iostream>
#include <cstdlib>

using namespace std;

pair<int, int> jugador_humano(const State& st)
{
    int x;
    int y;

    while (true)
    {
        cout << "Ingrese X Y: ";
        cin >> x >> y;

        if (x < 0 || x >= st.get_cols() ||
            y < 0 || y >= st.get_rows())
        {
            cout << "Fuera de rango" << endl;
            continue;
        }

        if (!st.is_valid_move(x, y))
        {
            cout << "Casilla ocupada" << endl;
            continue;
        }

        return { x, y };
    }
}

pair<int, int> jugador_aleatorio(const State& st)
{
    while (true)
    {
        int x = rand() % st.get_cols();
        int y = rand() % st.get_rows();

        if (st.is_valid_move(x, y))
        {
            return { x, y };
        }
    }
}