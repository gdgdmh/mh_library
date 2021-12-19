#ifndef MHL_TEST_CODE_TESTSUBJECT_HPP_
#define MHL_TEST_CODE_TESTSUBJECT_HPP_

#include <memory>
#include <mhl/system/template/iexecute_method.hpp>
#include <mhl/system/template/iobservable.hpp>
#include <mhl/system/template/subject.hpp>
#include <mhl/test/unittest_base.hpp>

namespace test_code {

// テストのためのクラス
class TestObserver : public mhl::IObservable {
 public:
  TestObserver() : value(0) {}

  void Update(mhl::Subject& subject) { value = 1; }

  int Get() const { return value; }

 private:
  int value;
};

// メソッド実行テストクラス
class TestSubject : public mhl::UnitTestBase {
 public:
  /**
   * コンストラクタ
   */
  TestSubject(std::shared_ptr<mhl::output::console::IConsoleOutputables>
                  output_console);

  /**
   * デストラクタ
   */
  virtual ~TestSubject();

  void ExecuteUnitTest();
};

}  // namespace test_code

#endif  // TEST_TESTSUBJECT_HPP_
