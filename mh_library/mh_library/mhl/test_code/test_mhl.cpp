#include "test_mhl.hpp"

#include <mhl/output/console/iconsole_outputables.hpp>
#include <mhl/test/unittest_execute_list.hpp>
#include <mhl/test_code/bit/test_bit_control_uint32.hpp>
#include <mhl/test_code/data/test_data_collection.hpp>
#include <mhl/test_code/test_execute_method.hpp>
#include <mhl/test_code/test_scene_stack.hpp>
#include <mhl/test_code/test_subject.hpp>

/**
 * コンストラクタ
 */
test_code::TestMhl::TestMhl(
    std::shared_ptr<mhl::output::console::IConsoleOutputables> output_console)
    : UnitTestBase(output_console) {}

/**
 * デストラクタ
 */
test_code::TestMhl::~TestMhl() {}

void test_code::TestMhl::ExecuteUnitTest() {
  mhl::UnitTestExecuteList list;

  list.Add(std::shared_ptr<test_code::TestDataCollection>(
      new test_code::TestDataCollection(output_console_)));
  list.Add(std::shared_ptr<test_code::TestExecuteMethod>(
      new test_code::TestExecuteMethod(output_console_)));
  list.Add(std::shared_ptr<test_code::TestSubject>(
      new test_code::TestSubject(output_console_)));
  list.Add(std::shared_ptr<test_code::TestSceneStack>(
      new test_code::TestSceneStack(output_console_)));
  // bit
  list.Add(std::shared_ptr<test_code::TestBitControlUint32>(
      new test_code::TestBitControlUint32(output_console_)));
  // execute test
  if (!list.Execute()) {
    AssertEquals(false, "TestMhl::ExecuteUnitTest failure");
  }
}
