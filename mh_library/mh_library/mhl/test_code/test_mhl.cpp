#include "test_mhl.hpp"

#include "../test/unittest_execute_list.hpp"
#include "../util/output/ioutput_console.hpp"
#include "../util/output/output_console.hpp"
#include "test_execute_method.hpp"
#include "test_scene_stack.hpp"
#include "test_subject.hpp"
#include "bit/test_bit_control_uint32.hpp"

#include "../test_program/test_cpp_new_function_test.hpp"
#include "../test_program/test_instance_of_test.hpp"
#include "../test_program/test_binarytree_test.hpp"
#include "../test_program/test_multithread_test.hpp"


/**
 * コンストラクタ
 */
test_code::TestMhl::TestMhl(std::shared_ptr<mhl::IOutputConsole> output_console)
    : UnitTestBase(output_console) {}

/**
 * デストラクタ
 */
test_code::TestMhl::~TestMhl() {}

void test_code::TestMhl::ExecuteUnitTest() {
  mhl::UnitTestExecuteList list;
  std::shared_ptr<mhl::IOutputConsole> console(new mhl::OutputConsole());
  list.Add(std::shared_ptr<test_program::TestCppNewFunctionTest>(
      new test_program::TestCppNewFunctionTest(console)));
  list.Add(std::shared_ptr<test_code::TestExecuteMethod>(
      new test_code::TestExecuteMethod(console)));
  list.Add(std::shared_ptr<test_code::TestSubject>(
      new test_code::TestSubject(console)));
  list.Add(std::shared_ptr<test_program::TestInstanceOfTest>(
      new test_program::TestInstanceOfTest(console)));
  list.Add(std::shared_ptr<test_code::TestSceneStack>(
      new test_code::TestSceneStack(console)));
  // bit
  list.Add(std::shared_ptr<test_code::TestBitControlUint32>(new test_code::TestBitControlUint32(console)));

  list.Add(std::shared_ptr<test_program::TestBinaryTest>(
      new test_program::TestBinaryTest(console)));

  // できれば最後の実行したい()
  list.Add(std::shared_ptr<test_program::TestMultithreadTest>(
      new test_program::TestMultithreadTest(console)));
  // execute test
  if (!list.Execute()) {
    AssertEquals(false, "TestMhl::ExecuteUnitTest failure");
  }
}
