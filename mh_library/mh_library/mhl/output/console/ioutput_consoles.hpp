#ifndef MHL_OUTPUT_CONSOLE_IOUTPUTCONSOLES_HPP_
#define MHL_OUTPUT_CONSOLE_IOUTPUTCONSOLES_HPP_

#include <memory>
#include <string>

#include "ioutput_console.hpp"

namespace mhl {

namespace output {

namespace console {

/**
 * @brief 複数環境コンソール出力クラス
 *
 */
class IOutputConsoles {
 public:
  /**
   * デストラクタ
   */
  virtual ~IOutputConsoles() {}

  /**
   * 文字列を出力する
   */
  virtual void Print(std::string string) = 0;

  /**
   * 改行付き文字列を出力する
   */
  virtual void PrintLine(std::string string) = 0;

  /**
   * @brief 出力クラスを追加する
   *
   */
  virtual void Add(std::shared_ptr<IOutputConsole>& output_console) = 0;

  /**
   * @brief 追加された出力クラスをクリアする
   *
   */
  virtual void Clear() = 0;
};

}  // namespace console

}  // namespace output

}  // namespace mhl

#endif  // MHL_OUTPUT_CONSOLE_IOUTPUTCONSOLES_HPP_
