#ifndef MHL_TEST_PROGRAM_TEST_MT_RAND_TEST_HPP_
#define MHL_TEST_PROGRAM_TEST_MT_RAND_TEST_HPP_

#include <stdint.h>

#include <memory>
#include <mhl/system/rand/irand_getable.hpp>
#include <mhl/test/unittest_base.hpp>

namespace test_program {

/**
 * @brief メルセンヌ・ツイスタ乱数のテスト
 *
 */
class TestMtRandTest : public mhl::UnitTestBase {
 public:
  /**
   * コンストラクタ
   */
  TestMtRandTest(std::shared_ptr<mhl::output::console::IConsoleOutputables>
                     output_console);

  /**
   * デストラクタ
   */
  virtual ~TestMtRandTest();

  void ExecuteUnitTest();

 private:
  std::shared_ptr<mhl::IRandGetable> mt_;
};

}  // namespace test_program

#endif  // MHL_TEST_PROGRAM_TEST_MT_RAND_TEST_HPP_
