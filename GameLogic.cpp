// Angel Leyton y Josefina Valdebenito 
#include "GameLogic.h"

int check_winner(const State& st)
{
    int filas = st.get_rows();
    int columnas = st.get_cols();
    int k = st.get_k();
    int heuristica(const State& st, int jugadorIA);

    int dx[4] = {1, 0, 1, 1};
    int dy[4] = {0, 1, 1, -1};

    for (int y = 0; y < filas; y++)
    {
        for (int x = 0; x < columnas; x++)
        {
            int jugador = st.get_square(x, y);

            if (jugador == 0)
            {
                continue;
            }

            for (int dir = 0; dir < 4; dir++)
            {
                int contador = 1;

                int nx = x;
                int ny = y;

                for (int paso = 1; paso < k; paso++)
                {
                    nx += dx[dir];
                    ny += dy[dir];

                    if (nx < 0 || nx >= columnas ||
                        ny < 0 || ny >= filas)
                    {
                        break;
                    }

                    if (st.get_square(nx, ny) != jugador)
                    {
                        break;
                    }

                    contador++;
                }

                if (contador >= k)
                {
                    return jugador;
                }
            }
        }
    }

    return 0;
}

bool juego_terminado(const State& st)
{
    return st.full() || check_winner(st) != 0;
}

int heuristica(const State& st, int jugadorIA)
{
    int puntos = 0;

    for (int y = 0; y < st.get_rows(); y++)
    {
        for (int x = 0; x < st.get_cols(); x++)
        {
            if (st.get_square(x, y) == jugadorIA)
            {
                puntos += 10;
            }
            else if (st.get_square(x, y) == -jugadorIA)
            {
                puntos -= 10;
            }
        }
    }

    return puntos;
}