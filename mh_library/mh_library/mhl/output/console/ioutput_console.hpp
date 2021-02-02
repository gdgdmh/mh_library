#ifndef MHL_OUTPUT_CONSOLE_IOUTPUTCONSOLE_HPP_
#define MHL_OUTPUT_CONSOLE_IOUTPUTCONSOLE_HPP_

#include <string>

namespace mhl {

namespace output {

namespace console {

// コンソール出力のインターフェースクラス
class IOutputConsole {
 public:
  /**
   * デストラクタ
   */
  virtual ~IOutputConsole() {}

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

#endif  // MHL_OUTPUT_CONSOLE_IOUTPUTCONSOLE_HPP_
