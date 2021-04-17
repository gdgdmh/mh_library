#ifndef MHL_DEBUG_MHL_ASSERT_HPP_
#define MHL_DEBUG_MHL_ASSERT_HPP_

#include <cassert>

#include "./stacktrace/get_stacktrace_win.hpp"

namespace mhl {

namespace debug {

#ifndef MHL_ASSERT
// 一時しのぎのassert
#define MHL_ASSERT(expr, msg) _ASSERT_EXPR(expr, msg)
#endif  // MHL_ASSERT

class MhlAssert {
 public:
  static void Assert(bool value1, bool value2);
  static void Assert(int8_t value1, int8_t value2);
  static void Assert(uint8_t value1, uint8_t value2);
  static void Assert(int16_t value1, int16_t value2);
  static void AssertEquals(uint16_t value1, uint16_t value2);
  static void AssertEquals(int32_t value1, int32_t value2);
  static void AssertEquals(uint32_t value1, uint32_t value2);
  static void AssertEquals(float value1, float value2);
  static void AssertEquals(double value1, double value2);
};

}  // namespace debug

}  // namespace mhl

#endif  // MHL_DEBUG_MHL_ASSERT_HPP_
