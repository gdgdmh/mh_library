#ifndef TEST_TESTEXECUTEMETHOD_HPP_
#define TEST_TESTEXECUTEMETHOD_HPP_

#include <memory>
#include "../mh_library/test/UnitTestBase.hpp"
#include "../mh_library/util/template/IExecuteMethod.hpp"

namespace test {

// メソッド実行テストクラス
class TestExecuteMethod : public mh_library::UnitTestBase {
public:
  typedef mh_library::IExecuteMethod<test::TestExecuteMethod> MEB;
  enum class SCENE {
    kInitialize,
    kLoad,
    kMain
  };

public:
  /**
   * コンストラクタ
   */
  TestExecuteMethod(std::shared_ptr<mh_library::IOutputConsole> output_console);

  /**
   * デストラクタ
   */
  virtual ~TestExecuteMethod();

  void ExecuteUnitTest();

  void Task();

  SCENE GetScene() {
    return scene_;
  }

public:

  mh_library::IExecuteMethod<test::TestExecuteMethod> Initialize();

  mh_library::IExecuteMethod<test::TestExecuteMethod> Load();

  mh_library::IExecuteMethod<test::TestExecuteMethod> Main();

private:
    mh_library::IExecuteMethod<test::TestExecuteMethod> on_exec_;
    SCENE scene_;
    //MEB on_exec_;
};

}

#endif  // TEST_TESTEXECUTEMETHOD_HPP_
