#ifndef MHL_TEST_PROGRAM_TEST_MOVE_TEST_HPP_
#define MHL_TEST_PROGRAM_TEST_MOVE_TEST_HPP_

#include <memory>

#include "../test/unittest_base.hpp"
#include "../util/string/std_string_formatter.hpp"

namespace test_program {

class TestMoveDummy {
 public:
  /**
   * @brief Construct a new Test Move Dummy object
   *
   * @param output_console
   */
  TestMoveDummy(std::shared_ptr<mhl::output::console::IConsoleOutputable>& output_console);

 private:
  std::shared_ptr<mhl::output::console::IConsoleOutputable> output_console_;
};

/**
 * @brief std::moveテスト
 *
 */
class TestMoveTest : public mhl::UnitTestBase {
 public:
  /**
   * @brief Construct a new Test Move Test object
   *
   * @param output_console
   */
  TestMoveTest(std::shared_ptr<mhl::output::console::IConsoleOutputable> output_console);

  /**
   * @brief Destroy the Test Move Test object
   *
   */
  virtual ~TestMoveTest();

  /**
   * @brief テスト実行
   *
   */
  void ExecuteUnitTest();

 private:
  /**
   * @brief クラスコンストラクタが呼ばれないテスト
   *
   */
  void TestClassConstractor();

  /**
   * @brief vectorでのテスト
   *
   */
  void TestVector();
};

}  // namespace test_program

#endif  // MHL_TEST_PROGRAM_TEST_MOVE_TEST_HPP_
