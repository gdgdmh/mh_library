#ifndef MHL_DEBUG_ASSERT_MHL_ASSERT_CHECKER_HPP_
#define MHL_DEBUG_ASSERT_MHL_ASSERT_CHECKER_HPP_

#include <mhl/debug/assert/iassert_checker.hpp>

namespace mhl {

namespace debug {

namespace assert {

/**
 * @brief アサーションチェックインターフェース
 *
 */
class AssertChecker : public mhl::debug::assert::IAssertChecker {
 public:
  AssertChecker() {}

  /**
   * @brief デストラクタ
   *
   */
  virtual ~AssertChecker() {}

  /**
   * @brief チェック
   *
   * @param value trueならチェックOK
   * @return true チェックOK
   * @return false チェックNG
   */
  bool Check(const bool value) override { return value; }
};

}  // namespace assert

}  // namespace debug

}  // namespace mhl

#endif  // MHL_DEBUG_ASSERT_MHL_ASSERT_CHECKER_HPP_
