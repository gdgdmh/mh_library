#ifndef MHL_TEST_CODE_TESTINSTANCEOFTEST_HPP_
#define MHL_TEST_CODE_TESTINSTANCEOFTEST_HPP_

#include <memory>
#include <mhl/test/unittest_base.hpp>

namespace test_program {

/**
 * @brief 攻撃インターフェース
 */
class IAttack {
 public:
  virtual ~IAttack() {}
  virtual void Attack(std::shared_ptr<mhl::output::console::IConsoleOutputables>
                          output_console) = 0;
};

/**
 * @brief スキル攻撃インターフェース
 */
class ISkillAttack {
 public:
  virtual ~ISkillAttack() {}
  virtual void SkillAttack(
      std::shared_ptr<mhl::output::console::IConsoleOutputables>
          output_console) = 0;
};

/**
 * @brief 敵基底クラス
 */
class Enemy : public IAttack {
 public:
  Enemy() {}

  virtual void Attack(std::shared_ptr<mhl::output::console::IConsoleOutputables>
                          output_console) {
    output_console->PrintLine("Enemy Attack");
  }
};

/**
 * @brief スキルあり敵クラス
 *
 */
class LightEnemy : public Enemy, ISkillAttack {
 public:
  LightEnemy() {}

  void Attack(std::shared_ptr<mhl::output::console::IConsoleOutputables>
                  output_console) {
    output_console->PrintLine("LightEnemy Attack");
  }

  void SkillAttack(std::shared_ptr<mhl::output::console::IConsoleOutputables>
                       output_console) {
    output_console->PrintLine("LightEnemy SkillAttack");
  }
};

/**
 * @brief スキルなし敵クラス
 *
 */
class DarkEnemy : public Enemy {
 public:
  DarkEnemy() {}

  void Attack(std::shared_ptr<mhl::output::console::IConsoleOutputables>
                  output_console) {
    output_console->PrintLine("dark attack");
  }
};

// テンプレート
template <typename Base, typename T>
inline bool instanceOf(const T*) {
  return std::is_base_of<Base, T>::value;
}

// JavaでいうinstanceOfのテスト
class TestInstanceOfTest : public mhl::UnitTestBase {
 public:
  /**
   * コンストラクタ
   */
  TestInstanceOfTest(std::shared_ptr<mhl::output::console::IConsoleOutputables>
                         output_console);

  /**
   * デストラクタ
   */
  virtual ~TestInstanceOfTest();

  /**
   * @brief ユニットテスト実行
   */
  void ExecuteUnitTest();
};

}  // namespace test_program

#endif  // TEST_TESTINSTANCEOFTEST_HPP_
