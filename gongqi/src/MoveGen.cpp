#include "MoveGen.h"

#include "Rules.h"

namespace gongqi {

std::vector<Move> genMoves(const State& state) {
  std::vector<Move> moves;
  for (int x = 0; x < N; ++x) {
    for (int y = 0; y < N; ++y) {
      if (isLegalMove(state, state.side, x, y, false)) moves.push_back({{x, y}, false});
      if (state.BC[state.side] == 1 && isLegalMove(state, state.side, x, y, true)) {
        moves.push_back({{x, y}, true});
      }
    }
  }
  return moves;
}

} // namespace gongqi
