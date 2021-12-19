#include "mhl_assertion.hpp"

#include <mhl/exception/argument_exception.hpp>

/**
 * @brief コンストラクタ
 *
 * @param checker アサーションチェックインターフェース
 * @param assert_process アサーション処理インターフェース
 */
mhl::debug::assert::MhlAssertion::MhlAssertion(
    std::unique_ptr<IAssertChecker>&& checker,
    std::unique_ptr<IAssertProcessor>&& assert_process,
    std::unique_ptr<mhl::output::console::IConsoleOutputables>&& output_console,
    std::unique_ptr<mhl::debug::stacktrace::IStacktraceable>&& stacktrace)
    : checker_(std::move(checker)),
      assert_process_(std::move(assert_process)),
      output_console_(std::move(output_console)),
      stacktrace_(std::move(stacktrace)) {}

/**
 * @brief デストラクタ
 *
 */
mhl::debug::assert::MhlAssertion::~MhlAssertion() {}

/**
 * @brief valueをチェックし、trueならアサーション処理をする
 *
 * @param value trueならアサーション処理をする
 */
void mhl::debug::assert::MhlAssertion::Assert(bool value) {
  if (!IsValid()) {
    // 未設定
    ErrorProcess();
  }
  // trueならアサーション
  if (!checker_->Check(value)) {
    PrintStackTrace();
    assert_process_->Assert();
  }
}

/**
 * @brief valueをチェックし、trueならアサーション処理をする
 *        アサーション処理をした際にメッセージを出力する
 *
 * @param value trueならアサーション処理をする
 * @param message アサーション処理実行時にメッセージを出力
 */
void mhl::debug::assert::MhlAssertion::Assert(bool value,
                                              const std::string& message) {
  if (!IsValid()) {
    // 未設定
    ErrorProcess();
  }
  // パラメーターをチェックして一致しないならアサーション
  if (!checker_->Check(value)) {
    output_console_->PrintLine(message);
    PrintStackTrace();
    assert_process_->Assert();
  }
}

/**
 * @brief パラメータの設定がされているかチェック
 *
 * @return true 設定されている
 * @return false 設定されてない
 */
bool mhl::debug::assert::MhlAssertion::IsValid() {
  if (!checker_) {
    return false;
  }
  if (!assert_process_) {
    return false;
  }
  if (!output_console_) {
    return false;
  }
  if (!stacktrace_) {
    return false;
  }
  return true;
}

/**
 * @brief エラー処理(例外を発生させる)
 *
 */
void mhl::debug::assert::MhlAssertion::ErrorProcess() {
  mhl::exception::ArgumentException exception_data(
      "MhlAssertion(not set interface)", 0);
  throw exception_data;
}

/**
 * @brief スタックトレースの出力
 *
 */
void mhl::debug::assert::MhlAssertion::PrintStackTrace() {
  mhl::debug::stacktrace::StacktraceInfo info;
  stacktrace_->GetStacktrace(info);
  std::string stacktrace_str;
  stacktrace_->ToStringStacktrace(stacktrace_str, info);
  output_console_->PrintLine(stacktrace_str);
}