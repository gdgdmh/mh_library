#include "test_mhl_test_program.hpp"

#include "../output/console/iconsole_outputable.hpp"
#include "../output/console/output_console.hpp"
#include "../test/unittest_execute_list.hpp"
#include "../test_program/route_search/test_route_search_test.hpp"
#include "../test_program/test_binarytree_test.hpp"
#include "../test_program/test_callback_test.hpp"
#include "../test_program/test_cpp_new_function_test.hpp"
#include "../test_program/test_delegate_test.hpp"
#include "../test_program/test_fermat_test.hpp"
#include "../test_program/test_instance_of_test.hpp"
#include "../test_program/test_move_test.hpp"
#include "../test_program/test_multithread_test.hpp"
#include "../test_program/test_stacktrace_test.hpp"
#include "../test_program/test_vector_test.hpp"

/**
 * コンストラクタ
 */
test_program::TestMhlTestProgram::TestMhlTestProgram(
    std::shared_ptr<mhl::output::console::IConsoleOutputable> output_console)
    : UnitTestBase(output_console) {}

/**
 * デストラクタ
 */
test_program::TestMhlTestProgram::~TestMhlTestProgram() {}

void test_program::TestMhlTestProgram::ExecuteUnitTest() {
  using namespace test_program;
  mhl::UnitTestExecuteList list;
  std::shared_ptr<mhl::output::console::IConsoleOutputable> console(
      new mhl::output::console::OutputConsole());
  list.Add(
      std::shared_ptr<TestStacktraceTest>(new TestStacktraceTest(console)));
  list.Add(std::shared_ptr<TestCppNewFunctionTest>(
      new TestCppNewFunctionTest(console)));
  list.Add(
      std::shared_ptr<TestInstanceOfTest>(new TestInstanceOfTest(console)));
  list.Add(std::shared_ptr<TestBinaryTest>(new TestBinaryTest(console)));
  list.Add(std::shared_ptr<TestVectorTest>(new TestVectorTest(console)));
  list.Add(std::shared_ptr<TestDelegateTest>(new TestDelegateTest(console)));
  list.Add(std::shared_ptr<TestMoveTest>(new TestMoveTest(console)));
  list.Add(std::shared_ptr<TestFermatTest>(new TestFermatTest(console)));
  list.Add(std::shared_ptr<route_search::TestRouteSearchTest>(
      new route_search::TestRouteSearchTest(console)));
  // できればマルチスレッドは最後の実行したい(マルチスレッドが途中だと原因がわからなくなる可能性があるかもしれない)
  list.Add(
      std::shared_ptr<TestMultithreadTest>(new TestMultithreadTest(console)));
  // execute test
  if (!list.Execute()) {
    AssertEquals(false, "TestMhlTestProgram::ExecuteUnitTest failure");
  }
}
