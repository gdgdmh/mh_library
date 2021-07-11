#ifndef MHL_SYSTEM_SERVICE_LOCATOR_SERVICE_LOCATOR_HPP_
#define MHL_SYSTEM_SERVICE_LOCATOR_SERVICE_LOCATOR_HPP_

#include <memory>

namespace mhl {

namespace locator {

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
  ServiceLocator();

  /**
   * @brief デストラクタ
   *
   */
  virtual ~ServiceLocator();

  /**
   * @brief サービスの取得
   * 使用の際は最低限のASSERTだけすること
   * 基本はnullオブジェクトを提供するのでnullptrが返ることはない
   *
   * @return T* サービスオブジェクトのポインタ
   */
  virtual T* get();

  /**
   * @brief サービスを設定する
   *
   */
  void Provide(T* service);
};

}  // namespace locator

}  // namespace mhl

#endif  // MHL_SYSTEM_SERVICE_LOCATOR_SERVICE_LOCATOR_HPP_
