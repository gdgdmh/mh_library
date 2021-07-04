
#include <stdint.h>

#include "a_pch.h"
#include "mhl/system/singleton/singleton_cleanup.hpp"

namespace mhl {
namespace system {
namespace singleton {

/**
 * @brief テストクラス
 *
 */
class TestCounter {
 public:
  TestCounter() {}
  virtual ~TestCounter() {}

  static void Release() { counter_ = -1; }
  static int32_t Get() { return counter_; }
  static void Reset() { counter_ = 0; }

 private:
  static int32_t counter_;
};
// 静的変数宣言
int32_t TestCounter::counter_ = 0;

/**
 * @brief テストクラス2つ目
 *
 */
class TestCounter2 {
 public:
  TestCounter2() {}
  virtual ~TestCounter2() {}

  static void Release() {}
};

/**
 * @brief コンストラクタデフォルト値チェック
 *
 */
TEST(SingletonCleanup, ConstructorDefault) {
  // Arrange
  // 念の為
  mhl::system::singleton::SingletonCleanup::Finalize();
  // Act
  // Assert
  ASSERT_EQ(mhl::system::singleton::SingletonCleanup::GetSize(), 0);
}

/**
 * @brief 初期化成功テスト
 *
 */
TEST(SingletonCleanup, InitializeSuccess) {
  // Arrange
  mhl::system::singleton::SingletonCleanup::Finalize();
  // Act
  bool result = mhl::system::singleton::SingletonCleanup::Initialize();
  // Assert
  ASSERT_EQ(result, true);
}

/**
 * @brief 初期化失敗テスト
 *
 */
TEST(SingletonCleanup, InitializeFailure) {
  // Arrange
  mhl::system::singleton::SingletonCleanup::Finalize();
  mhl::system::singleton::SingletonCleanup::Add(&TestCounter::Release);

  // Act
  // Assert
  ASSERT_EQ(mhl::system::singleton::SingletonCleanup::Initialize(), false);
}

/**
 * @brief 終了処理1データ
 *
 */
TEST(SingletonCleanup, Finalize1Data) {
  // Arrange
  mhl::system::singleton::SingletonCleanup::Finalize();
  ASSERT_EQ(mhl::system::singleton::SingletonCleanup::GetSize(), 0);
  mhl::system::singleton::SingletonCleanup::Add(&TestCounter::Release);
  ASSERT_EQ(mhl::system::singleton::SingletonCleanup::GetSize(), 1);
  // Act
  mhl::system::singleton::SingletonCleanup::Finalize();
  // Assert
  ASSERT_EQ(mhl::system::singleton::SingletonCleanup::GetSize(), 0);
}

/**
 * @brief 終了処理2データ
 *
 */
TEST(SingletonCleanup, Finalize2Data) {
  // Arrange
  mhl::system::singleton::SingletonCleanup::Finalize();
  ASSERT_EQ(mhl::system::singleton::SingletonCleanup::GetSize(), 0);
  mhl::system::singleton::SingletonCleanup::Add(&TestCounter::Release);
  mhl::system::singleton::SingletonCleanup::Add(&TestCounter2::Release);
  ASSERT_EQ(mhl::system::singleton::SingletonCleanup::GetSize(), 2);
  // Act
  mhl::system::singleton::SingletonCleanup::Finalize();
  // Assert
  ASSERT_EQ(mhl::system::singleton::SingletonCleanup::GetSize(), 0);
}

/**
 * @brief 取得0テスト
 *
 */
TEST(SingletonCleanup, Get0) {
  // Arrange
  mhl::system::singleton::SingletonCleanup::Finalize();
  ASSERT_EQ(mhl::system::singleton::SingletonCleanup::Initialize(), true);
  // Act
  // Assert
  ASSERT_EQ(mhl::system::singleton::SingletonCleanup::GetSize(), 0);
}

/**
 * @brief 取得1テスト
 *
 */
TEST(SingletonCleanup, Get1) {
  // Arrange
  mhl::system::singleton::SingletonCleanup::Finalize();
  ASSERT_EQ(mhl::system::singleton::SingletonCleanup::Initialize(), true);
  // Act
  mhl::system::singleton::SingletonCleanup::Add(&TestCounter::Release);
  // Assert
  ASSERT_EQ(mhl::system::singleton::SingletonCleanup::GetSize(), 1);
}

/**
 * @brief 取得2テスト
 *
 */
TEST(SingletonCleanup, Get2) {
  // Arrange
  mhl::system::singleton::SingletonCleanup::Finalize();
  ASSERT_EQ(mhl::system::singleton::SingletonCleanup::Initialize(), true);
  // Act
  mhl::system::singleton::SingletonCleanup::Add(&TestCounter::Release);
  mhl::system::singleton::SingletonCleanup::Add(&TestCounter2::Release);
  // Assert
  ASSERT_EQ(mhl::system::singleton::SingletonCleanup::GetSize(), 2);
}

/**
 * @brief 追加1テスト
 *
 */
TEST(SingletonCleanup, Add1) {
  // Arrange
  mhl::system::singleton::SingletonCleanup::Finalize();
  ASSERT_EQ(mhl::system::singleton::SingletonCleanup::Initialize(), true);
  // Act
  mhl::system::singleton::SingletonCleanup::Add(&TestCounter::Release);
  // Assert
  ASSERT_EQ(mhl::system::singleton::SingletonCleanup::GetSize(), 1);
}

// 実行
TEST(SingletonCleanup, Execute) {
  // Arrange
  mhl::system::singleton::SingletonCleanup::Finalize();
  ASSERT_EQ(mhl::system::singleton::SingletonCleanup::Initialize(), true);
  TestCounter::Reset();
  ASSERT_EQ(TestCounter::Get(), 0);
  mhl::system::singleton::SingletonCleanup::Add(&TestCounter::Release);
  // Act
  mhl::system::singleton::SingletonCleanup::Execute();
  ASSERT_EQ(TestCounter::Get(), -1);
}

}  // namespace singleton
}  // namespace system
}  // namespace mhl
