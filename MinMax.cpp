// Angel Leyton y Josefina Valdebenito 
#include "MinMax.h"
#include "GameLogic.h"

#include <utility>

int minmax(State st,int jugadorIA,int profundidad,int profundidadMax)
{
    if (juego_terminado(st))
    {
        int ganador = check_winner(st);

        if (ganador == jugadorIA)
        {
            return 1;
        }

        if (ganador == 0)
        {
            return 0;
        }

        return -1;
    }

    if (profundidad >= profundidadMax)
    {
        return heuristica(st, jugadorIA);
    }

    bool maximiza = (st.get_to_move() == jugadorIA);

    if (maximiza)
    {
        int mejor = -2;

        for (int y = 0; y < st.get_rows(); ++y)
        {
            for (int x = 0; x < st.get_cols(); ++x)
            {
                if (st.is_valid_move(x, y))
                {
                    State hijo = st;

                    hijo.make_move(x, y);

                    int valor = minmax(hijo,jugadorIA,profundidad + 1,profundidadMax);

                    if (valor > mejor)
                    {
                        mejor = valor;
                    }
                }
            }
        }

        return mejor;
    }
    else
    {
        int mejor = 2;

        for (int y = 0; y < st.get_rows(); ++y)
        {
            for (int x = 0; x < st.get_cols(); ++x)
            {
                if (st.is_valid_move(x, y))
                {
                    State hijo = st;

                    hijo.make_move(x, y);

                    int valor = minmax(hijo,jugadorIA,profundidad + 1,profundidadMax);

                    if (valor < mejor)
                    {
                        mejor = valor;
                    }
                }
            }
        }

        return mejor;
    }
}

std::pair<int, int> jugador_minmax(const State& st,int profundidadMax)
{
    int mejorValor = -2;
    int mejorX = -1;
    int mejorY = -1;

    int jugadorIA = st.get_to_move();

    for (int y = 0; y < st.get_rows(); ++y)
    {
        for (int x = 0; x < st.get_cols(); ++x)
        {
            if (st.is_valid_move(x, y))
            {
                State hijo = st;

                hijo.make_move(x, y);

                int valor = minmax(hijo,jugadorIA,1,profundidadMax);

                if (valor > mejorValor)
                {
                    mejorValor = valor;
                    mejorX = x;
                    mejorY = y;
                }
            }
        }
    }

    return { mejorX, mejorY };
}