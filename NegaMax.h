// Angel Leyton y Josefina Valdebenito 
#ifndef NEGAMAX_H
#define NEGAMAX_H

#include "State.h"

#include <utility>

int negamax(State st, int color, int profundidad, int profundidadMax);

std::pair<int,int> jugador_negamax(const State& st, int profundidadMax);

#endif