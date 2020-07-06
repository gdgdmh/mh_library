#include <memory>

#include "mhl/test_code/TestMhl.hpp"
#include "mhl/util/output/OutputConsole.hpp"

int main() {
  std::shared_ptr<mhl::IOutputConsole> output(new mhl::OutputConsole());
  test::TestMhl test(output);
  test.ExecuteUnitTest();
}
