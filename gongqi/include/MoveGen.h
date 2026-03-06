#pragma once

#include <vector>

#include "Move.h"
#include "State.h"

namespace gongqi {

std::vector<Move> genMoves(const State& state);

} // namespace gongqi
