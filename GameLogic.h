// Angel Leyton y Josefina Valdebenito 
#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include "State.h"

int check_winner(const State& st);
bool juego_terminado(const State& st);
int heuristica(const State& st, int jugadorIA);

#endif