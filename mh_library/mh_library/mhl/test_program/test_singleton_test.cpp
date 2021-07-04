#include "test_singleton_test.hpp"

#include "../system/singleton/singleton_cleanup.hpp"

/**
 * コンストラクタ
 */
test_program::TestSingletonTest::TestSingletonTest(
    std::shared_ptr<mhl::output::console::IConsoleOutputables> output_console)
    : UnitTestBase(output_console) {}

/**
 * デストラクタ
 */
test_program::TestSingletonTest::~TestSingletonTest() {}

void test_program::TestSingletonTest::ExecuteUnitTest() { TestCleanup(); }

/**
 * @brief クリーンアップのテスト
 *
 */
void test_program::TestSingletonTest::TestCleanup() {
  mhl::system::singleton::SingletonCleanup sc;
  if (sc.Initialize()) {
    output_console_->PrintLine("クリーンアップ初期化成功");
  }

  sc.Add([this]() { output_console_->PrintLine("Add1"); });

  sc.Add([this]() { output_console_->PrintLine("Add2"); });

  sc.Execute();

  sc.Finalize();
}
