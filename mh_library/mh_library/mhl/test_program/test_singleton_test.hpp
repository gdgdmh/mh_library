#ifndef MHL_TEST_PROGRAM_TEST_SINGLETON_TEST_HPP_
#define MHL_TEST_PROGRAM_TEST_SINGLETON_TEST_HPP_

#include "../test/unittest_base.hpp"

namespace test_program {

class SingletonTest {
 public:
  SingletonTest() : value_(0) {}
  virtual ~SingletonTest() {}

 public:
  /**
   * @brief クリーンアップ処理
   *
   */
  void Cleanup() { value_ = -1; }

  /**
   * @brief 値のリセット
   *
   */
  void Reset() { value_ = 0; }

  /**
   * @brief 値取得処理
   *
   * @return int32_t 値
   */
  int32_t Get() { return value_; }

 private:
  int32_t value_;
};

/**
 * @brief シングルトンのテスト
 *
 */
class TestSingletonTest : public mhl::UnitTestBase {
 public:
  /**
   * コンストラクタ
   */
  TestSingletonTest(std::shared_ptr<mhl::output::console::IConsoleOutputables>
                        output_console);

  /**
   * デストラクタ
   */
  virtual ~TestSingletonTest();

  void ExecuteUnitTest();

  /**
   * @brief クリーンアップのテスト
   *
   * @return true 成功
   * @return false 失敗
   */
  bool TestCleanup();

  /**
   * @brief シングルトンテスト
   *
   */
  void TestSingleton();

 private:
};

}  // namespace test_program

#endif  // MHL_TEST_PROGRAM_TEST_SINGLETON_TEST_HPP_
