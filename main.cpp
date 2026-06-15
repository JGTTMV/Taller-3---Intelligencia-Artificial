// Angel Leyton y Josefina Valdebenito 

#include "State.h"
#include "GameLogic.h"
#include "Jugador.h"
#include "MinMax.h"
#include "AlphaBeta.h"
#include "NegaMax.h"

#include <iostream>
#include <ctime>

using namespace std;

int main()
{
    srand(time(0));

    int columnas;
    int filas;
    int k;

    cout << "Columnas: ";
    cin >> columnas;

    cout << "Filas: ";
    cin >> filas;

    cout << "K para ganar: ";
    cin >> k;

    State st(columnas, filas, k);

    int profundidadMax = 5;
    int tipoJugadorO;
    int tipoJugadorX;

    cout << endl;

    cout << "Seleccione el jugador para O" << endl;
    cout << "1. Humano" << endl;
    cout << "2. Random" << endl;
    cout << "3. MinMax" << endl;
    cout << "4. AlphaBeta" << endl;
    cout << "5. NegaMax" << endl;
    cin >> tipoJugadorO;

    cout << endl;

    cout << "Seleccione el jugador para X" << endl;
    cout << "1. Humano" << endl;
    cout << "2. Random" << endl;
    cout << "3. MinMax" << endl;
    cout << "4. AlphaBeta" << endl;
    cout << "5. NegaMax" << endl;
    cin >> tipoJugadorX;

    cout << endl;

    while (!st.full() && check_winner(st) == 0)
    {
        st.print();

        pair<int, int> movimiento;

        // turno P1
        if (st.get_to_move() == State::P1)
        {
            cout << "Turno jugador "
                 << State::DISP[State::P1 + 1]
                 << endl;

            if (tipoJugadorX == 1)
            {
                movimiento = jugador_humano(st);
            }
            else if(tipoJugadorX == 2)
            {
                movimiento = jugador_aleatorio(st);
            }
            else if(tipoJugadorX == 3)
            {
                movimiento = jugador_minmax(st, profundidadMax);
            }
            else if (tipoJugadorX == 4)
            {
                movimiento = jugador_alphabeta(st, profundidadMax);
            }
            else if (tipoJugadorX == 5)
            {
                movimiento = jugador_negamax(st, profundidadMax);
            }
        }
        // turno P2
        else
        {
            cout << "Turno jugador "
                 << State::DISP[State::P2 + 1]
                 << endl;

            if (tipoJugadorO == 1)
            {
                movimiento = jugador_humano(st);
            }
            else if(tipoJugadorO == 2)
            {
                movimiento = jugador_aleatorio(st);
            }
            else if(tipoJugadorO == 3)
            {
                movimiento = jugador_minmax(st, profundidadMax);
            }
            else if (tipoJugadorO == 4)
            {
                movimiento = jugador_alphabeta(st, profundidadMax);
            }
            else if (tipoJugadorO == 5)
            {
                movimiento = jugador_negamax(st, profundidadMax);
            }
        }

        st.make_move(movimiento.first, movimiento.second);

        cout << endl;
    }

    st.print();

    int ganador = check_winner(st);

    if (ganador != 0)
    {
        cout << "Gana "
             << State::DISP[ganador + 1]
             << endl;
    }
    else
    {
        cout << "Empate" << endl;
    }

    return 0;
}