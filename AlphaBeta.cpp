// Angel Leyton y Josefina Valdebenito 

#include "AlphaBeta.h"
#include "GameLogic.h"

int alphabeta(State st, int jugadorIA, int alpha, int beta, int profundidad, int profundidadMax, int& nodosVisitados, int& profundidadMaxAlcanzada)
{
    nodosVisitados++;
    if (profundidad > profundidadMaxAlcanzada)
    {
        profundidadMaxAlcanzada = profundidad;
    }

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
        int mejor = -1000;

        for (int y = 0; y < st.get_rows(); y++)
        {
            for (int x = 0; x < st.get_cols(); x++)
            {
                if (st.is_valid_move(x,y))
                {
                    State hijo = st;

                    hijo.make_move(x,y);

                    int valor = alphabeta(hijo, jugadorIA, alpha, beta, profundidad + 1, profundidadMax, nodosVisitados, profundidadMaxAlcanzada);

                    if (valor > mejor)
                    {
                        mejor = valor;
                    }

                    if (mejor > alpha)
                    {
                        alpha = mejor;
                    }

                    if (beta <= alpha)
                    {
                        return mejor;
                    }
                }
            }
        }

        return mejor;
    }
    else
    {
        int mejor = 1000;

        for (int y = 0; y < st.get_rows(); y++)
        {
            for (int x = 0; x < st.get_cols(); x++)
            {
                if (st.is_valid_move(x,y))
                {
                    State hijo = st;

                    hijo.make_move(x,y);

                    int valor = alphabeta(hijo, jugadorIA, alpha, beta, profundidad + 1, profundidadMax, nodosVisitados, profundidadMaxAlcanzada);

                    if (valor < mejor)
                    {
                        mejor = valor;
                    }

                    if (mejor < beta)
                    {
                        beta = mejor;
                    }

                    if (beta <= alpha)
                    {
                        return mejor;
                    }
                }
            }
        }

        return mejor;
    }
}

std::pair<int,int> jugador_alphabeta(const State& st, int profundidadMax, int& nodosVisitados, int& profundidadMaxAlcanzada)
{
    int mejorValor = -1000;
    int mejorX = -1;
    int mejorY = -1;

    int jugadorIA = st.get_to_move();
    nodosVisitados = 0;
    profundidadMaxAlcanzada = 0;

    for (int y = 0; y < st.get_rows(); y++)
    {
        for (int x = 0; x < st.get_cols(); x++)
        {
            if (st.is_valid_move(x,y))
            {
                State hijo = st;

                hijo.make_move(x,y);

                int valor = alphabeta(hijo, jugadorIA, -1000, 1000, 1, profundidadMax, nodosVisitados, profundidadMaxAlcanzada);

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