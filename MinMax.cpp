// Angel Leyton y Josefina Valdebenito 

#include "MinMax.h"
#include "GameLogic.h"

#include <utility>

int minmax(State st, int jugadorIA, int profundidad, int profundidadMax, int& nodosVisitados, int& profundidadMaxAlcanzada)
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

    bool maximiza = (st.get_to_move() == jugadorIA); //Determina si el jugador actual es el jugador IA (maximizador) o el oponente (minimizador)

    if (maximiza) //Si el jugador actual es el maximizador, busca el valor maximo entre los movimientos posibles
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

                    //Llama recursivamente a minmax para evaluar el estado hijo, aumentando la profundidad
                    int valor = minmax(hijo, jugadorIA, profundidad + 1, profundidadMax, nodosVisitados, profundidadMaxAlcanzada);

                    if (valor > mejor) //Actualiza el mejor valor encontrado para el maximizador
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

                    int valor = minmax(hijo, jugadorIA, profundidad + 1, profundidadMax, nodosVisitados, profundidadMaxAlcanzada);

                    //Actualiza el mejor valor encontrado para el minimizador, buscando el valor minimo entre los movimientos posibles
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

std::pair<int, int> jugador_minmax(const State& st, int profundidadMax, int& nodosVisitados, int& profundidadMaxAlcanzada)
{
    int mejorValor = -2;
    int mejorX = -1;
    int mejorY = -1;

    int jugadorIA = st.get_to_move();
    nodosVisitados = 0;
    profundidadMaxAlcanzada = 0;

    for (int y = 0; y < st.get_rows(); ++y)
    {
        for (int x = 0; x < st.get_cols(); ++x)
        {
            if (st.is_valid_move(x, y))
            {
                State hijo = st;

                hijo.make_move(x, y); //Genera el estado hijo aplicando el movimiento

                int valor = minmax(hijo, jugadorIA, 1, profundidadMax, nodosVisitados, profundidadMaxAlcanzada);

                //Actualiza el mejor movimiento encontrado para el jugador IA, buscando el valor maximo entre los movimientos posibles
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