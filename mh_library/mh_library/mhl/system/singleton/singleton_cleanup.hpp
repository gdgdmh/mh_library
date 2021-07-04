#ifndef MHL_SYSTEM_SINGLETON_SINGLETON_CLEANUP_HPP_
#define MHL_SYSTEM_SINGLETON_SINGLETON_CLEANUP_HPP_

#include <stdint.h>

#include <functional>
#include <mutex>

namespace mhl {

namespace system {

namespace singleton {

/**
 * @brief シングルトンクリーンアップ
 * MhSingletonで使用するため、単体では使用しないこと
 * 例外はユニットテスト時のみ
 */
class SingletonCleanup {
 public:
  // クリーンアップ関数の最大登録数(必要であれば増やすこと)
  static constexpr int32_t kMaxSize = 256;

 public:
  /**
   * @brief クリーンアップ関数
   *
   */
  using CleanupFunction = std::function<void(void)>;

  /**
   * @brief 初期化
   *
   * @return true 成功
   * @return false 失敗(既にクリーンアップ関数が追加されてるのでFinalize)
   */
  static bool Initialize();

  /**
   * @brief 終了処理
   */
  static void Finalize();

  /**
   * @brief クリーンアップ関数追加
   *
   * @param function 追加するクリーンアップ関数
   * @return true 追加に成功
   * @return false 追加に失敗
   */
  static bool Add(CleanupFunction function);

  /**
   * @brief クリーンアップ実行
   *
   */
  static void Execute();

  /**
   * @brief クリーンアップ関数の取得
   *
   * @param index 取得するクリーンアップ関数のindex
   * @return const mhl::system::singleton::SingletonCleanup::CleanupFunction*
   * クリーンアップ関数
   */
  static const mhl::system::singleton::SingletonCleanup::CleanupFunction*
  GetFunction(int32_t index);

  /**
   * @brief サイズ取得
   *
   * @return int32_t 登録されてるクリーンアップ関数の数
   */
  static int32_t GetSize();

 private:
  // 排他処理用のmutex
  static std::mutex mutex_;
  // クリーンアップ関数の数
  static int32_t cleanup_function_size_;
  // クリーンアップ関数
  static mhl::system::singleton::SingletonCleanup::CleanupFunction
      cleanup_function_[kMaxSize];
};

}  // namespace singleton

}  // namespace system

}  // namespace mhl

#endif  // MHL_SYSTEM_SINGLETON_SINGLETON_CLEANUP_HPP_
