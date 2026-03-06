#pragma once

#include <vector>

#include "State.h"

namespace gongqi {

struct Undo {
  State snapshot;
};

} // namespace gongqi
