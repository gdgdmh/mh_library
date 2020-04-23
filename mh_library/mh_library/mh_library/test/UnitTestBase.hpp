#ifndef MH_LIBRABY_TEST_UNITTESTBASE_H_
#define MH_LIBRABY_TEST_UNITTESTBASE_H_

#include <string>
#include <memory>
#include "../util/output/IOutputConsole.hpp"

namespace mh_library {

// 単体テスト用のベースクラス
class UnitTestBase {
public:
  /**
   * コンストラクタ
   * @param outputConsole コンソール出力クラス
   */
  UnitTestBase(std::shared_ptr<mh_library::IOutputConsole> output_console);

  /**
   * デストラクタ
   */
  virtual ~UnitTestBase();

  /**
   * 実行
   */
  virtual void ExecuteUnitTest();

protected:

  /**
   * 条件のチェックの成否をチェックして失敗したときはメッセージを表示して例外を発生させる
   * メソッド内ではプログラム停止をしないので注意
   * @param expected 条件チェックした値(0なら失敗とする)
   * @param message  失敗した際のメッセージ
   * @return         trueなら成功
   */
  bool AssertEquals(int expected, std::string message);

protected:
  std::shared_ptr<mh_library::IOutputConsole> output_console_; // コンソール出力
};

}

#endif  // MH_LIBRABY_TEST_UNITTESTBASE_H_
