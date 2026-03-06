#include "test_framework.h"

#include "../include/KTBC.h"

using namespace gongqi;

TEST(test_ktbc_same_pos_5) {
  State s;
  for (int i = 0; i < 5; ++i) updateKTBC(s, BLACK, 1, 1);
  ASSERT_EQ(s.BC[BLACK], 1);
}
