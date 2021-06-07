
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
  // Arrange
  mhl::debug::assert::AssertDummy assert_dummy;
  // Act

  // Assert
  EXPECT_EQ(assert_dummy.IsCalled(), false);
}

/**
 * @brief アサーション処理がされた際にtrueが返されるか
 *
 */
TEST(AssertDummy, AssertTrue) {
  // Arrange
  mhl::debug::assert::AssertDummy assert_dummy;
  // Act
  assert_dummy.Assert();
  // Assert
  EXPECT_EQ(assert_dummy.IsCalled(), true);
}

/**
 * @brief リセット処理が呼ばれた際にfalseが返されるか
 *
 */
TEST(AssertDummy, ResetFalse) {
  // Arrange
  mhl::debug::assert::AssertDummy assert_dummy;
  // Act
  assert_dummy.Reset();
  // Assert
  EXPECT_EQ(assert_dummy.IsCalled(), false);
}

/**
 * @brief Assertが呼ばれた後にリセットしたらfalseが返されるか
 *
 */
TEST(AssertDummy, AssertAfterResetFalse) {
  // Arrange
  mhl::debug::assert::AssertDummy assert_dummy;
  assert_dummy.Assert();
  EXPECT_EQ(assert_dummy.IsCalled(), true);
  // Act
  assert_dummy.Reset();
  // Assert
  EXPECT_EQ(assert_dummy.IsCalled(), false);
}

}  // namespace assert_dummy
}  // namespace assert
}  // namespace debug
}  // namespace mhl
