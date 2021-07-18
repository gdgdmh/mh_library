#ifndef MHL_SYSTEM_SERVICE_LOCATOR_SERVICE_LOCATOR_HPP_
#define MHL_SYSTEM_SERVICE_LOCATOR_SERVICE_LOCATOR_HPP_

#include <memory>

namespace mhl {

namespace service_locator {

/**
 * @brief サービスロケーターテンプレート
 *
 */
template <typename T>
class ServiceLocator {
 public:
  /**
   * @brief コンストラクタ
   *
   */
  ServiceLocator() : service_(nullptr) {}

  /**
   * @brief デストラクタ
   *
   */
  virtual ~ServiceLocator() { service_.reset(); }

  /**
   * @brief サービスの取得
   * 使用の際は最低限のASSERTだけすること
   * 基本はnullオブジェクトを提供するのでnullptrが返ることはない
   *
   * @return T* サービスオブジェクトのポインタ
   */
  virtual T* get() { return service_.get(); }

  /**
   * @brief サービスを設定する
   *
   */
  void Provide(T* service) { service_.reset(service_); }

 private:
  std::unique_ptr<T> service_;
};

}  // namespace service_locator

}  // namespace mhl

#endif  // MHL_SYSTEM_SERVICE_LOCATOR_SERVICE_LOCATOR_HPP_
