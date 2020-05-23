#include <memory>
#include "mhl/util/output/IOutputConsole.hpp"
#include "mhl/util/output/OutputConsole.hpp"
#include "mhl/exception/UnitTestException.hpp"
#include "mhl/test/UnitTestExecuteList.hpp"
#include "test/TestCppNewFunctionTest.hpp"
#include "test/TestExecuteMethod.hpp"
#include "test/TestSubject.hpp"

int main() {
  mhl::UnitTestExecuteList list;
  std::shared_ptr<mhl::IOutputConsole> console(new mhl::OutputConsole());
  list.Add(std::shared_ptr<test::TestCppNewFunctionTest>(new test::TestCppNewFunctionTest(console)));
  list.Add(std::shared_ptr<test::TestExecuteMethod>(new test::TestExecuteMethod(console)));
  list.Add(std::shared_ptr<test::TestSubject>(new test::TestSubject(console)));
  if (!list.Execute()) {
      return 1;
  }
  return 0;
}
