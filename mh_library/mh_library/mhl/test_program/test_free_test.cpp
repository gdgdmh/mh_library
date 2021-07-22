#include "test_free_test.hpp"

#include <stdint.h>

#include "../system/variable_length_arguments/get_variable_length_arguments.hpp"

/**
 * コンストラクタ
 */
test_program::TestFreeTest::TestFreeTest(
    std::shared_ptr<mhl::output::console::IConsoleOutputables> output_console)
    : UnitTestBase(output_console) {}

/**
 * デストラクタ
 */
test_program::TestFreeTest::~TestFreeTest() {}

void test_program::TestFreeTest::ExecuteUnitTest() {
  TestGetVariableLengthArguments();
}

void test_program::TestFreeTest::TestGetVariableLengthArguments() {
  mhl::system::variable_length_arguments::GetVariableLengthArguments get;
  {
    std::string s;
    int32_t value = 10;
    get.ToString(s, "value=%d", value);
  }
  {
    constexpr size_t kStrSize = 100;
    char str[kStrSize];
    int32_t value = 10;
    get.ToChar(str, kStrSize, "value=%d", value);
    int32_t tmp = 0;
    tmp = 10;
  }
}
