#include <memory>
#include "mh_library/util/output/IOutputConsole.hpp"
#include "mh_library/util/output/OutputConsole.hpp"
#include "mh_library/exception/UnitTestException.hpp"
#include "mh_library/test/UnitTestExecuteList.hpp"
#include "test/TestExecuteMethod.hpp"

int main() {
  mh_library::UnitTestExecuteList list;
  std::shared_ptr<mh_library::IOutputConsole> console(new mh_library::OutputConsole());
  list.Add(std::shared_ptr<test::TestExecuteMethod>(new test::TestExecuteMethod(console)));
  if (!list.Execute()) {
      return 1;
  }
  return 0;
}
