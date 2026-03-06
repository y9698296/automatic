#pragma once

#include <functional>
#include <stdexcept>
#include <string>
#include <vector>

struct TestCase { std::string name; std::function<void()> fn; };
std::vector<TestCase>& registry();

struct TestReg {
  TestReg(const std::string& name, std::function<void()> fn);
};

#define TEST(name) void name(); static TestReg reg_##name(#name, name); void name()
#define ASSERT_TRUE(cond) do { if (!(cond)) throw std::runtime_error("assert true failed: " #cond); } while(0)
#define ASSERT_EQ(a,b) do { if (!((a)==(b))) throw std::runtime_error("assert eq failed: " #a " == " #b); } while(0)
