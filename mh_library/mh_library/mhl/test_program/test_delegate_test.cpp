#include "test_delegate_test.hpp"

/**
 * コンストラクタ
 */
test_program::TestDelegateTest::TestDelegateTest(
    std::shared_ptr<mhl::IOutputConsole> output_console)
    : UnitTestBase(output_console) {}

/**
 * デストラクタ
 */
test_program::TestDelegateTest::~TestDelegateTest() {}

void test_program::TestDelegateTest::ExecuteUnitTest() {
  output_console_->PrintLine("--- TestDelegateTest ---");
  TestTukuroDoorBell bell(output_console_);
  {
    // 元のクラスを作成
    std::shared_ptr<TestDog> d(new TestDog(output_console_));
    std::shared_ptr<TestCat> c(new TestCat(output_console_));
    // デリゲートを作成する
    std::shared_ptr<TestTukuroDelegateBase> dog =
        TestTukuroDelegate<TestDog>::createDelegator(d, &TestDog::woof);
    std::shared_ptr<TestTukuroDelegateBase> cat =
        TestTukuroDelegate<TestCat>::createDelegator(c, &TestCat::meow);
    // 登録
    bell.setOnOpenDoorHandler(dog);
    bell.setOnOpenDoorHandler(cat);
  }
  // イベント発生
  bell.onOpenDoor();
  output_console_->PrintLine("------------------------");
}
