#include "test_framework.h"

#include "../include/Gong.h"

using namespace gongqi;

TEST(test_gong_basic) {
  State s;
  s.board[5][5] = BLACK;
  s.board[6][5] = WHITE;
  auto removed = gongEat(s, BLACK, 5, 5);
  ASSERT_EQ(removed.size(), 1u);
  ASSERT_EQ(s.board[6][5], EMPTY);
}
