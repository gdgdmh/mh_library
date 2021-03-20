#ifndef MHL_OUTPUT_CONSOLE_ICONSOLE_OUTPUTABLE_HPP_
#define MHL_OUTPUT_CONSOLE_ICONSOLE_OUTPUTABLE_HPP_

#include <string>

namespace mhl {

namespace output {

namespace console {

/**
 * @brief コンソール出力インターフェース
 *
 */
class IConsoleOutputable {
 public:
  /**
   * デストラクタ
   */
  virtual ~IConsoleOutputable() {}

  /**
   * 文字列を出力する
   */
  virtual void Print(std::string string) = 0;

  /**
   * 改行付き文字列を出力する
   */
  virtual void PrintLine(std::string string) = 0;
};

}  // namespace console

}  // namespace output

}  // namespace mhl

#endif  // MHL_OUTPUT_CONSOLE_ICONSOLE_OUTPUTABLE_HPP_
