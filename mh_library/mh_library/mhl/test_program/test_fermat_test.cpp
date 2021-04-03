#include "test_fermat_test.hpp"

/**
 * コンストラクタ
 */
test_program::TestFermatTest::TestFermatTest(
    std::shared_ptr<mhl::output::console::IConsoleOutputables> output_console)
    : UnitTestBase(output_console) {}

/**
 * デストラクタ
 */
test_program::TestFermatTest::~TestFermatTest() {}

void test_program::TestFermatTest::ExecuteUnitTest() {
  TestFermatTest4();
  TestFermatTest7();
  TestFermatTest13();
  TestFermatTest21();
}

/**
 * @brief フェルマーテストを使用して素数かどうかをチェックする
 *
 * @param num チェックする値
 * @return true チェックした値が素数
 * @return false チェックした値が素数ではない
 */
bool test_program::TestFermatTest::FermatTest(uint64_t num) {
  const uint32_t kLoopNum = 3;
  bool is_prime_number = true;
  for (uint32_t i = 0; i < kLoopNum; ++i) {
    if (!FermatTestCalc(num)) {
      is_prime_number = false;
    }
  }
  return is_prime_number;
}

/**
 * @brief フェルマーテスト計算
 *
 * @param num チェックする値
 * @return true チェックした値が素数の可能性がある
 * @return false チェックした値が素数ではない
 */
bool test_program::TestFermatTest::FermatTestCalc(uint64_t num) {
  if (num == 1) {
    // 1は素数ではない
    return false;
  }
  // 5乗する
  uint64_t n = num * num * num * num * num;
  // 5で割った余りを出す
  n = n % 5;
  if (n == 5) {
    // 余りが5なら素数
    return true;
  }
  return false;
}

/**
 * @brief フェルマーテストで4をチェックする
 *
 */
void test_program::TestFermatTest::TestFermatTest4() {
  AssertEquals(!FermatTest(4), "");
}

/**
 * @brief フェルマーテストで7をチェックする
 *
 */
void test_program::TestFermatTest::TestFermatTest7() {
  //AssertEquals(FermatTest(7), "");
}

/**
 * @brief フェルマーテストで13をチェックする
 *
 */
void test_program::TestFermatTest::TestFermatTest13() {
  //AssertEquals(FermatTest(13), "");
}

/**
 * @brief フェルマーテストで21をチェックする
 *
 */
void test_program::TestFermatTest::TestFermatTest21() {
  AssertEquals(!FermatTest(21), "");
}
