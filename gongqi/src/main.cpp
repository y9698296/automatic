#include <iostream>

#include "MCTS.h"

int main() {
  gongqi::State s;
  auto m = gongqi::runMCTS(s, 10);
  std::cout << "best move: (" << m.pos.x << "," << m.pos.y << ") bomb=" << m.useBomb << "\n";
  return 0;
}
