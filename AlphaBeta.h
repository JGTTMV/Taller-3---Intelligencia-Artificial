// Angel Leyton y Josefina Valdebenito 

#ifndef ALPHABETA_H
#define ALPHABETA_H

#include "State.h"

#include <utility>

int alphabeta(State st, int jugadorIA, int alpha, int beta, int profundidad, int profundidadMax, int& nodosVisitados, int& profundidadMaxAlcanzada);

std::pair<int, int> jugador_alphabeta(const State& st, int profundidadMax, int& nodosVisitados, int& profundidadMaxAlcanzada);

#endif