#ifndef MHL_OUTPUT_CONSOLE_OUTPUTCONSOLE_HPP_
#define MHL_OUTPUT_CONSOLE_OUTPUTCONSOLE_HPP_

#include <string>

#include "ioutput_console.hpp"

namespace mhl {

namespace output {

namespace console {

// コンソール出力クラス
class OutputConsole : public mhl::output::console::IOutputConsole {
 public:
  /**
   * コンストラクタ
   */
  OutputConsole();

  /**
   * デストラクタ
   */
  virtual ~OutputConsole();

  /**
   * 文字列を出力する
   */
  void Print(std::string string);

  /**
   * 改行付き文字列を出力する
   */
  void PrintLine(std::string string);
};

}  // namespace console

}  // namespace output

}  // namespace mhl

#endif  // MHL_OUTPUT_CONSOLE_OUTPUTCONSOLE_HPP_
