#ifndef MHL_SYSTEM_VARIABLE_LENGTH_ARGUMENTS_GET_VARIABLE_LENGTH_ARGUMENTS_HPP_
#define MHL_SYSTEM_VARIABLE_LENGTH_ARGUMENTS_GET_VARIABLE_LENGTH_ARGUMENTS_HPP_

#include <vector>

namespace mhl {
namespace system {
namespace variable_length_arguments {

class GetVariableLengthArguments {
 public:
  /**
   * @brief 可変引数を取得
   *
   * @param arg_string 取得した可変引数文字列
   * @param format フォーマット(書式指定文字列)
   * @param args 書式設定する省略可能な引数
   */
  template <typename... Args>
  void ToString(std::string& arg_string, const char* format, Args... args) {
    size_t len = std::snprintf(nullptr, 0, format, args...);
    std::vector<char> buf(len + 1);
    std::snprintf(&buf[0], len + 1, format, args...);
    arg_string = std::string(&buf[0], &buf[0] + len);
  }

  /**
   * @brief 可変引数を取得
   *
   * @param arg_char 取得した可変引数文字列
   * @param buffer_count arg_charの文字数
   * @param format フォーマット(書式指定文字列)
   * @param args 書式設定する省略可能な引数
   */
  template <typename... Args>
  void ToChar(char arg_char[], size_t buffer_count, const char* format,
              Args... args) {
    size_t len = std::snprintf(nullptr, 0, format, args...);
    std::vector<char> buf(len + 1);
    std::snprintf(arg_char, buffer_count - 1, format, args...);
  }
};

}  // namespace variable_length_arguments
}  // namespace system
}  // namespace mhl

#endif  // MHL_SYSTEM_VARIABLE_LENGTH_ARGUMENTS_GET_VARIABLE_LENGTH_ARGUMENTS_HPP_
