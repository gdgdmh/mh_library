#ifndef MHL_TEST_CODE_TESTMHL_HPP_
#define MHL_TEST_CODE_TESTMHL_HPP_

#include <memory>
#include <mhl/test/unittest_base.hpp>

namespace test_code {

// MHLテストクラス
class TestMhl : public mhl::UnitTestBase {
 public:
  /**
   * コンストラクタ
   */
  TestMhl(std::shared_ptr<mhl::output::console::IConsoleOutputables>
              output_console);

  /**
   * デストラクタ
   */
  virtual ~TestMhl();

  void ExecuteUnitTest();
};

}  // namespace test_code

#endif  // MHL_TEST_CODE_TESTMHL_HPP_
