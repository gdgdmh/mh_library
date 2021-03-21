#include "output_consoles.hpp"

#include <iostream>

/**
 * コンストラクタ
 */
mhl::output::console::OutputConsoles::OutputConsoles() {}

/**
 * デストラクタ
 */
mhl::output::console::OutputConsoles::~OutputConsoles() {}

/**
 * 文字列を出力する
 */
void mhl::output::console::OutputConsoles::Print(std::string string) {
  for (auto& output : output_) {
    if (!output) {
      continue;
    }
    output->Print(string);
  }
}

/**
 * 改行付き文字列を出力する
 */
void mhl::output::console::OutputConsoles::PrintLine(std::string string) {
  for (auto& output : output_) {
    if (!output) {
      continue;
    }
    output->PrintLine(string);
  }
}

/**
 * @brief 出力クラスを追加する
 *
 */
void mhl::output::console::OutputConsoles::Add(
    std::shared_ptr<IConsoleOutputable>& output_console) {
  output_.emplace_back(output_console);
}

/**
 * @brief 追加された出力クラスをクリアする
 *
 */
void mhl::output::console::OutputConsoles::Clear() { output_.clear(); }

/**
 * @brief 現在登録されている出力クラスの個数を取得する
 *
 * @return size_t 出力クラスの個数
 */
size_t mhl::output::console::OutputConsoles::Size() { return output_.size(); }
