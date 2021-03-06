﻿#include "test_mhl.hpp"

#include "../test/unittest_execute_list.hpp"
#include "../output/console/ioutput_console.hpp"
#include "../output/console/output_console.hpp"
#include "test_execute_method.hpp"
#include "test_scene_stack.hpp"
#include "test_subject.hpp"
#include "bit/test_bit_control_uint32.hpp"
#include "data/test_data_collection.hpp"


/**
 * コンストラクタ
 */
test_code::TestMhl::TestMhl(
    std::shared_ptr<mhl::output::console::IOutputConsole> output_console)
    : UnitTestBase(output_console) {}

/**
 * デストラクタ
 */
test_code::TestMhl::~TestMhl() {}

void test_code::TestMhl::ExecuteUnitTest() {
  mhl::UnitTestExecuteList list;
  std::shared_ptr<mhl::output::console::IOutputConsole> console(
      new mhl::output::console::OutputConsole());
  list.Add(std::shared_ptr<test_code::TestDataCollection>(
      new test_code::TestDataCollection(console)));
  list.Add(std::shared_ptr<test_code::TestExecuteMethod>(
      new test_code::TestExecuteMethod(console)));
  list.Add(std::shared_ptr<test_code::TestSubject>(
      new test_code::TestSubject(console)));
  list.Add(std::shared_ptr<test_code::TestSceneStack>(
      new test_code::TestSceneStack(console)));
  // bit
  list.Add(std::shared_ptr<test_code::TestBitControlUint32>(new test_code::TestBitControlUint32(console)));
  // execute test
  if (!list.Execute()) {
    AssertEquals(false, "TestMhl::ExecuteUnitTest failure");
  }
}
