#include "ArgumentException.hpp"

mh_library::ArgumentException::ArgumentException(const std::string& message, int error_code)
  : runtime_error(message), error_code_(error_code) {
}

mh_library::ArgumentException::~ArgumentException() {
}