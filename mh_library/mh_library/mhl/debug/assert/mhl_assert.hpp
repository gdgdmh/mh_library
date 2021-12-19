#ifndef MHL_DEBUG_ASSERT_MHL_ASSERT_HPP_
#define MHL_DEBUG_ASSERT_MHL_ASSERT_HPP_

#include <mhl/debug/assert/mhl_assertion.hpp>

namespace mhl {

namespace debug {

namespace assert {

class MhlAssert {
 public:
  /**
   * @brief valueをチェックし、trueならアサーション処理をする
   *
   * @param value trueならアサーション処理をする
   */
  static void Assert(bool value);

  /**
   * @brief valueをチェックし、trueならアサーション処理をする
   *        アサーション処理をした際にメッセージを出力する
   *
   * @param value trueならアサーション処理をする
   * @param message アサーション処理実行時にメッセージを出力
   */
  static void Assert(bool value, const std::string& message);
};

}  // namespace assert

}  // namespace debug

}  // namespace mhl

#endif  // MHL_DEBUG_ASSERT_MHL_ASSERT_HPP_
