#include "TestExecuteMethod.hpp"

/**
 * コンストラクタ
 */
test::TestExecuteMethod::TestExecuteMethod() : on_exec_(&test::TestExecuteMethod::Initialize) {
}

/**
 * デストラクタ
 */
test::TestExecuteMethod::~TestExecuteMethod() {
}

void test::TestExecuteMethod::Task() {
}

mh_library::IExecuteMethod<test::TestExecuteMethod> test::TestExecuteMethod::Initialize() {
  return NULL;
  //return &test::TestExecuteMethod::Load;
}

mh_library::IExecuteMethod<test::TestExecuteMethod> test::TestExecuteMethod::Load() {
  return NULL;
  //  return &test::TestExecuteMethod::Main;
}

mh_library::IExecuteMethod<test::TestExecuteMethod> test::TestExecuteMethod::Main() {
  return NULL;
  // return &test::TestExecuteMethod::Main;
}
