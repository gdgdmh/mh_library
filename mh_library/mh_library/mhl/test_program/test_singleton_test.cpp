#include "test_singleton_test.hpp"

#include "../system/singleton/mh_singleton.hpp"
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

void test_program::TestSingletonTest::ExecuteUnitTest() {
  if (!TestCleanup()) {
    // クリーンアップ失敗ということは使っている可能性がある
    // このままシングルトンテスト続行すると予想しない自体になる可能性があるので中断
    return;
  }
  TestSingleton();
}

/**
 * @brief クリーンアップのテスト
 *
 * @return true 成功
 * @return false 失敗
 */
bool test_program::TestSingletonTest::TestCleanup() {
  mhl::system::singleton::SingletonCleanup sc;
  if (sc.Initialize()) {
    output_console_->PrintLine("クリーンアップ初期化成功");
  } else {
    // 既に使われている
    output_console_->PrintLine("クリーンアップ初期化失敗");
    return false;
  }
  sc.Add([this]() { output_console_->PrintLine("Singleton Test Add1"); });
  sc.Add([this]() { output_console_->PrintLine("Singleton Test Add2"); });
  sc.Execute();
  sc.Finalize();
  return true;
}

/**
 * @brief シングルトンテスト
 *
 */
void test_program::TestSingletonTest::TestSingleton() {
  SingletonTest& s =
      mhl::system::singleton::MhSingleton<SingletonTest>::GetInstance();

  mhl::system::singleton::SingletonCleanup::Execute();
  mhl::system::singleton::SingletonCleanup::Finalize();
}