#ifndef MHL_OUTPUT_CONSOLE_DUMMYOUTPUTCONSOLE_HPP_
#define MHL_OUTPUT_CONSOLE_DUMMYOUTPUTCONSOLE_HPP_

#include <string>

#include "ioutput_console.hpp"

namespace mhl {

namespace output {

namespace console {

// ダミーコンソール出力クラス
class DummyOutputConsole : public mhl::output::console::IOutputConsole {
 public:
  /**
   * コンストラクタ
   */
  DummyOutputConsole();

  /**
   * デストラクタ
   */
  virtual ~DummyOutputConsole();

  /**
   * 文字列を出力する(ダミーなので出力はしない)
   */
  void Print(std::string string);

  /**
   * 改行付き文字列を出力する(ダミーなので出力はしない)
   */
  void PrintLine(std::string string);
};

}  // namespace console

}  // namespace output

}  // namespace mhl

#endif  // MHL_OUTPUT_CONSOLE_DUMMYOUTPUTCONSOLE_HPP_
