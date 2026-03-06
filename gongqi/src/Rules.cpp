#include "Rules.h"

#include "Count.h"
#include "Geometry.h"

namespace gongqi {

bool isLinkedToOwn(const State& state, Color color, int x, int y) {
  for (const auto& d : DIR8) {
    int nx = x + d.x;
    int ny = y + d.y;
    if (inBoard(nx, ny) && state.board[nx][ny] == color) return true;
  }
  return false;
}

bool isLegalMove(const State& state, Color color, int x, int y, bool useBomb) {
  if (state.terminal) return false;
  if (!inBoard(x, y)) return false;
  if (state.board[x][y] != EMPTY) return false;
  if (useBomb && state.BC[color] == 0) return false;

  if (!state.omdpTriggered) {
    if (isBaseline(color, x, y)) return true;
    return isLinkedToOwn(state, color, x, y);
  }
  return isLinkedToOwn(state, color, x, y);
}

bool checkWinAfterMove(const State& state, Color color, int x, int y, bool useBomb,
                       const std::vector<RemovedPiece>& removed) {
  Color enemy = opposite(color);

  if (isBaseline(enemy, x, y)) return true;

  if (!useBomb) {
    for (const auto& r : removed) {
      if (r.c == enemy && isBaseline(enemy, r.x, r.y)) return true;
    }
  }

  if (countPieces(state, enemy) == 0) {
    // Avoid empty-board instant win: zero-enemy-piece win requires this move to have removed enemy stones.
    for (const auto& r : removed) {
      if (r.c == enemy) return true;
    }
    return false;
  }

  return false;
}

} // namespace gongqi
