#include "Duan.h"

#include <queue>

#include "Geometry.h"

namespace gongqi {

std::vector<RemovedPiece> duanCut(State& state, Workspace& ws, Color enemyColor) {
  ws.stamp += 1;
  if (ws.stamp == 0) {
    for (auto& col : ws.visStamp) {
      col.fill(0);
    }
    ws.stamp = 1;
  }

  std::queue<Pos> q;

  for (int x = 0; x < N; ++x) {
    for (int y = 0; y < N; ++y) {
      if (isBaseline(enemyColor, x, y) && state.board[x][y] == enemyColor) {
        ws.visStamp[x][y] = ws.stamp;
        q.push({x, y});
      }
    }
  }

  while (!q.empty()) {
    Pos u = q.front();
    q.pop();
    for (const auto& d : DIR8) {
      int vx = u.x + d.x;
      int vy = u.y + d.y;
      if (inBoard(vx, vy) && state.board[vx][vy] == enemyColor && ws.visStamp[vx][vy] != ws.stamp) {
        ws.visStamp[vx][vy] = ws.stamp;
        q.push({vx, vy});
      }
    }
  }

  std::vector<RemovedPiece> removed;
  for (int x = 0; x < N; ++x) {
    for (int y = 0; y < N; ++y) {
      if (state.board[x][y] == enemyColor && ws.visStamp[x][y] != ws.stamp) {
        state.board[x][y] = EMPTY;
        removed.push_back({x, y, enemyColor});
      }
    }
  }
  return removed;
}

} // namespace gongqi
