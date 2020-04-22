#ifndef TEST_TESTEXECUTEMETHOD_HPP_
#define TEST_TESTEXECUTEMETHOD_HPP_

#include "../mh_library/util/template/IExecuteMethod.hpp"

namespace test {

// メソッド実行テストクラス
class TestExecuteMethod {

public:
  typedef mh_library::IExecuteMethod<test::TestExecuteMethod> MEB;
public:
  /**
   * コンストラクタ
   */
  TestExecuteMethod();

  /**
   * デストラクタ
   */
  virtual ~TestExecuteMethod();

  void Task();

public:

  mh_library::IExecuteMethod<test::TestExecuteMethod> Initialize();

  mh_library::IExecuteMethod<test::TestExecuteMethod> Load();

  mh_library::IExecuteMethod<test::TestExecuteMethod> Main();

private:
    mh_library::IExecuteMethod<test::TestExecuteMethod> on_exec_;
    //MEB on_exec_;
};

}

#endif  // TEST_TESTEXECUTEMETHOD_HPP_
