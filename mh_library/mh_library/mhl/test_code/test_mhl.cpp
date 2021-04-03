#include "test_mhl.hpp"

#include "../test/unittest_execute_list.hpp"
#include "../output/console/iconsole_outputables.hpp"
#include "test_execute_method.hpp"
#include "test_scene_stack.hpp"
#include "test_subject.hpp"
#include "bit/test_bit_control_uint32.hpp"
#include "data/test_data_collection.hpp"


/**
 * コンストラクタ
 */
test_code::TestMhl::TestMhl(
    std::shared_ptr<mhl::output::console::IConsoleOutputables>
        output_console)
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
