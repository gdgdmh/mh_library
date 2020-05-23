#include "TestCppNewFunctionTest.hpp"

/**
 * コンストラクタ
 */
test::TestCppNewFunctionTest::TestCppNewFunctionTest(std::shared_ptr<mhl::IOutputConsole> output_console)
  : UnitTestBase(output_console) {
}

/**
 * デストラクタ
 */
test::TestCppNewFunctionTest::~TestCppNewFunctionTest() {
}

void test::TestCppNewFunctionTest::ExecuteUnitTest() {
  TestCpp11Nullptr();
  TestUniformInitialization001();
  TestUniformInitialization002();
  TestUniformInitialization003();
  TestUniformInitialization004();
}

/**
 * C++11のnullptrテスト
 */
void test::TestCppNewFunctionTest::TestCpp11Nullptr() {
  char* p = nullptr;
  AssertEquals(p == nullptr, "TestCppNewFunctionTest::TestCpp11Nullptr() not nullptr");
}

/**
 * 統一初期化記法
 */
void test::TestCppNewFunctionTest::TestUniformInitialization001() {
  const int VALUE = 3;
  int x { VALUE };
  AssertEquals(x == VALUE, "TestCppNewFunctionTest::TestUniformInitialization001 x not 3");
}

/**
 * 統一初期化記法case002
 */
void test::TestCppNewFunctionTest::TestUniformInitialization002() {
  const int VALUE1 = 10;
  const int VALUE2 = 11;
  const int VALUE3 = 12;
  const int VALUE4 = 13;
  int x[] { VALUE1, VALUE2, VALUE3, VALUE4 };
  AssertEquals(x[0] == VALUE1, "TestCppNewFunctionTest::TestUniformInitialization002 x[0] not VALUE1");
  AssertEquals(x[1] == VALUE2, "TestCppNewFunctionTest::TestUniformInitialization002 x[1] not VALUE2");
  AssertEquals(x[2] == VALUE3, "TestCppNewFunctionTest::TestUniformInitialization002 x[2] not VALUE3");
  AssertEquals(x[3] == VALUE4, "TestCppNewFunctionTest::TestUniformInitialization002 x[3] not VALUE4");
}

/**
 * 統一初期化記法case003
 */
void test::TestCppNewFunctionTest::TestUniformInitialization003() {
  struct Struct {
    int a;
    int b;
  };
  const int VALUE_A = 11;
  const int VALUE_B = 12;
  Struct x { VALUE_A, VALUE_B };
  AssertEquals(x.a == VALUE_A, "TestCppNewFunctionTest::TestUniformInitialization003 x.a not VALUE_A");
  AssertEquals(x.b == VALUE_B, "TestCppNewFunctionTest::TestUniformInitialization003 x.b not VALUE_B");
}

/**
 * 統一初期化記法case004
 */
void test::TestCppNewFunctionTest::TestUniformInitialization004() {
  const int VALUE1 = 101;
  const int VALUE2 = 102;
  std::vector<int> x = { VALUE1, VALUE2 };
  AssertEquals(x[0] == VALUE1, "TestCppNewFunctionTest::TestUniformInitialization003 x[0] not VALUE1");
  AssertEquals(x[1] == VALUE2, "TestCppNewFunctionTest::TestUniformInitialization003 x[1] not VALUE2");
}
