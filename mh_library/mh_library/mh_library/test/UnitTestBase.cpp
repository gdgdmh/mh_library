#include "UnitTestBase.hpp"

#include "../exception/UnitTestException.hpp"

/**
 * コンストラクタ
 * @param outputConsole コンソール出力クラス
 */
mh_library::UnitTestBase::UnitTestBase(std::shared_ptr<mh_library::IOutputConsole> output_console) :
  output_console_(output_console) {
}

/**
 * デストラクタ
 */
mh_library::UnitTestBase::~UnitTestBase() {
}

/**
 * 実行
 * @return trueなら成功 falseなら失敗
 */
bool mh_library::UnitTestBase::Execute() {
  return true;
}

/**
 * 条件のチェックの成否をチェックして失敗したときはメッセージを表示して例外を発生させる
 * @param expected 条件チェックした値(0なら失敗とする)
 * @param message  失敗した際のメッセージ
 * @return         trueなら成功
 */
bool mh_library::UnitTestBase::AssertEquals(int expected, std::string message) {
  if (expected != 0) {
    // 正常
    return true;
  }
  if (output_console_) {
    // 失敗しているのでメッセージを出力する
    // 後に__LINE__や__FILE__を追加することも考慮する
    output_console_->PrintLine(message);
  }
  // 例外をスローするため、失敗したらfalseを返すことはない
  throw UnitTestException(message, 0);
}
