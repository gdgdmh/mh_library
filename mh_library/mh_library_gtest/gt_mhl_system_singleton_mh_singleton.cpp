
#include <stdint.h>

#include "a_pch.h"
#include "mhl/system/singleton/mh_singleton.hpp"
#include "mhl/system/singleton/singleton_cleanup.hpp"

namespace mhl {
namespace system {
namespace singleton {

/**
 * @brief テストクラス
 *
 */
class SingletonTestCounter {
 public:
  SingletonTestCounter() {}
  virtual ~SingletonTestCounter() {}

  /**
   * @brief 開放処理 わかりやすいように-1を設定
   *
   */
  static void Release() { counter_ = -1; }

  /**
   * @brief 取得
   *
   * @return int32_t 値の取得
   */
  static int32_t Get() { return counter_; }

  /**
   * @brief リセット わかりやすいように0を設定
   *
   */
  static void Reset() { counter_ = 0; }

 private:
  static int32_t counter_;
};
// 静的変数宣言
int32_t SingletonTestCounter::counter_ = 0;

/**
 * @brief テストクラス2つ目
 *
 */
class SingletonTestCounter2 {
 public:
  SingletonTestCounter2() {}
  virtual ~SingletonTestCounter2() {}

  static void Release() {}
};

/**
 * @brief シングルトン追加1
 *
 */
TEST(MhSingleton, Add1) {
  // Arrange
  mhl::system::singleton::SingletonCleanup::Finalize();
  ASSERT_EQ(mhl::system::singleton::SingletonCleanup::Initialize(), true);
  // Act
  SingletonTestCounter& c =
      mhl::system::singleton::MhSingleton<SingletonTestCounter>::GetInstance();
  // Assert
  ASSERT_EQ(mhl::system::singleton::SingletonCleanup::GetSize(), 1);
}

}  // namespace singleton
}  // namespace system
}  // namespace mhl
