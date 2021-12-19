#ifndef MHL_DEBUG_ASSERT_MHL_ASSERTION_HPP_
#define MHL_DEBUG_ASSERT_MHL_ASSERTION_HPP_

#include <cassert>
#include <memory>
#include <mhl/debug/assert/iassert_checker.hpp>
#include <mhl/debug/assert/iassert_processor.hpp>
#include <mhl/debug/stacktrace/get_stacktrace_win.hpp>
#include <mhl/debug/stacktrace/istacktraceable.hpp>
#include <mhl/output/console/iconsole_outputables.hpp>

namespace mhl {

namespace debug {

namespace assert {

#ifndef MHL_ASSERT
// 一時しのぎのassert
#define MHL_ASSERT(expr, msg) _ASSERT_EXPR(expr, msg)
#endif  // MHL_ASSERT

class MhlAssertion {
 public:
  /**
   * @brief コンストラクタ
   *
   * @param checker アサーションチェックインターフェース
   * @param assert_process アサーション処理インターフェース
   */
  MhlAssertion(
      std::unique_ptr<IAssertChecker>&& checker,
      std::unique_ptr<IAssertProcessor>&& assert_process,
      std::unique_ptr<mhl::output::console::IConsoleOutputables>&&
          output_console,
      std::unique_ptr<mhl::debug::stacktrace::IStacktraceable>&& stacktrace);

  /**
   * @brief デストラクタ
   *
   */
  virtual ~MhlAssertion();

  /**
   * @brief valueをチェックし、trueならアサーション処理をする
   *
   * @param value trueならアサーション処理をする
   */
  void Assert(bool value);

  /**
   * @brief valueをチェックし、trueならアサーション処理をする
   *        アサーション処理をした際にメッセージを出力する
   *
   * @param value trueならアサーション処理をする
   * @param message アサーション処理実行時にメッセージを出力
   */
  void Assert(bool value, const std::string& message);

 private:
  /**
   * @brief パラメータの設定がされているかチェック
   *
   * @return true 設定されている
   * @return false 設定されてない
   */
  bool IsValid();

  /**
   * @brief エラー処理(例外を発生させる)
   *
   */
  void ErrorProcess();

  /**
   * @brief スタックトレースの出力
   *
   */
  void PrintStackTrace();

 private:
  // アサーションチェックインターフェース
  std::unique_ptr<IAssertChecker> checker_;
  // アサーション処理
  std::unique_ptr<IAssertProcessor> assert_process_;
  // コンソール出力
  std::unique_ptr<mhl::output::console::IConsoleOutputables> output_console_;
  // スタックトレース情報
  std::unique_ptr<mhl::debug::stacktrace::IStacktraceable> stacktrace_;
};

}  // namespace assert

}  // namespace debug

}  // namespace mhl

#endif  // MHL_DEBUG_ASSERT_MHL_ASSERTION_HPP_
