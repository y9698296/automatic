#include "test_framework.h"

#include "../include/BombCross.h"

using namespace gongqi;

TEST(test_bombcross_stop_on_empty) {
  State s;
  s.board[5][5] = BLACK;
  s.board[6][5] = BLACK;  // own piece should not block
  s.board[7][5] = WHITE;  // eaten
  s.board[8][5] = EMPTY;  // stop here
  s.board[9][5] = WHITE;  // must survive
  auto removed = bombCrossEat(s, BLACK, 5, 5);
  ASSERT_EQ(removed.size(), 1u);
  ASSERT_EQ(s.board[7][5], EMPTY);
  ASSERT_EQ(s.board[9][5], WHITE);
}
