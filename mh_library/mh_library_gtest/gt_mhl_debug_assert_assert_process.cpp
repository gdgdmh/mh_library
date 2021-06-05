
#include "a_pch.h"
#include "mhl/debug/assert/assert_dummy.hpp"

namespace mhl {
namespace debug {
namespace assert {
namespace assert_dummy {

/**
 * @brief コンストラクタデフォルト値チェック
 *
 */
TEST(AssertDummy, ConstructorDefault) {
  mhl::debug::assert::AssertDummy assert_dummy;
  EXPECT_EQ(assert_dummy.IsCalled(), false);
}

/**
 * @brief アサーション処理がされた際にtrueが返されるか
 *
 */
TEST(AssertDummy, AssertTrue) {
  mhl::debug::assert::AssertDummy assert_dummy;
  assert_dummy.Assert();
  EXPECT_EQ(assert_dummy.IsCalled(), true);
}

/**
 * @brief リセット処理が呼ばれた際にfalseが返されるか
 *
 */
TEST(AssertDummy, ResetFalse) {
  mhl::debug::assert::AssertDummy assert_dummy;
  assert_dummy.Reset();
  EXPECT_EQ(assert_dummy.IsCalled(), false);
}

/**
 * @brief Assertが呼ばれた後にリセットしたらfalseが返されるか
 *
 */
TEST(AssertDummy, AssertAfterResetFalse) {
  mhl::debug::assert::AssertDummy assert_dummy;
  assert_dummy.Assert();
  EXPECT_EQ(assert_dummy.IsCalled(), true);
  assert_dummy.Reset();
  EXPECT_EQ(assert_dummy.IsCalled(), false);
}

}  // namespace assert_dummy
}  // namespace assert
}  // namespace debug
}  // namespace mhl
