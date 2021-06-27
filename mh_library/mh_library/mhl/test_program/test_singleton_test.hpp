#ifndef MHL_TEST_PROGRAM_TEST_SINGLETON_TEST_HPP_
#define MHL_TEST_PROGRAM_TEST_SINGLETON_TEST_HPP_

#include "../test/unittest_base.hpp"

namespace test_program {

/**
 * @brief シングルトンのテスト
 *
 */
class TestSingletonTest : public mhl::UnitTestBase {
 public:
  /**
   * コンストラクタ
   */
  TestSingletonTest(std::shared_ptr<mhl::output::console::IConsoleOutputables>
                        output_console);

  /**
   * デストラクタ
   */
  virtual ~TestSingletonTest();

  void ExecuteUnitTest();

  /**
   * @brief クリーンアップのテスト
   *
   */
  void TestCleanup();

 private:
};

}  // namespace test_program

#endif  // MHL_TEST_PROGRAM_TEST_SINGLETON_TEST_HPP_
