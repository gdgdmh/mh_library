#include <memory>
#include "mh_library/util/output/IOutputConsole.hpp"
#include "mh_library/util/output/OutputConsole.hpp"
#include "mh_library/exception/UnitTestException.hpp"

int main() {
  std::shared_ptr<mh_library::IOutputConsole> console(new mh_library::OutputConsole());
  console->PrintLine("HelloWorld");
  // UnitTestExceptionTest
  try {
      int value = 1000;
      if (value > 10) {
          throw mh_library::UnitTestException("value error", 1);
      }
  } catch (const mh_library::UnitTestException& e) {
    console->PrintLine(e.what());
  }

  return 0;
}
