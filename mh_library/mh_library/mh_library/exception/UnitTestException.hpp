#ifndef MH_LIBRABY_EXCEPTION_UNITTESTEXCEPTION_H_
#define MH_LIBRABY_EXCEPTION_UNITTESTEXCEPTION_H_

#include <stdexcept>

namespace mh_library {

// 単体テスト用の例外クラス
class UnitTestException : public std::runtime_error {
public:
  UnitTestException(const std::string& message, int error_code);

  virtual ~UnitTestException();

  int GetResult() {
    return error_code_;
  }
private:
  int error_code_; // エラーコード情報
};

}

#endif  // MH_LIBRABY_EXCEPTION_UNITTESTEXCEPTION_H_
