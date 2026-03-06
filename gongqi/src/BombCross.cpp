#include "BombCross.h"

namespace gongqi {

std::vector<RemovedPiece> bombCrossEat(State& state, Color color, int x, int y) {
  Color enemy = opposite(color);
  std::vector<RemovedPiece> removed;

  for (const auto& d : DIR4) {
    int nx = x + d.x;
    int ny = y + d.y;
    while (inBoard(nx, ny)) {
      if (state.board[nx][ny] == EMPTY) break;
      if (state.board[nx][ny] == enemy) {
        state.board[nx][ny] = EMPTY;
        removed.push_back({nx, ny, enemy});
      }
      nx += d.x;
      ny += d.y;
    }
  }
  return removed;
}

} // namespace gongqi
