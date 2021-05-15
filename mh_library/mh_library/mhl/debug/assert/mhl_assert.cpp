#include "mhl_assert.hpp"

#include "../../exception/argument_exception.hpp"

/**
 * @brief コンストラクタ
 *
 * @param checker アサーションチェックインターフェース
 * @param assert_process アサーション処理インターフェース
 */
mhl::debug::assert::MhlAssert::MhlAssert(
    std::unique_ptr<IAssertChecker>&& checker,
    std::unique_ptr<IAssertProcessor>&& assert_process,
    std::unique_ptr<mhl::output::console::IConsoleOutputables>&& output_console)
    : checker_(std::move(checker)),
      assert_process_(std::move(assert_process)),
      output_console_(std::move(output_console)) {}

/**
 * @brief デストラクタ
 *
 */
mhl::debug::assert::MhlAssert::~MhlAssert() {}

/**
 * @brief valueをチェックし、trueならアサーション処理をする
 *
 * @param value trueならアサーション処理をする
 */
void mhl::debug::assert::MhlAssert::Assert(bool value) {
  if (!IsValid()) {
    // 未設定
    ErrorProcess();
  }
  // trueならアサーション
  if (!checker_->Check(value)) {
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
void mhl::debug::assert::MhlAssert::Assert(bool value,
                                           const std::string& message) {
  if (!IsValid()) {
    // 未設定
    ErrorProcess();
  }
  // パラメーターをチェックして一致しないならアサーション
  if (!checker_->Check(value)) {
    output_console_->PrintLine(message);
    assert_process_->Assert();
  }
}

/**
 * @brief パラメータの設定がされているかチェック
 *
 * @return true 設定されている
 * @return false 設定されてない
 */
bool mhl::debug::assert::MhlAssert::IsValid() {
  if (!checker_) {
    return false;
  }
  if (!assert_process_) {
    return false;
  }
  if (!output_console_) {
    return false;
  }
  return true;
}

/**
 * @brief エラー処理(例外を発生させる)
 *
 */
void mhl::debug::assert::MhlAssert::ErrorProcess() {
  mhl::exception::ArgumentException exception_data(
      "MhlAssert(not set interface)", 0);
  throw exception_data;
}