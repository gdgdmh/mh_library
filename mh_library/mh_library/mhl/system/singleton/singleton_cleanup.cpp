#include "singleton_cleanup.hpp"

// static変数実体宣言
std::mutex mhl::system::singleton::SingletonCleanup::mutex_;
int32_t mhl::system::singleton::SingletonCleanup::cleanup_function_size_ = 0;
mhl::system::singleton::SingletonCleanup::CleanupFunction
    mhl::system::singleton::SingletonCleanup::cleanup_function_[kMaxSize];

/**
 * @brief 初期化
 *
 * @return true 成功
 * @return false 失敗
 */
bool mhl::system::singleton::SingletonCleanup::Initialize() {
  std::lock_guard<std::mutex> lock(mutex_);
  if (cleanup_function_size_ != 0) {
    // 既に使用していて初期化しようとした
    return false;
  }
  cleanup_function_size_ = 0;
  for (int32_t i = 0; i < kMaxSize; ++i) {
    cleanup_function_[i] = nullptr;
  }
  return true;
}

/**
 * @brief クリーンアップ関数追加
 *
 * @param function 追加するクリーンアップ関数
 * @return true 追加に成功
 * @return false 追加に失敗
 */
bool mhl::system::singleton::SingletonCleanup::Add(CleanupFunction function) {
  std::lock_guard<std::mutex> lock(mutex_);
  if (cleanup_function_size_ < 0) {
    return false;
  }
  if (cleanup_function_size_ >= kMaxSize) {
    return false;
  }
  cleanup_function_[cleanup_function_size_] = function;
  ++cleanup_function_size_;
  return true;
}

/**
 * @brief クリーンアップ実行
 *
 */
void mhl::system::singleton::SingletonCleanup::Execute() {
  std::lock_guard<std::mutex> lock(mutex_);
  for (int32_t i = cleanup_function_size_ - 1; i >= 0; --i) {
    if (cleanup_function_[i] != nullptr) {
      cleanup_function_[i]();
      cleanup_function_[i] = nullptr;
    }
  }
  cleanup_function_size_ = 0;
}
