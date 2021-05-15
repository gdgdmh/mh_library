#include "test_stacktrace_test.hpp"

#include "../debug/stacktrace/get_stacktrace_win.hpp"
#include "../debug/stacktrace/istacktraceable.hpp"

/**
 * コンストラクタ
 */
test_program::TestStacktraceTest::TestStacktraceTest(
    std::shared_ptr<mhl::output::console::IConsoleOutputables> output_console)
    : UnitTestBase(output_console) {}

/**
 * デストラクタ
 */
test_program::TestStacktraceTest::~TestStacktraceTest() {}

void test_program::TestStacktraceTest::ExecuteUnitTest() {
  std::shared_ptr<mhl::debug::stacktrace::IStacktraceable> stacktrace(
      new mhl::debug::stacktrace::GetStacktraceWin());
  mhl::debug::stacktrace::StacktraceInfo info;
  stacktrace->GetStacktrace(info);
  std::string s;
  stacktrace->ToStringStacktrace(s, info);

  output_console_->Print(s);
}
