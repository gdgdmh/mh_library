#include "TestMhl.hpp"

#include <mhl/output/console/IConsoleOutputables.hpp>
#include <mhl/test/UnittestExecuteList.hpp>
#include <mhl/test_code/bit/TestBitControlUint32.hpp>
#include <mhl/test_code/data/TestDataCollection.hpp>
#include <mhl/test_code/TestExecuteMethod.hpp>
#include <mhl/test_code/TestSceneStack.hpp>
#include <mhl/test_code/TestSubject.hpp>

/**
 * コンストラクタ
 */
test_code::TestMhl::TestMhl(
    std::shared_ptr<mhl::output::console::IConsoleOutputables> output_console) :
    UnitTestBase(output_console)
{
}

/**
 * デストラクタ
 */
test_code::TestMhl::~TestMhl()
{
}

void test_code::TestMhl::ExecuteUnitTest()
{
    mhl::UnitTestExecuteList list;

    list.Add(std::make_shared<test_code::TestDataCollection>(output_console_));
    list.Add(std::make_shared<test_code::TestExecuteMethod>(output_console_));
    list.Add(std::make_shared<test_code::TestSubject>(output_console_));
    list.Add(std::make_shared<test_code::TestSceneStack>(output_console_));
    // bit
    list.Add(std::make_shared<test_code::TestBitControlUint32>(output_console_));
    // execute test
    if (!list.Execute())
    {
        AssertEquals(false, "TestMhl::ExecuteUnitTest failure");
    }
}
