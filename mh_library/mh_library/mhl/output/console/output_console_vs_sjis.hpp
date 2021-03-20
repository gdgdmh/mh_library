#ifndef MHL_OUTPUT_CONSOLE_OUTPUTCONSOLE_VS_SJIS_HPP_
#define MHL_OUTPUT_CONSOLE_OUTPUTCONSOLE_VS_SJIS_HPP_

#include <string>

#include "iconsole_outputable.hpp"

namespace mhl {

namespace output {

namespace console {

/**
 * @brief VisualStudioの出力ウィンドウに出力
 *
 */
class OutputConsoleVsSjis : public mhl::output::console::IConsoleOutputable {
 public:
  /**
   * コンストラクタ
   */
  OutputConsoleVsSjis();

  /**
   * デストラクタ
   */
  virtual ~OutputConsoleVsSjis();

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

#endif  // MHL_OUTPUT_CONSOLE_OUTPUTCONSOLE_VS_SJIS_HPP_
