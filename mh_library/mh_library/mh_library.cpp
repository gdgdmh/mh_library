#include <memory>

#include "mhl/test_code/test_mhl.hpp"
#include "mhl/util/output/output_console.hpp"

int main() {
  std::shared_ptr<mhl::IOutputConsole> output(new mhl::OutputConsole());
  test::TestMhl test(output);
  test.ExecuteUnitTest();
}
