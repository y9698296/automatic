#include "test_framework.h"

#include <iostream>

std::vector<TestCase>& registry() { static std::vector<TestCase> r; return r; }
TestReg::TestReg(const std::string& name, std::function<void()> fn) { registry().push_back({name, std::move(fn)}); }

int main() {
  int failed = 0;
  for (const auto& t : registry()) {
    try {
      t.fn();
      std::cout << "[PASS] " << t.name << "\n";
    } catch (const std::exception& e) {
      ++failed;
      std::cout << "[FAIL] " << t.name << ": " << e.what() << "\n";
    }
  }
  return failed == 0 ? 0 : 1;
}
