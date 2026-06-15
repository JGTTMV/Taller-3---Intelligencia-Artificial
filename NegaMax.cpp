// Angel Leyton y Josefina Valdebenito 
#include "NegaMax.h"
#include "GameLogic.h"

#include "NegaMax.h"
#include "GameLogic.h"

int negamax(State st, int color, int profundidad, int profundidadMax, int jugadorIA)
{
    if (juego_terminado(st))
    {
        int ganador = check_winner(st);

        if (ganador == 0)
            return 0;

        return (ganador == jugadorIA) ? color * 1 : color * -1;
    }

    if (profundidad >= profundidadMax)
    {
        return color * heuristica(st, jugadorIA);
    }

    int mejor = -100000;

    for (int y = 0; y < st.get_rows(); y++)
    {
        for (int x = 0; x < st.get_cols(); x++)
        {
            if (st.is_valid_move(x, y))
            {
                State hijo = st;
                hijo.make_move(x, y);

                int valor = -negamax(hijo, -color, profundidad + 1, profundidadMax, jugadorIA);

                if (valor > mejor)
                    mejor = valor;
            }
        }
    }

    return mejor;
}
std::pair<int,int> jugador_negamax(const State& st, int profundidadMax)
{
    int jugadorIA = st.get_to_move();
    int mejorValor = -100000;
    int mejorX = -1;
    int mejorY = -1;

    int color = 1;

    for (int y = 0; y < st.get_rows(); y++)
    {
        for (int x = 0; x < st.get_cols(); x++)
        {
            if (st.is_valid_move(x, y))
            {
                State hijo = st;
                hijo.make_move(x, y);

                int valor = -negamax(hijo, -color, 1, profundidadMax, jugadorIA);

                if (valor > mejorValor)
                {
                    mejorValor = valor;
                    mejorX = x;
                    mejorY = y;
                }
            }
        }
    }

    return {mejorX, mejorY};
}