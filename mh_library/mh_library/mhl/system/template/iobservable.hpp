#ifndef MHL_SYSTEM_TEMPLATE_IOBSERVABLE_HPP_
#define MHL_SYSTEM_TEMPLATE_IOBSERVABLE_HPP_

namespace mhl {

// 前方宣言
class Subject;

// オブザーバーインターフェースクラス
class IObservable {
 public:
  virtual ~IObservable() {}

  virtual void Update(Subject& subject) = 0;
};

}  // namespace mhl

#endif  // MHL_SYSTEM_TEMPLATE_IOBSERVABLE_HPP_
