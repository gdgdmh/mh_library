#include "TestOutputConsolesTest.hpp"

#include <mhl/output/console/OutputConsole.hpp>
#include <mhl/output/console/OutputConsoleVsSjis.hpp>
#include <mhl/output/console/OutputConsoles.hpp>

/**
 * コンストラクタ
 */
test_program::TestOutputConsolesTest::TestOutputConsolesTest(
    std::shared_ptr<mhl::output::console::IConsoleOutputables> output_console) :
    UnitTestBase(output_console)
{
}

/**
 * デストラクタ
 */
test_program::TestOutputConsolesTest::~TestOutputConsolesTest()
{
}

/**
 * @brief テスト
 *
 */
void test_program::TestOutputConsolesTest::ExecuteUnitTest()
{
    mhl::output::console::OutputConsoles o;
    std::shared_ptr<mhl::output::console::IConsoleOutputable> output_console(
        new mhl::output::console::OutputConsole);
    std::shared_ptr<mhl::output::console::IConsoleOutputable> output_vs(
        new mhl::output::console::OutputConsoleVsSjis);
    o.Add(output_console);
    o.Add(output_vs);
    o.PrintLine("TestOutputConsolesTest::ExecuteUnitTest()テスト");
}
