#ifndef MHL_SYSTEM_TEMPLATE_IEXECUTEMETHOD_HPP_
#define MHL_SYSTEM_TEMPLATE_IEXECUTEMETHOD_HPP_

#include <string>

namespace mhl {

// メソッド実行インターフェースクラス
template <typename T>
class IExecuteMethod {
 public:
  IExecuteMethod(IExecuteMethod<T> (T::*f)()) : function_(f){};

  /**
   * デストラクタ
   */
  virtual ~IExecuteMethod() {}

  IExecuteMethod<T> executeMethod(T* obj) { return (obj->*function_)(); }

 private:
  // 実行するT型クラスのメソッドポインタ
  IExecuteMethod<T> (T::*function_)();
};

}  // namespace mhl

#endif  // MHL_SYSTEM_TEMPLATE_IEXECUTEMETHOD_HPP_
