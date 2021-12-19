#ifndef MHL_TEST_FERMAT_TEST_HPP_
#define MHL_TEST_FERMAT_TEST_HPP_

#include <stdint.h>

#include <memory>
#include <mhl/test/unittest_base.hpp>

namespace test_program {

// フェルマーテスト
class TestFermatTest : public mhl::UnitTestBase {
 public:
  /**
   * コンストラクタ
   */
  TestFermatTest(std::shared_ptr<mhl::output::console::IConsoleOutputables>
                     output_console);

  /**
   * デストラクタ
   */
  virtual ~TestFermatTest();

  void ExecuteUnitTest();

 private:
  /**
   * @brief フェルマーテストを使用して素数かどうかをチェックする
   *
   * @param num チェックする値
   * @return true チェックした値が素数(100%ではない)
   * @return false チェックした値が素数ではない
   */
  bool FermatTest(uint64_t num);

  /**
   * @brief フェルマーテスト計算
   *
   * @param num チェックする値
   * @return true チェックした値が素数の可能性がある
   * @return false チェックした値が素数ではない
   */
  bool FermatTestCalc(uint64_t num);

  /**
   * @brief フェルマーテストで4をチェックする
   *
   */
  void TestFermatTest4();

  /**
   * @brief フェルマーテストで7をチェックする
   *
   */
  void TestFermatTest7();

  /**
   * @brief フェルマーテストで13をチェックする
   *
   */
  void TestFermatTest13();

  /**
   * @brief フェルマーテストで21をチェックする
   *
   */
  void TestFermatTest21();
};

}  // namespace test_program

#endif  // MHL_TEST_FERMAT_TEST_HPP_
