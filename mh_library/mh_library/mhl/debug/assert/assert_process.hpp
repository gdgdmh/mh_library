#ifndef MHL_DEBUG_ASSERT_MHL_ASSERT_PROCESS_HPP_
#define MHL_DEBUG_ASSERT_MHL_ASSERT_PROCESS_HPP_

#include <cassert>

#include "iassert_processor.hpp"

namespace mhl {

namespace debug {

namespace assert {

/**
 * @brief アサーション処理クラス
 *
 */
class AssertProcess : public IAssertProcessor {
 public:

  AssertProcess() {}

  /**
   * @brief デストラクタ
   *
   */
  virtual ~AssertProcess() {}

  /**
   * @brief アサーション処理
   *
   */
  virtual void Assert() override { assert(0); }
};

}  // namespace assert

}  // namespace debug

}  // namespace mhl

#endif  // MHL_DEBUG_ASSERT_MHL_ASSERT_PROCESS_HPP_
