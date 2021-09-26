#include "output_logs.hpp"

#include <iostream>

/**
 * @brief コンストラクタ
 *
 */
mhl::output::log::OutputLogs::OutputLogs() : outputable_() {}

/**
 * デストラクタ
 */
mhl::output::log::OutputLogs::~OutputLogs() { outputable_.clear(); }

/**
 * @brief 終了処理
 *
 * @return true 終了処理成功
 * @return false 終了処理失敗
 */
bool mhl::output::log::OutputLogs::Finalize() { return Clear(); }

/**
 * @brief 文字列を出力する
 *
 * @param string 出力する文字列
 */
void mhl::output::log::OutputLogs::Print(const std::string& string) {
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
void mhl::output::log::OutputLogs::PrintLine(const std::string& string) {
  for (auto output : outputable_) {
    if (output.get() == nullptr) {
      continue;
    }
    output->PrintLine(string);
  }
}

/**
 * @brief ログ出力クラスを追加する.初期化済みであることが前提
 *
 * @param output_log 追加するログ出力クラス(初期化済み)
 * @return true 追加成功
 * @return false 初期化されてないなどの理由で追加しなかった
 */
bool mhl::output::log::OutputLogs::Add(
    const std::shared_ptr<ILogOutputable>& output_log) {
  if (output_log.get() == nullptr) {
    return false;
  }
  if (!output_log->IsInitialized()) {
    return false;
  }
  outputable_.emplace_back(output_log);
  return true;
}

/**
 * @brief 追加されたログ出力クラスをクリアする
 *
 * @return true 成功
 * @return false どれかが失敗
 */
bool mhl::output::log::OutputLogs::Clear() {
  bool is_success = true;
  for (auto output : outputable_) {
    if (output.get() == nullptr) {
      continue;
    }
    if (!output->Finalize()) {
      is_success = false;
    }
    output.reset();
  }
  outputable_.clear();
  return is_success;
}

/**
 * @brief 現在登録されている出力クラスの個数を取得する
 *
 * @return size_t 出力クラスの個数
 */
size_t mhl::output::log::OutputLogs::Size() const { return outputable_.size(); }