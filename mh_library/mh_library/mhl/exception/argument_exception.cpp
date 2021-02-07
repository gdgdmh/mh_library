#include "argument_exception.hpp"

mhl::exception::ArgumentException::ArgumentException(const std::string& message,
                                          int error_code)
    : runtime_error(message), error_code_(error_code) {}

mhl::exception::ArgumentException::~ArgumentException() {}