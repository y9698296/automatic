#include "Zobrist.h"

namespace gongqi {

uint64_t hashState(const State& state) {
  uint64_t h = 1469598103934665603ull;
  for (int x = 0; x < N; ++x) {
    for (int y = 0; y < N; ++y) {
      h ^= static_cast<uint64_t>(state.board[x][y] + 31 * x + 131 * y);
      h *= 1099511628211ull;
    }
  }
  h ^= static_cast<uint64_t>(state.side);
  return h;
}

} // namespace gongqi
