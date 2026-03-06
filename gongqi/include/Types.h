#pragma once

#include <array>
#include <cstdint>
#include <optional>
#include <vector>

namespace gongqi {

constexpr int N = 19;

enum Color : int {
  EMPTY = 0,
  BLACK = 1,
  WHITE = 2,
};

struct Pos {
  int x;
  int y;
  bool operator==(const Pos& o) const { return x == o.x && y == o.y; }
  bool operator<(const Pos& o) const { return x == o.x ? y < o.y : x < o.x; }
};

struct RemovedPiece {
  int x;
  int y;
  Color c;
};

inline bool inBoard(int x, int y) { return x >= 0 && x < N && y >= 0 && y < N; }
inline Color opposite(Color c) { return c == BLACK ? WHITE : BLACK; }

inline const std::array<Pos, 8> DIR8 = {{{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}}};
inline const std::array<Pos, 4> DIR4 = {{{1,0},{-1,0},{0,1},{0,-1}}};

} // namespace gongqi
