#include "UnitTestException.hpp"

mh_library::UnitTestException::UnitTestException(const std::string& message, int error_code)
  : runtime_error(message), error_code_(error_code) {
}

mh_library::UnitTestException::~UnitTestException() {
}