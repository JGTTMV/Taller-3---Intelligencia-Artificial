// Angel Leyton y Josefina Valdebenito 
#ifndef JUGADOR_H
#define JUGADOR_H

#include "State.h"

#include <utility>

std::pair<int, int> jugador_humano(const State& st);

std::pair<int, int> jugador_aleatorio(const State& st);

#endif