#include "STBC.h"

#include "Count.h"

namespace gongqi {

void updateSTBC(State& state, Color color) {
  int triCount = countTriPieces(state, color);
  if (state.prevTriCount[color] == 0 && triCount > 0) {
    state.BC[color] = 1;
  }
  state.prevTriCount[color] = triCount;
}

} // namespace gongqi
