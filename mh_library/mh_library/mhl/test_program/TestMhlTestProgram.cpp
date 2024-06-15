#include "TestMhlTestProgram.hpp"

// 特に順序はないので下に追加していく
#include <mhl/output/console/IConsoleOutputable.hpp>
#include <mhl/output/console/OutputConsole.hpp>
#include <mhl/test/UnittestExecuteList.hpp>
#include <mhl/test_program/route_search/TestRouteSearchTest.hpp>
#include <mhl/test_program/TestBinarytreeTest.hpp>
#include <mhl/test_program/TestCallbackTest.hpp>
#include <mhl/test_program/TestComponentTest.hpp>
#include <mhl/test_program/TestCppNewFunctionTest.hpp>
#include <mhl/test_program/TestDebugAssertTest.hpp>
#include <mhl/test_program/TestDelegateTest.hpp>
#include <mhl/test_program/TestFermatTest.hpp>
#include <mhl/test_program/TestFreeTest.hpp>
#include <mhl/test_program/TestInstanceOfTest.hpp>
#include <mhl/test_program/TestMoveTest.hpp>
#include <mhl/test_program/TestMtRandTest.hpp>
#include <mhl/test_program/TestMultithreadTest.hpp>
#include <mhl/test_program/TestOutputConsolesTest.hpp>
#include <mhl/test_program/TestSingletonTest.hpp>
#include <mhl/test_program/TestStacktraceTest.hpp>
#include <mhl/test_program/TestVectorTest.hpp>

/**
 * コンストラクタ
 */
test_program::TestMhlTestProgram::TestMhlTestProgram(
    std::shared_ptr<mhl::output::console::IConsoleOutputables> output_console) :
    UnitTestBase(output_console)
{
}

/**
 * デストラクタ
 */
test_program::TestMhlTestProgram::~TestMhlTestProgram()
{
}

void test_program::TestMhlTestProgram::ExecuteUnitTest()
{
    using namespace test_program;
    mhl::UnitTestExecuteList list;
    // --- 普段は使わない ---
    // アサーションのテスト
    // list.Add(std::shared_ptr<TestDebugAssertTest>(
    //  new TestDebugAssertTest(output_console_)));
    // ----------------------
    list.Add(std::make_shared<TestStacktraceTest>(output_console_));
    list.Add(std::make_shared<TestCppNewFunctionTest>(output_console_));
    list.Add(std::make_shared<TestInstanceOfTest>(output_console_));
    list.Add(
        std::make_shared<TestBinaryTest>(output_console_));
    list.Add(
        std::make_shared<TestVectorTest>(output_console_));
    list.Add(
        std::make_shared<TestDelegateTest>(output_console_));
    list.Add(std::make_shared<TestMoveTest>(output_console_));
    list.Add(
        std::make_shared<TestFermatTest>(output_console_));
    list.Add(std::make_shared<TestComponentTest>(output_console_));
    list.Add(std::make_shared<route_search::TestRouteSearchTest>(output_console_));
    list.Add(std::make_shared<TestOutputConsolesTest>(output_console_));
    list.Add(
        std::make_shared<TestMtRandTest>(output_console_));
    list.Add(std::make_shared<TestSingletonTest>(output_console_));
    list.Add(std::make_shared<TestFreeTest>(output_console_));
    // できればマルチスレッドは最後の実行したい(マルチスレッドが途中だと原因がわからなくなる可能性があるかもしれない)
    list.Add(std::make_shared<TestMultithreadTest>(output_console_));
    // execute test
    if (!list.Execute())
    {
        AssertEquals(false, "TestMhlTestProgram::ExecuteUnitTest failure");
    }
}
