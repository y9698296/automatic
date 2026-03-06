#pragma once

#include <array>

#include "Types.h"

namespace gongqi {

struct Workspace {
  std::array<std::array<uint32_t, N>, N> visStamp{};
  uint32_t stamp = 0;
};

} // namespace gongqi
