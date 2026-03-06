#pragma once

#include "Move.h"
#include "State.h"
#include "Undo.h"
#include "Workspace.h"

namespace gongqi {

Undo applyMove(State& state, Workspace& ws, const Move& move);
void undoMove(State& state, const Undo& undo);

} // namespace gongqi
