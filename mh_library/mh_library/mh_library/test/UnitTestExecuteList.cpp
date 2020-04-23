#include "UnitTestExecuteList.hpp"

#include "../exception/UnitTestException.hpp"
#include "../util/output/IOutputConsole.hpp"
#include "../util/output/OutputConsole.hpp"

mh_library::UnitTestExecuteList::UnitTestExecuteList() {
}

mh_library::UnitTestExecuteList::~UnitTestExecuteList() {
}

void mh_library::UnitTestExecuteList::Add(const std::shared_ptr<UnitTestBase>& unit_test) {
  unit_test_list.push_back(unit_test);
}

bool mh_library::UnitTestExecuteList::Execute() {
  std::shared_ptr<IOutputConsole> console(new OutputConsole());
  try {
    console->PrintLine("--- UnitTestExecuteList start ---------------------------");
    for (auto it = unit_test_list.begin(); it != unit_test_list.end(); ++it) {
      (*it)->ExecuteUnitTest();
    }
  } catch (const mh_library::UnitTestException& e) {
    // 単体テスト失敗の例外
    console->PrintLine("UnitTestExecuteList::Execute failure");
    console->PrintLine(e.what());
    return false;
  }
  console->PrintLine("--- UnitTestExecuteList end -----------------------------");
  return true;
}