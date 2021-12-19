﻿#ifndef MHL_TEST_CODE_TESTEXECUTEMETHOD_HPP_
#define MHL_TEST_CODE_TESTEXECUTEMETHOD_HPP_

#include <memory>
#include <mhl/system/template/iexecute_method.hpp>
#include <mhl/test/unittest_base.hpp>

namespace test_code {

// メソッド実行テストクラス
class TestExecuteMethod : public mhl::UnitTestBase {
 public:
  typedef mhl::IExecuteMethod<test_code::TestExecuteMethod> MEB;
  enum class SCENE { kInitialize, kLoad, kMain };

 public:
  /**
   * コンストラクタ
   */
  TestExecuteMethod(std::shared_ptr<mhl::output::console::IConsoleOutputables>
                        output_console);

  /**
   * デストラクタ
   */
  virtual ~TestExecuteMethod();

  void ExecuteUnitTest();

  void Task();

  SCENE GetScene() { return scene_; }

 public:
  mhl::IExecuteMethod<test_code::TestExecuteMethod> Initialize();
  mhl::IExecuteMethod<test_code::TestExecuteMethod> Load();
  mhl::IExecuteMethod<test_code::TestExecuteMethod> Main();

 private:
  mhl::IExecuteMethod<test_code::TestExecuteMethod> on_exec_;
  SCENE scene_;
};

}  // namespace test_code

#endif  // TEST_TESTEXECUTEMETHOD_HPP_
