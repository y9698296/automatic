#pragma once

#include "Types.h"

namespace gongqi {

struct Move {
  Pos pos;
  bool useBomb = false;
  bool operator<(const Move& o) const {
    if (pos.x != o.pos.x) return pos.x < o.pos.x;
    if (pos.y != o.pos.y) return pos.y < o.pos.y;
    return useBomb < o.useBomb;
  }
  bool operator==(const Move& o) const {
    return pos.x == o.pos.x && pos.y == o.pos.y && useBomb == o.useBomb;
  }
};

} // namespace gongqi
