#include <memory>

#include "mhl/test_code/test_mhl.hpp"
#include "mhl/util/output/output_console.hpp"
// test
#include "mhl/test_program/test_callback_test.hpp"

int main() {
  std::shared_ptr<mhl::IOutputConsole> output(new mhl::OutputConsole());
  test_code::TestMhl test(output);
  test.ExecuteUnitTest();

  output->PrintLine("--- main test -------------------------------------------------------");
  test_program::TestCallbackTest ct(output);
  ct.ExecuteUnitTest();
}
