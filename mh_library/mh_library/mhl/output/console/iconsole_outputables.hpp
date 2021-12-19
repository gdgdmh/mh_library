#ifndef MHL_OUTPUT_CONSOLE_ICONSOLEOUTPUTABLES_HPP_
#define MHL_OUTPUT_CONSOLE_ICONSOLEOUTPUTABLES_HPP_

#include <memory>
#include <mhl/output/console/iconsole_outputable.hpp>
#include <string>

namespace mhl {

namespace output {

namespace console {

/**
 * @brief 複数環境コンソール出力クラス
 *
 */
class IConsoleOutputables {
 public:
  /**
   * デストラクタ
   */
  virtual ~IConsoleOutputables() {}

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
  virtual void Add(std::shared_ptr<IConsoleOutputable>& output_console) = 0;

  /**
   * @brief 追加された出力クラスをクリアする
   *
   */
  virtual void Clear() = 0;

  /**
   * @brief 現在登録されている出力クラスの個数を取得する
   *
   * @return size_t 出力クラスの個数
   */
  virtual size_t Size() = 0;
};

}  // namespace console

}  // namespace output

}  // namespace mhl

#endif  // MHL_OUTPUT_CONSOLE_ICONSOLEOUTPUTABLES_HPP_
