#include <memory>

#include "mhl/test_code/test_mhl.hpp"
#include "mhl/util/output/output_console.hpp"
// test
#include "mhl/test_code/test_callback_test.hpp"

int main() {
  std::shared_ptr<mhl::IOutputConsole> output(new mhl::OutputConsole());
  test::TestMhl test(output);
  test.ExecuteUnitTest();

  output->PrintLine("--- main test -------------------------------------------------------");
  test::TestCallbackTest ct(output);
  ct.ExecuteUnitTest();
}
