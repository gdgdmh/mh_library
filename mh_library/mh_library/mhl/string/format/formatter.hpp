#ifndef MHL_STRING_FORMAT_FORMATTER_HPP_
#define MHL_STRING_FORMAT_FORMATTER_HPP_

#include <mhl/system/variable_length_arguments/get_variable_length_arguments.hpp>
#include <string>

namespace mhl {
namespace string {
namespace format {

// コンソール出力のインターフェースクラス
class Formatter {
 public:
  /**
   * 指定された形式に基づいて文字列に変換し、別の文字列に挿入する
   * @param  fmt  フォーマット文字列
   * @param  args パラメータ
   * @return      整形された文字列
   */
  template <typename... Args>
  static std::string Format(const std::string& fmt, Args... args) {
    mhl::system::variable_length_arguments::GetVariableLengthArguments g;
    std::string s;
    g.ToString(s, fmt.c_str(), args...);
    return s;
  }
};
}  // namespace format
}  // namespace string
}  // namespace mhl

#endif  // MHL_STRING_FORMAT_FORMATTER_HPP_
