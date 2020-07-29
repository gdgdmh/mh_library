﻿#include "test_mhl.hpp"

#include "../test/unittest_execute_list.hpp"
#include "../util/output/ioutput_console.hpp"
#include "../util/output/output_console.hpp"
#include "test_cpp_new_function_test.hpp"
#include "test_execute_method.hpp"
#include "test_instance_of_test.hpp"
#include "test_scene_stack.hpp"
#include "test_subject.hpp"

/**
 * コンストラクタ
 */
test::TestMhl::TestMhl(std::shared_ptr<mhl::IOutputConsole> output_console)
    : UnitTestBase(output_console) {}

/**
 * デストラクタ
 */
test::TestMhl::~TestMhl() {}

void test::TestMhl::ExecuteUnitTest() {
  mhl::UnitTestExecuteList list;
  std::shared_ptr<mhl::IOutputConsole> console(new mhl::OutputConsole());
  list.Add(std::shared_ptr<test::TestCppNewFunctionTest>(
      new test::TestCppNewFunctionTest(console)));
  list.Add(std::shared_ptr<test::TestExecuteMethod>(
      new test::TestExecuteMethod(console)));
  list.Add(std::shared_ptr<test::TestSubject>(new test::TestSubject(console)));
  list.Add(std::shared_ptr<test::TestInstanceOfTest>(
      new test::TestInstanceOfTest(console)));
  list.Add(std::shared_ptr<test::TestSceneStack>(new test::TestSceneStack(console)));
  if (!list.Execute()) {
    AssertEquals(false, "TestMhl::ExecuteUnitTest failure");
  }
}
