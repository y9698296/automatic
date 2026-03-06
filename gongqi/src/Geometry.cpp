#include "Geometry.h"

namespace gongqi {

bool isBaseline(Color color, int, int y) {
  return (color == BLACK && y == 0) || (color == WHITE && y == N - 1);
}

bool inEnemyTriLine(Color color, int, int y) {
  if (color == BLACK) return (N - 1 - y) <= 3;
  return y <= 3;
}

bool crossedMidline(Color color, int, int y) {
  int mid = (N - 1) / 2;
  if (color == BLACK) return y >= mid;
  return y <= mid;
}

} // namespace gongqi
