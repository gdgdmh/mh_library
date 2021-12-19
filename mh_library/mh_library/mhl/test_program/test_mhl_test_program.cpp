#include "test_mhl_test_program.hpp"

// 特に順序はないので下に追加していく
#include <mhl/output/console/iconsole_outputable.hpp>
#include <mhl/output/console/output_console.hpp>
#include <mhl/test/unittest_execute_list.hpp>
#include <mhl/test_program/route_search/test_route_search_test.hpp>
#include <mhl/test_program/test_binarytree_test.hpp>
#include <mhl/test_program/test_callback_test.hpp>
#include <mhl/test_program/test_component_test.hpp>
#include <mhl/test_program/test_cpp_new_function_test.hpp>
#include <mhl/test_program/test_debug_assert_test.hpp>
#include <mhl/test_program/test_delegate_test.hpp>
#include <mhl/test_program/test_fermat_test.hpp>
#include <mhl/test_program/test_free_test.hpp>
#include <mhl/test_program/test_instance_of_test.hpp>
#include <mhl/test_program/test_move_test.hpp>
#include <mhl/test_program/test_mt_rand_test.hpp>
#include <mhl/test_program/test_multithread_test.hpp>
#include <mhl/test_program/test_output_consoles_test.hpp>
#include <mhl/test_program/test_singleton_test.hpp>
#include <mhl/test_program/test_stacktrace_test.hpp>
#include <mhl/test_program/test_vector_test.hpp>

/**
 * コンストラクタ
 */
test_program::TestMhlTestProgram::TestMhlTestProgram(
    std::shared_ptr<mhl::output::console::IConsoleOutputables> output_console)
    : UnitTestBase(output_console) {}

/**
 * デストラクタ
 */
test_program::TestMhlTestProgram::~TestMhlTestProgram() {}

void test_program::TestMhlTestProgram::ExecuteUnitTest() {
  using namespace test_program;
  mhl::UnitTestExecuteList list;
  // --- 普段は使わない ---
  // アサーションのテスト
  // list.Add(std::shared_ptr<TestDebugAssertTest>(
  //  new TestDebugAssertTest(output_console_)));
  // ----------------------
  list.Add(std::shared_ptr<TestStacktraceTest>(
      new TestStacktraceTest(output_console_)));
  list.Add(std::shared_ptr<TestCppNewFunctionTest>(
      new TestCppNewFunctionTest(output_console_)));
  list.Add(std::shared_ptr<TestInstanceOfTest>(
      new TestInstanceOfTest(output_console_)));
  list.Add(
      std::shared_ptr<TestBinaryTest>(new TestBinaryTest(output_console_)));
  list.Add(
      std::shared_ptr<TestVectorTest>(new TestVectorTest(output_console_)));
  list.Add(
      std::shared_ptr<TestDelegateTest>(new TestDelegateTest(output_console_)));
  list.Add(std::shared_ptr<TestMoveTest>(new TestMoveTest(output_console_)));
  list.Add(
      std::shared_ptr<TestFermatTest>(new TestFermatTest(output_console_)));
  list.Add(std::shared_ptr<TestComponentTest>(
      new TestComponentTest(output_console_)));
  list.Add(std::shared_ptr<route_search::TestRouteSearchTest>(
      new route_search::TestRouteSearchTest(output_console_)));
  list.Add(std::shared_ptr<TestOutputConsolesTest>(
      new TestOutputConsolesTest(output_console_)));
  list.Add(
      std::shared_ptr<TestMtRandTest>(new TestMtRandTest(output_console_)));
  list.Add(std::shared_ptr<TestSingletonTest>(
      new TestSingletonTest(output_console_)));
  list.Add(std::make_shared<TestFreeTest>(output_console_));
  // できればマルチスレッドは最後の実行したい(マルチスレッドが途中だと原因がわからなくなる可能性があるかもしれない)
  list.Add(std::shared_ptr<TestMultithreadTest>(
      new TestMultithreadTest(output_console_)));
  // execute test
  if (!list.Execute()) {
    AssertEquals(false, "TestMhlTestProgram::ExecuteUnitTest failure");
  }
}
