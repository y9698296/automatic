#include "test_framework.h"

#include "../include/STBC.h"

using namespace gongqi;

TEST(test_stbc_trigger_0_to_1) {
  State s;
  s.prevTriCount[BLACK] = 0;
  s.board[0][18] = BLACK; // in black enemy tri-line
  updateSTBC(s, BLACK);
  ASSERT_EQ(s.BC[BLACK], 1);
  ASSERT_TRUE(s.prevTriCount[BLACK] > 0);
}
