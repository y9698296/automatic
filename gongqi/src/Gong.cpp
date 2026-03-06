#include "Gong.h"

namespace gongqi {

std::vector<RemovedPiece> gongEat(State& state, Color color, int x, int y) {
  Color enemy = opposite(color);
  std::vector<RemovedPiece> removed;
  for (const auto& d : DIR4) {
    int nx = x + d.x;
    int ny = y + d.y;
    if (inBoard(nx, ny) && state.board[nx][ny] == enemy) {
      state.board[nx][ny] = EMPTY;
      removed.push_back({nx, ny, enemy});
    }
  }
  return removed;
}

} // namespace gongqi
