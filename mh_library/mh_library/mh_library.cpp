#include <memory>

#include "mhl/test_code/test_mhl.hpp"
#include "mhl/test_program/test_mhl_test_program.hpp"
#include "mhl/output/console/iconsole_outputables.hpp"
#include "mhl/output/console/output_console.hpp"
#include "mhl/output/console/output_consoles.hpp"
#include "mhl/output/console/output_console_vs_sjis.hpp"

int main() {
  std::shared_ptr<mhl::output::console::IConsoleOutputables> output(
      new mhl::output::console::OutputConsoles());
  std::shared_ptr<mhl::output::console::IConsoleOutputable> output_console(
      new mhl::output::console::OutputConsole);
  std::shared_ptr<mhl::output::console::IConsoleOutputable> output_vs(
      new mhl::output::console::OutputConsoleVsSjis);
  output->Add(output_console);
  output->Add(output_vs);


  test_code::TestMhl test(output);
  test.ExecuteUnitTest();

  test_program::TestMhlTestProgram testProgram(output);
  testProgram.ExecuteUnitTest();

  output->PrintLine("--- main test -------------------------------------------------------");
  //test_program::TestCallbackTest ct(output);
  //ct.ExecuteUnitTest();
}
