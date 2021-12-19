#ifndef MHL_OUTPUT_CONSOLE_OUTPUTCONSOLES_HPP_
#define MHL_OUTPUT_CONSOLE_OUTPUTCONSOLES_HPP_

#include <mhl/output/console/iconsole_outputable.hpp>
#include <mhl/output/console/iconsole_outputables.hpp>
#include <string>
#include <vector>

namespace mhl {

namespace output {

namespace console {

/**
 * @brief 複数コンソール出力クラス
 *
 */
class OutputConsoles : public mhl::output::console::IConsoleOutputables {
 public:
  /**
   * コンストラクタ
   */
  OutputConsoles();

  /**
   * デストラクタ
   */
  virtual ~OutputConsoles();

  /**
   * 文字列を出力する
   */
  void Print(std::string string);

  /**
   * 改行付き文字列を出力する
   */
  void PrintLine(std::string string);

  /**
   * @brief 出力クラスを追加する
   *
   */
  void Add(std::shared_ptr<IConsoleOutputable>& output_console);

  /**
   * @brief 追加された出力クラスをクリアする
   *
   */
  void Clear();

  /**
   * @brief 現在登録されている出力クラスの個数を取得する
   *
   * @return size_t 出力クラスの個数
   */
  size_t Size();

 private:
  std::vector<std::shared_ptr<IConsoleOutputable> > output_;
};

}  // namespace console

}  // namespace output

}  // namespace mhl

#endif  // MHL_OUTPUT_CONSOLE_OUTPUTCONSOLES_HPP_
