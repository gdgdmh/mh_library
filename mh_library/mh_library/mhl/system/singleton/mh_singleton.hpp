#ifndef MHL_SYSTEM_SINGLETON_MH_SINGLETON_HPP_
#define MHL_SYSTEM_SINGLETON_MH_SINGLETON_HPP_

#include <memory>
#include <mhl/system/singleton/singleton_cleanup.hpp>

namespace mhl {

namespace system {

namespace singleton {

/**
 * @brief シングルトンクラス
 * テンプレートで指定されたクラスをシングルトンで扱えるようにする
 * 使い方
 * // GetInstanceを呼ぶことでクラスAが動的に生成、そのクラスの参照が返される
 * A& a = mhl::system::singleton::MhSingleton<A>::GetInstance();
 *
 * // アプリケーションの最後にクリーンアップ処理実行すること
 * mhl::system::singleton::SingletonCleanup::Execute();
 * // クリーンアップ処理の終了処理
 * mhl::system::singleton::SingletonCleanup::Finalize();
 */
template <typename T>
class MhSingleton final {
 public:
  static T& GetInstance() {
    std::call_once(initialize_flag_, Create);
    return (*instance_.get());
  }

 private:
  static void Create() {
    instance_.reset(new T);
    SingletonCleanup::Add(&MhSingleton<T>::Cleanup);
  }

  static void Cleanup() { instance_.reset(); }

 private:
  static std::once_flag initialize_flag_;  // 初期化フラグ
  static std::unique_ptr<T> instance_;  // シングルトンにするクラス
};

// 静的変数実体宣言
template <typename T>
std::once_flag mhl::system::singleton::MhSingleton<T>::initialize_flag_;
template <typename T>
std::unique_ptr<T> mhl::system::singleton::MhSingleton<T>::instance_ = nullptr;

}  // namespace singleton

}  // namespace system

}  // namespace mhl

#endif  // MHL_SYSTEM_SINGLETON_MH_SINGLETON_HPP_
