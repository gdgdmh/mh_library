#include "TestExecuteMethod.hpp"

/**
 * コンストラクタ
 */
test::TestExecuteMethod::TestExecuteMethod(std::shared_ptr<mh_library::IOutputConsole> output_console)
  : UnitTestBase(output_console), on_exec_(&test::TestExecuteMethod::Initialize), scene_(SCENE::kInitialize) {
}

/**
 * デストラクタ
 */
test::TestExecuteMethod::~TestExecuteMethod() {
}

void test::TestExecuteMethod::ExecuteUnitTest() {
  AssertEquals(scene_ == SCENE::kInitialize, "TestExecuteMethod not kInitialize");
  Task();
  AssertEquals(scene_ == SCENE::kInitialize, "TestExecuteMethod not kInitialize(2)");
  Task();
  AssertEquals(scene_ == SCENE::kLoad, "TestExecuteMethod not kLoad");
  Task();
  AssertEquals(scene_ == SCENE::kMain, "TestExecuteMethod not kMain");
  Task();
  AssertEquals(scene_ == SCENE::kMain, "TestExecuteMethod not kMain(2)");
}

void test::TestExecuteMethod::Task() {
  on_exec_ = on_exec_.executeMethod(this);
}

mh_library::IExecuteMethod<test::TestExecuteMethod> test::TestExecuteMethod::Initialize() {
  scene_ = SCENE::kInitialize;
  return &test::TestExecuteMethod::Load;
}

mh_library::IExecuteMethod<test::TestExecuteMethod> test::TestExecuteMethod::Load() {
  scene_ = SCENE::kLoad;
  return &test::TestExecuteMethod::Main;
}

mh_library::IExecuteMethod<test::TestExecuteMethod> test::TestExecuteMethod::Main() {
  scene_ = SCENE::kMain;
  return &test::TestExecuteMethod::Main;
}
