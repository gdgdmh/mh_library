﻿#ifndef MHL_SYSTEM_TEMPLATE_SUBJECT_HPP_
#define MHL_SYSTEM_TEMPLATE_SUBJECT_HPP_

#include <mhl/system/template/iobservable.hpp>
#include <vector>

namespace mhl {

// サブジェクトクラス
class Subject {
 public:
  virtual ~Subject() {}

  void Add(IObservable& o) { observers.push_back(&o); }

  void Remove(IObservable& o) {
    observers.erase(std::remove(observers.begin(), observers.end(), &o));
  }

  void Clear() { observers.clear(); }

  void NotifyObservers() {
    std::vector<IObservable*>::iterator it;
    for (it = observers.begin(); it != observers.end(); ++it) {
      (*it)->Update(*this);
    }
  }

 private:
  std::vector<IObservable*> observers;
};
}  // namespace mhl

#endif  // MHL_SYSTEM_TEMPLATE_SUBJECT_HPP_
