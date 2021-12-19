#include "test_debug_assert_test.hpp"

#include <mhl/debug/assert/assert_checker.hpp>
#include <mhl/debug/assert/assert_process.hpp>
#include <mhl/debug/assert/mhl_assertion.hpp>
#include <mhl/output/console/output_console.hpp>
#include <mhl/output/console/output_console_vs_sjis.hpp>
#include <mhl/output/console/output_consoles.hpp>

/**
 * コンストラクタ
 */
test_program::TestDebugAssertTest::TestDebugAssertTest(
    std::shared_ptr<mhl::output::console::IConsoleOutputables> output_console)
    : UnitTestBase(output_console) {}

/**
 * デストラクタ
 */
test_program::TestDebugAssertTest::~TestDebugAssertTest() {}

void test_program::TestDebugAssertTest::ExecuteUnitTest() {
  std::unique_ptr<mhl::debug::assert::IAssertChecker> checker(
      new mhl::debug::assert::AssertChecker());
  std::unique_ptr<mhl::debug::assert::IAssertProcessor> processor(
      new mhl::debug::assert::AssertProcess());
  std::unique_ptr<mhl::output::console::IConsoleOutputables> output_console(
      new mhl::output::console::OutputConsoles());

  {
    std::shared_ptr<mhl::output::console::IConsoleOutputable> c =
        std::shared_ptr<mhl::output::console::OutputConsole>(
            new mhl::output::console::OutputConsole());
    output_console->Add(c);
  }
  {
    std::shared_ptr<mhl::output::console::IConsoleOutputable> c =
        std::shared_ptr<mhl::output::console::OutputConsoleVsSjis>(
            new mhl::output::console::OutputConsoleVsSjis());
    output_console->Add(c);
  }

  std::unique_ptr<mhl::debug::stacktrace::IStacktraceable> stacktrace =
      std::unique_ptr<mhl::debug::stacktrace::GetStacktraceWin>(
          new mhl::debug::stacktrace::GetStacktraceWin());

  mhl::debug::assert::MhlAssertion ast(std::move(checker), std::move(processor),
                                       std::move(output_console),
                                       std::move(stacktrace));

  int32_t value1 = 0;
  int32_t value2 = 1;
  ast.Assert(value1 == value2, "テストAssert");
}
