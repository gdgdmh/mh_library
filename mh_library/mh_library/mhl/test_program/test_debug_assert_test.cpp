﻿#include "test_debug_assert_test.hpp"

#include "../debug/assert/mhl_assert.hpp"
#include "../debug/assert/assert_checker.hpp"
#include "../debug/assert/assert_process.hpp"
#include "../output/console/output_consoles.hpp"
#include "../output/console/output_console.hpp"
#include "../output/console/output_console_vs_sjis.hpp"

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

  std::unique_ptr<mhl::debug::assert::IAssertChecker> checker(new mhl::debug::assert::AssertChecker());
  std::unique_ptr<mhl::debug::assert::IAssertProcessor> processor(new mhl::debug::assert::AssertProcess());
  std::unique_ptr<mhl::output::console::IConsoleOutputables> output_console(new mhl::output::console::OutputConsoles());

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
  
  mhl::debug::assert::MhlAssert ast(std::move(checker), std::move(processor), std::move(output_console));

  int32_t value1 = 0;
  int32_t value2 = 1;
  ast.Assert(value1 == value2, "テストAssert");

}
