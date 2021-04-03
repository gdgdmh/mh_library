#ifndef MHL_TEST_PROGRAM_TEST_OUTPUT_CONSOLES_TEST_HPP_
#define MHL_TEST_PROGRAM_TEST_OUTPUT_CONSOLES_TEST_HPP_

#include <stdint.h>

#include <memory>

#include "../test/unittest_base.hpp"

namespace test_program {

class TestOutputConsolesTest : public mhl::UnitTestBase {
 public:
  /**
   * コンストラクタ
   */
  TestOutputConsolesTest(
      std::shared_ptr<mhl::output::console::IConsoleOutputables> output_console);

  /**
   * デストラクタ
   */
  virtual ~TestOutputConsolesTest();

  /**
   * @brief テスト
   *
   */
  void ExecuteUnitTest();
};

}  // namespace test_program

#endif  // MHL_TEST_PROGRAM_TEST_OUTPUT_CONSOLES_TEST_HPP_
