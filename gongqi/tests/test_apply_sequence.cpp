#include "test_framework.h"

#include "../include/Apply.h"
#include "../include/Rules.h"

using namespace gongqi;

TEST(test_apply_sequence_bomb_baseline_not_win) {
  State s;
  Workspace ws;
  s.side = BLACK;
  s.BC[BLACK] = 1;
  s.board[0][0] = WHITE; // white baseline stone
  s.board[1][0] = BLACK; // continuous non-empty so bomb ray can hit
  s.board[1][18] = WHITE; // keep enemy alive on baseline so duan/count does not end game
  auto u = applyMove(s, ws, Move{{2,0}, true});
  (void)u;
  ASSERT_EQ(s.board[0][0], EMPTY);
  ASSERT_TRUE(!s.terminal); // bomb-cross removing baseline guard does not directly win
}

TEST(test_no_legal_move_after_terminal) {
  State s;
  s.terminal = true;
  ASSERT_TRUE(!isLegalMove(s, BLACK, 0, 0, false));
}

TEST(test_no_instant_win_on_empty_opening) {
  State s;
  Workspace ws;
  s.side = BLACK;
  auto u = applyMove(s, ws, Move{{0,0}, false});
  (void)u;
  ASSERT_TRUE(!s.terminal);
}
