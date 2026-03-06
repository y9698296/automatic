#include "MCTS.h"

#include <algorithm>
#include <cmath>
#include <random>
#include <stdexcept>

#include "Apply.h"
#include "MoveGen.h"

namespace gongqi {
namespace {

double nodeValue(const Node* n) { return n->N == 0 ? 0.0 : n->W / n->N; }

double raveValue(const Node* n, const Move& m) {
  auto itN = n->N_rave.find(m);
  if (itN == n->N_rave.end() || itN->second == 0) return 0.0;
  return n->W_rave.at(m) / itN->second;
}

double beta(const Node* n, const Move& m) {
  auto it = n->N_rave.find(m);
  if (it == n->N_rave.end()) return 0.0;
  double nr = static_cast<double>(it->second);
  double nn = static_cast<double>(n->N);
  return nr / (nn + nr + 4.0 * nn * nr + 1e-9);
}

Node* selectChild(Node* node, double c) {
  Node* best = nullptr;
  double bestScore = -1e18;
  for (auto& kv : node->children) {
    const Move& m = kv.first;
    Node* child = kv.second.get();
    if (child->N == 0) return child;
    double b = beta(node, m);
    double q = nodeValue(child);
    double qr = raveValue(node, m);
    double u = c * std::sqrt(std::log(std::max(1, node->N)) / child->N);
    double score = (1.0 - b) * q + b * qr + u;
    if (score > bestScore) {
      bestScore = score;
      best = child;
    }
  }
  return best;
}

int terminalValue(const State& state, Color rootSide) {
  if (!state.terminal) return 0;
  return state.winner == rootSide ? 1 : -1;
}

}  // namespace

Move runMCTS(const State& rootState, int iterations, int rolloutMaxPlies) {
  if (rootState.terminal) throw std::runtime_error("cannot search terminal state");
  if (iterations <= 0) throw std::runtime_error("iterations must be positive");

  auto root = std::make_unique<Node>();
  root->playerToMove = rootState.side;
  root->untriedMoves = genMoves(rootState);
  if (root->untriedMoves.empty()) throw std::runtime_error("no legal moves");

  std::mt19937 rng(42);

  for (int it = 0; it < iterations; ++it) {
    State state = rootState;
    Workspace ws;
    std::vector<Node*> path{root.get()};

    Node* node = root.get();
    while (node->untriedMoves.empty() && !node->children.empty() && !state.terminal) {
      node = selectChild(node, 1.4);
      applyMove(state, ws, *node->moveFromParent);
      path.push_back(node);
    }

    if (!state.terminal) {
      if (!node->untriedMoves.empty()) {
        std::uniform_int_distribution<size_t> pick(0, node->untriedMoves.size() - 1);
        size_t idx = pick(rng);
        Move m = node->untriedMoves[idx];
        node->untriedMoves.erase(node->untriedMoves.begin() + idx);
        applyMove(state, ws, m);
        auto child = std::make_unique<Node>();
        child->parent = node;
        child->moveFromParent = m;
        child->playerToMove = state.side;
        child->untriedMoves = genMoves(state);
        Node* childPtr = child.get();
        node->children[m] = std::move(child);
        node = childPtr;
        path.push_back(node);
      }
    }

    std::set<Move> rolloutMoves;
    for (int ply = 0; ply < rolloutMaxPlies && !state.terminal; ++ply) {
      auto moves = genMoves(state);
      if (moves.empty()) break;
      std::uniform_int_distribution<size_t> pick(0, moves.size() - 1);
      Move m = moves[pick(rng)];
      rolloutMoves.insert(m);
      applyMove(state, ws, m);
    }

    int result = terminalValue(state, rootState.side);

    for (auto itp = path.rbegin(); itp != path.rend(); ++itp) {
      Node* n = *itp;
      n->N += 1;
      double v = (n->playerToMove == rootState.side) ? result : -result;
      n->W += v;
      for (const auto& m : rolloutMoves) {
        n->N_rave[m] += 1;
        n->W_rave[m] += v;
      }
    }
  }

  if (!root->children.empty()) {
    Move best = root->children.begin()->first;
    int bestN = -1;
    for (auto& kv : root->children) {
      if (kv.second->N > bestN) {
        bestN = kv.second->N;
        best = kv.first;
      }
    }
    return best;
  }

  if (!root->untriedMoves.empty()) return root->untriedMoves.front();
  throw std::runtime_error("mcts failed to produce a move");
}

} // namespace gongqi
