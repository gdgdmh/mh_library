#ifndef MHL_OUTPUT_CONSOLE_DUMMYOUTPUTCONSOLE_HPP_
#define MHL_OUTPUT_CONSOLE_DUMMYOUTPUTCONSOLE_HPP_

#include <mhl/output/console/iconsole_outputable.hpp>
#include <string>

namespace mhl {

namespace output {

namespace console {

// ダミーコンソール出力クラス
class DummyOutputConsole : public mhl::output::console::IConsoleOutputable {
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
