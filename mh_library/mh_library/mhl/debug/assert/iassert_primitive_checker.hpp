#ifndef MHL_DEBUG_ASSERT_MHL_IASSERT_PRIMITIVE_CHECKER_HPP_
#define MHL_DEBUG_ASSERT_MHL_IASSERT_PRIMITIVE_CHECKER_HPP_

#include <stdint.h>

namespace mhl {

namespace debug {

namespace assert {

/**
 * @brief アサーションプリミティブ型チェックインターフェース
 *
 */
class IAssertPrimitiveChecker {
 public:
  virtual void Assert(const bool value1, const bool value2) = 0;
  virtual void Assert(const int8_t value1, const int8_t value2) = 0;
  virtual void Assert(const uint8_t value1, const uint8_t value2) = 0;
  virtual void Assert(const int16_t value1, const int16_t value2) = 0;
  virtual void Assert(const uint16_t value1, const uint16_t value2) = 0;
  virtual void Assert(const int32_t value1, const int32_t value2) = 0;
  virtual void Assert(const uint32_t value1, const uint32_t value2) = 0;
  virtual void Assert(const char* const value1, const char* const value2) = 0;
  virtual void Assert(const float value1, const float value2) = 0;
  virtual void Assert(const double value1, const double value2) = 0;
};

}  // namespace assert

}  // namespace debug

}  // namespace mhl

#endif  // MHL_DEBUG_ASSERT_MHL_IASSERT_PRIMITIVE_CHECKER_HPP_
