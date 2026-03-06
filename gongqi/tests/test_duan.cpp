#include "test_framework.h"

#include "../include/Duan.h"

using namespace gongqi;

TEST(test_duan_disconnect) {
  State s;
  Workspace ws;
  s.board[0][18] = WHITE;   // baseline-connected seed
  s.board[1][17] = WHITE;   // connected
  s.board[10][10] = WHITE;  // disconnected
  auto removed = duanCut(s, ws, WHITE);
  ASSERT_EQ(removed.size(), 1u);
  ASSERT_EQ(s.board[10][10], EMPTY);
  ASSERT_EQ(s.board[1][17], WHITE);
}
