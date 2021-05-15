#ifndef MHL_TEST_CODE_TEST_ASSERT_TEST_HPP_
#define MHL_TEST_CODE_TEST_ASSERT_TEST_HPP_

#include <memory>

#include "../test/unittest_base.hpp"

namespace test_program {

// Assertテスト
class TestDebugAssertTest : public mhl::UnitTestBase {
 public:
  /**
   * コンストラクタ
   */
  TestDebugAssertTest(std::shared_ptr<mhl::output::console::IConsoleOutputables>
                          output_console);

  /**
   * デストラクタ
   */
  virtual ~TestDebugAssertTest();

  void ExecuteUnitTest();
};

}  // namespace test_program

#endif  // MHL_TEST_CODE_TEST_ASSERT_TEST_HPP_
