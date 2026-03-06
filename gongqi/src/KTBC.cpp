#include "KTBC.h"

namespace gongqi {

void updateKTBC(State& state, Color color, int x, int y) {
  Pos cur{x, y};
  if (state.ktbc.lastPos[color].has_value() && state.ktbc.lastPos[color].value() == cur) {
    state.ktbc.streak[color] += 1;
  } else {
    state.ktbc.lastPos[color] = cur;
    state.ktbc.streak[color] = 1;
  }

  if (state.ktbc.streak[color] >= 5) state.BC[color] = 1;
}

} // namespace gongqi
