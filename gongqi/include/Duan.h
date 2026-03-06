#pragma once

#include <vector>

#include "State.h"
#include "Types.h"
#include "Workspace.h"

namespace gongqi {

std::vector<RemovedPiece> duanCut(State& state, Workspace& ws, Color enemyColor);

} // namespace gongqi
