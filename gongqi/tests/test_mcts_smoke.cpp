#include "test_framework.h"

#include "../include/MCTS.h"
#include "../include/Rules.h"

using namespace gongqi;

TEST(test_mcts_smoke_legal) {
  State s;
  Move m = runMCTS(s, 20);
  ASSERT_TRUE(isLegalMove(s, s.side, m.pos.x, m.pos.y, m.useBomb));
}

TEST(test_mcts_iteration_validation) {
  State s;
  bool threw = false;
  try {
    (void)runMCTS(s, 0);
  } catch (const std::runtime_error&) {
    threw = true;
  }
  ASSERT_TRUE(threw);
}

TEST(test_mcts_terminal_state_validation) {
  State s;
  s.terminal = true;
  s.winner = BLACK;
  bool threw = false;
  try {
    (void)runMCTS(s, 10);
  } catch (const std::runtime_error&) {
    threw = true;
  }
  ASSERT_TRUE(threw);
}
