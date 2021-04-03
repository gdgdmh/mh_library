#include "test_component_test.hpp"

/**
 * @brief Construct a new Test Component Test object
 *
 * @param output_console コンソール出力クラス
 */
test_program::TestComponentTest::TestComponentTest(
    std::shared_ptr<mhl::output::console::IConsoleOutputables> output_console)
    : UnitTestBase(output_console) {}

/**
 * @brief Destroy the Test Component Test object
 *
 */
test_program::TestComponentTest::~TestComponentTest() {}

void test_program::TestComponentTest::ExecuteUnitTest() {
  TestComponentManager componentManager;
  {
    std::shared_ptr<TestAttackComponent> ac(new TestAttackComponent(1));
    componentManager.Add(ac);

    // 登録してないIDのコンポーネントを取得
    {
      std::shared_ptr<TestComponentBase> empty = componentManager.Get(0);
      AssertEquals(empty.get() == nullptr, "");
    }
    // 登録したIDのコンポーネントを取得
    {
      std::shared_ptr<TestComponentBase> component = componentManager.Get(1);
      AssertEquals(component.get() != nullptr, "");
    }
  }
}
