#ifndef TEST_TESTCPPNEWFUNCTIONTEST_HPP_
#define TEST_TESTCPPNEWFUNCTIONTEST_HPP_

#include <memory>
#include "../mhl/test/UnitTestBase.hpp"

namespace test {

// C++機能テスト
class TestCppNewFunctionTest : public mhl::UnitTestBase {
public:
  /**
   * コンストラクタ
   */
  TestCppNewFunctionTest(std::shared_ptr<mhl::IOutputConsole> output_console);

  /**
   * デストラクタ
   */
  virtual ~TestCppNewFunctionTest();

  void ExecuteUnitTest();

  /**
   * C++11のnullptrテスト
   */
  void TestCpp11Nullptr();

  /**
   * 統一初期化記法case001
   */
  void TestUniformInitialization001();

  /**
   * 統一初期化記法case002
   */
  void TestUniformInitialization002();

  /**
   * 統一初期化記法case003
   */
  void TestUniformInitialization003();

  /**
   * 統一初期化記法case004
   */
  void TestUniformInitialization004();
};

}

#endif  // TEST_TESTCPPNEWFUNCTIONTEST_HPP_
