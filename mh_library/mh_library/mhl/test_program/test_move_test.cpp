#include "test_move_test.hpp"

/**
 * @brief Construct a new Test Move Dummy object
 *
 * @param output_console
 */
test_program::TestMoveDummy::TestMoveDummy(
    std::shared_ptr<mhl::output::console::IConsoleOutputables>& output_console) {
  output_console_ = output_console;
  output_console_->PrintLine("TestMoveDummy Constructor");
}

/**
 * コンストラクタ
 */
test_program::TestMoveTest::TestMoveTest(
    std::shared_ptr<mhl::output::console::IConsoleOutputables> output_console)
    : UnitTestBase(output_console) {}

/**
 * デストラクタ
 */
test_program::TestMoveTest::~TestMoveTest() {}

/**
 * @brief テスト実行
 *
 */
void test_program::TestMoveTest::ExecuteUnitTest() {
  output_console_->PrintLine("--- TestMoveTest ---");
  TestClassConstractor();
  TestVector();
  output_console_->PrintLine("------------------------");
}

/**
 * @brief クラスコンストラクタが呼ばれないテスト
 *
 */
void test_program::TestMoveTest::TestClassConstractor() {
  output_console_->Print("dummy1 ");
  std::shared_ptr<TestMoveDummy> dummy1(new TestMoveDummy(output_console_));
  // dummy2がmoveされたときTestMoveDummyのコンストラクタは呼ばれない
  // dummy1とdummy2は同じポインタを指してる
  std::shared_ptr<TestMoveDummy>&& dummy2 = std::move(dummy1);
  AssertEquals(dummy1 == dummy2, "dummy1 not equals dummy2");
}

/**
 * @brief vectorでのテスト
 *
 */
void test_program::TestMoveTest::TestVector() {
  std::vector<TestMoveDummy> dummyV;
  output_console_->Print("dummyA ");
  TestMoveDummy dummyA(output_console_);
  dummyV.emplace_back(dummyA);
  output_console_->Print("dummyB ");
  TestMoveDummy dummyB(output_console_);
  dummyV.emplace_back(dummyB);
  // vectorのコピーが発生しない
  std::vector<TestMoveDummy>&& tmp = std::move(dummyV);
}
