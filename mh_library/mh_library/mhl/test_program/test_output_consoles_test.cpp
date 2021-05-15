#include "test_output_consoles_test.hpp"

#include "../output/console/output_consoles.hpp"
#include "../output/console/output_console.hpp"
#include "../output/console/output_console_vs_sjis.hpp"

/**
 * コンストラクタ
 */
test_program::TestOutputConsolesTest::TestOutputConsolesTest(
    std::shared_ptr<mhl::output::console::IConsoleOutputables> output_console)
    : UnitTestBase(output_console) {}

/**
 * デストラクタ
 */
test_program::TestOutputConsolesTest::~TestOutputConsolesTest() {}

/**
 * @brief テスト
 *
 */
void test_program::TestOutputConsolesTest::ExecuteUnitTest() {
  mhl::output::console::OutputConsoles o;
  std::shared_ptr<mhl::output::console::IConsoleOutputable> output_console(
      new mhl::output::console::OutputConsole);
  std::shared_ptr<mhl::output::console::IConsoleOutputable> output_vs(
      new mhl::output::console::OutputConsoleVsSjis);
  o.Add(output_console);
  o.Add(output_vs);
  o.PrintLine("TestOutputConsolesTest::ExecuteUnitTest()テスト");
}
