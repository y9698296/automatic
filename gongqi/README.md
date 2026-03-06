# Gongqi (研究版最小实现)

本项目实现了拱棋研究版最小规则引擎与 MCTS/RAVE smoke 版本。

## 构建

```bash
cmake -S . -B build
cmake --build build
ctest --test-dir build --output-on-failure
```
