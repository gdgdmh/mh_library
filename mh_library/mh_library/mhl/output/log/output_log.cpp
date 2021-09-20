#include "output_log.hpp"

#include <iostream>

/**
 * @brief コンストラクタ
 *
 */
mhl::output::log::OutputLog::OutputLog() : outputable_() {}

/**
 * デストラクタ
 */
mhl::output::log::OutputLog::~OutputLog() { outputable_.clear(); }

/**
 * @brief 終了処理
 *
 * @return true 終了処理成功
 * @return false 終了処理失敗
 */
bool mhl::output::log::OutputLog::Finalize() {
  bool is_success = true;
  for (auto output : outputable_) {
    if (output.get() == nullptr) {
      continue;
    }
    if (!output->Finalize()) {
      output.reset();
      is_success = false;
    }
  }
  return is_success;
}

/**
 * @brief 文字列を出力する
 *
 * @param string 出力する文字列
 */
void mhl::output::log::OutputLog::Print(const std::string& string) {
  for (auto output : outputable_) {
    if (output.get() == nullptr) {
      continue;
    }
    output->Print(string);
  }
}

/**
 * @brief 改行付き文字列を出力する
 *
 * @param string 出力する文字列
 */
void mhl::output::log::OutputLog::PrintLine(const std::string& string) {
  for (auto output : outputable_) {
    if (output.get() == nullptr) {
      continue;
    }
    output->PrintLine(string);
  }
}

/**
 * @brief 出力クラスを追加する
 *
 */
void mhl::output::log::OutputLog::Add(
    std::shared_ptr<ILogOutputable>& output_log) {}

/**
 * @brief 追加された出力クラスをクリアする
 *
 */
void mhl::output::log::OutputLog::Clear() {}

/**
 * @brief 現在登録されている出力クラスの個数を取得する
 *
 * @return size_t 出力クラスの個数
 */
size_t mhl::output::log::OutputLog::Size() const { return outputable_.size(); }