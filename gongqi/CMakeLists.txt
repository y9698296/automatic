cmake_minimum_required(VERSION 3.16)
project(gongqi LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

set(GONGQI_SOURCES
  src/Geometry.cpp
  src/Rules.cpp
  src/Apply.cpp
  src/Gong.cpp
  src/BombCross.cpp
  src/Duan.cpp
  src/KTBC.cpp
  src/STBC.cpp
  src/Count.cpp
  src/MoveGen.cpp
  src/Zobrist.cpp
  src/MCTS.cpp
  src/TT.cpp
)

add_library(gongqi_lib ${GONGQI_SOURCES})
add_executable(gongqi_main src/main.cpp)
target_link_libraries(gongqi_main PRIVATE gongqi_lib)

enable_testing()

add_executable(gongqi_tests
  tests/test_main.cpp
  tests/test_gong.cpp
  tests/test_duan.cpp
  tests/test_bombcross.cpp
  tests/test_ktbc.cpp
  tests/test_stbc.cpp
  tests/test_apply_sequence.cpp
  tests/test_mcts_smoke.cpp
)
target_link_libraries(gongqi_tests PRIVATE gongqi_lib)
add_test(NAME gongqi_tests COMMAND gongqi_tests)
