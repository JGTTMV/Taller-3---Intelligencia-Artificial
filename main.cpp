// Angel Leyton y Josefina Valdebenito 

#include "State.h"
#include "GameLogic.h"
#include "Jugador.h"
#include "MinMax.h"
#include "AlphaBeta.h"
#include "NegaMax.h"

#include <iostream>
#include <ctime>
#include <chrono>
#include <vector>
#include <iomanip>

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

    cout << "1. Humano" << endl;
    cout << "2. Random" << endl;
    cout << "3. MinMax" << endl;
    cout << "4. AlphaBeta" << endl;
    cout << "5. NegaMax" << endl;
    cout << "Seleccione el jugador para O: ";
    cin >> tipoJugadorO;

    cout << endl;

    cout << "1. Humano" << endl;
    cout << "2. Random" << endl;
    cout << "3. MinMax" << endl;
    cout << "4. AlphaBeta" << endl;
    cout << "5. NegaMax" << endl;
    cout << "Seleccione el jugador para X: ";
    cin >> tipoJugadorX;

    cout << endl;

    //Vectores para el calculo de estadisticas de tiempo
    vector<double> tiempos_P1; //Jugador X
    vector<double> tiempos_P2; //Jugador O

    vector<int> nodos_P1;
    vector<int> nodos_P2;
    vector<int> profundidad_P1;
    vector<int> profundidad_P2;

    while (!st.full() && check_winner(st) == 0)
    {
        st.print();

        pair<int, int> movimiento;
        chrono::high_resolution_clock::time_point inicio, fin;
        chrono::duration<double, milli> duracion;
        int nodosVisitados = 0;
        int profundidadMaxAlcanzada = 0;

        //turno P1
        if (st.get_to_move() == State::P1)
        {
            cout << "Turno jugador "
                 << State::DISP[State::P1 + 1]
                 << endl;

            inicio = chrono::high_resolution_clock::now();

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
                movimiento = jugador_minmax(st, profundidadMax, nodosVisitados, profundidadMaxAlcanzada);
            }
            else if (tipoJugadorX == 4)
            {
                movimiento = jugador_alphabeta(st, profundidadMax, nodosVisitados, profundidadMaxAlcanzada);
            }
            else if (tipoJugadorX == 5)
            {
                movimiento = jugador_negamax(st, profundidadMax, nodosVisitados, profundidadMaxAlcanzada);
            }

            fin = chrono::high_resolution_clock::now();
            duracion = fin - inicio;
            tiempos_P1.push_back(duracion.count());
            nodos_P1.push_back(nodosVisitados);
            profundidad_P1.push_back(profundidadMaxAlcanzada);
        }
        //turno P2
        else
        {
            cout << "Turno jugador "
                 << State::DISP[State::P2 + 1]
                 << endl;

            inicio = chrono::high_resolution_clock::now();

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
                movimiento = jugador_minmax(st, profundidadMax, nodosVisitados, profundidadMaxAlcanzada);
            }
            else if (tipoJugadorO == 4)
            {
                movimiento = jugador_alphabeta(st, profundidadMax, nodosVisitados, profundidadMaxAlcanzada);
            }
            else if (tipoJugadorO == 5)
            {
                movimiento = jugador_negamax(st, profundidadMax, nodosVisitados, profundidadMaxAlcanzada);
            }

            fin = chrono::high_resolution_clock::now();
            duracion = fin - inicio;
            tiempos_P2.push_back(duracion.count());
            nodos_P2.push_back(nodosVisitados);
            profundidad_P2.push_back(profundidadMaxAlcanzada);
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

    //Imprime las estadisticas de tiempo para cada jugador
    cout << "\n--- ESTADISTICAS DE PELEA ---\n" << endl;

    if (!tiempos_P1.empty())
    {
        double suma_P1 = 0;
        for (double t : tiempos_P1) suma_P1 += t;
        double promedio_P1 = suma_P1 / tiempos_P1.size();
        cout << "Jugador " << State::DISP[State::P1 + 1] << " (X):" << endl;
        cout << "  Numero de turnos: " << tiempos_P1.size() << endl;
        cout << fixed << setprecision(2);
        cout << "  Tiempo promedio por turno: " << promedio_P1 << " ms" << endl;
        cout << "  Tiempo total: " << suma_P1 << " ms" << endl;
    }

    if (!tiempos_P2.empty())
    {
        double suma_P2 = 0;
        for (double t : tiempos_P2) suma_P2 += t;
        double promedio_P2 = suma_P2 / tiempos_P2.size();
        cout << "Jugador " << State::DISP[State::P2 + 1] << " (O):" << endl;
        cout << "  Numero de turnos: " << tiempos_P2.size() << endl;
        cout << fixed << setprecision(2);
        cout << "  Tiempo promedio por turno: " << promedio_P2 << " ms" << endl;
        cout << "  Tiempo total: " << suma_P2 << " ms" << endl;

        int totalNodosP2 = 0;
        int maxProfP2 = 0;
        for (int n : nodos_P2) totalNodosP2 += n;
        for (int p : profundidad_P2) if (p > maxProfP2) maxProfP2 = p;
        cout << endl << "Nodos visitados totales: " << totalNodosP2 << endl;
        cout << "Profundidad maxima alcanzada: " << maxProfP2 << endl;
    }

    return 0;
}