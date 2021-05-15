#ifndef MHL_DEBUG_ASSERT_MHL_IASSERT_PROCESSOR_HPP_
#define MHL_DEBUG_ASSERT_MHL_IASSERT_PROCESSOR_HPP_

#include <stdint.h>

namespace mhl {

namespace debug {

namespace assert {

/**
 * @brief アサーション処理インターフェース
 *
 */
class IAssertProcessor {
 public:

  virtual ~IAssertProcessor() {}

  /**
   * @brief アサーション処理
   *
   */
  virtual void Assert() = 0;
};

}  // namespace assert

}  // namespace debug

}  // namespace mhl

#endif  // MHL_DEBUG_ASSERT_MHL_IASSERT_PROCESSOR_HPP_
