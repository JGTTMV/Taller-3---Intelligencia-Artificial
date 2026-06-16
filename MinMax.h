// Angel Leyton y Josefina Valdebenito 
#ifndef MINMAX_H
#define MINMAX_H

#include "State.h"

#include <utility>

int minmax(State st, int jugadorIA, int profundidad, int profundidadMax, int& nodosVisitados, int& profundidadMaxAlcanzada);

std::pair<int, int> jugador_minmax(const State& st, int profundidadMax, int& nodosVisitados, int& profundidadMaxAlcanzada);

#endif