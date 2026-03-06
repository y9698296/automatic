#include "Apply.h"

#include <stdexcept>

#include "BombCross.h"
#include "Duan.h"
#include "Geometry.h"
#include "Gong.h"
#include "KTBC.h"
#include "Rules.h"
#include "STBC.h"

namespace gongqi {

Undo applyMove(State& state, Workspace& ws, const Move& move) {
  Color color = state.side;
  Color enemy = opposite(color);

  if (!isLegalMove(state, color, move.pos.x, move.pos.y, move.useBomb)) {
    throw std::runtime_error("illegal move");
  }

  Undo u{state};

  state.board[move.pos.x][move.pos.y] = color;

  if (crossedMidline(color, move.pos.x, move.pos.y)) {
    state.omdpTriggered = true;
  }

  std::vector<RemovedPiece> removed;
  if (move.useBomb) {
    removed = bombCrossEat(state, color, move.pos.x, move.pos.y);
    state.BC[color] = 0;
  } else {
    removed = gongEat(state, color, move.pos.x, move.pos.y);
  }

  bool ateEnemy = false;
  for (const auto& r : removed) {
    if (r.c == enemy) {
      ateEnemy = true;
      break;
    }
  }
  if (ateEnemy) {
    auto duanRemoved = duanCut(state, ws, enemy);
    removed.insert(removed.end(), duanRemoved.begin(), duanRemoved.end());
  }

  if (checkWinAfterMove(state, color, move.pos.x, move.pos.y, move.useBomb, removed)) {
    state.terminal = true;
    state.winner = color;
  }

  updateKTBC(state, color, move.pos.x, move.pos.y);
  updateSTBC(state, color);

  state.side = enemy;
  return u;
}

void undoMove(State& state, const Undo& undo) { state = undo.snapshot; }

} // namespace gongqi
