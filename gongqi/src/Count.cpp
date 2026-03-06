#include "Count.h"

#include "Geometry.h"

namespace gongqi {

int countPieces(const State& state, Color color) {
  int cnt = 0;
  for (int x = 0; x < N; ++x) {
    for (int y = 0; y < N; ++y) {
      if (state.board[x][y] == color) ++cnt;
    }
  }
  return cnt;
}

int countTriPieces(const State& state, Color color) {
  int cnt = 0;
  for (int x = 0; x < N; ++x) {
    for (int y = 0; y < N; ++y) {
      if (state.board[x][y] == color && inEnemyTriLine(color, x, y)) ++cnt;
    }
  }
  return cnt;
}

} // namespace gongqi
