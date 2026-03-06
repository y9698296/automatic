#pragma once

#include "Types.h"

namespace gongqi {

bool isBaseline(Color color, int x, int y);
bool inEnemyTriLine(Color color, int x, int y);
bool crossedMidline(Color color, int x, int y);

} // namespace gongqi
