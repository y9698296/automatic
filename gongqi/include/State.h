#pragma once

#include <array>
#include <optional>

#include "Types.h"

namespace gongqi {

struct KTBCData {
  std::array<std::optional<Pos>, 3> lastPos;
  std::array<int, 3> streak{0, 0, 0};
};

struct State {
  std::array<std::array<Color, N>, N> board{};
  Color side = BLACK;
  bool omdpTriggered = false;
  std::array<int, 3> BC{0, 0, 0};
  std::array<int, 3> prevTriCount{0, 0, 0};
  KTBCData ktbc;
  bool terminal = false;
  Color winner = EMPTY;
};

} // namespace gongqi
