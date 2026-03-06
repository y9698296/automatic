#pragma once

#include <vector>

#include "State.h"
#include "Types.h"

namespace gongqi {

std::vector<RemovedPiece> bombCrossEat(State& state, Color color, int x, int y);

} // namespace gongqi
