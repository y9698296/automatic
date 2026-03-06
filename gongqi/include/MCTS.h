#pragma once

#include <map>
#include <memory>
#include <set>
#include <vector>

#include "Move.h"
#include "State.h"

namespace gongqi {

struct Node {
  Node* parent = nullptr;
  std::map<Move, std::unique_ptr<Node>> children;
  std::vector<Move> untriedMoves;
  int N = 0;
  double W = 0.0;
  std::map<Move, int> N_rave;
  std::map<Move, double> W_rave;
  std::optional<Move> moveFromParent;
  Color playerToMove = BLACK;
};

Move runMCTS(const State& rootState, int iterations, int rolloutMaxPlies = 64);

} // namespace gongqi
