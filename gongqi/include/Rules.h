#pragma once

#include <vector>

#include "State.h"
#include "Types.h"

namespace gongqi {

bool isLinkedToOwn(const State& state, Color color, int x, int y);
bool isLegalMove(const State& state, Color color, int x, int y, bool useBomb);
bool checkWinAfterMove(const State& state, Color color, int x, int y, bool useBomb,
                       const std::vector<RemovedPiece>& removed);

} // namespace gongqi
