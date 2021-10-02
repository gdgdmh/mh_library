#include "output_log.hpp"

/**
 * @brief コンストラクタ
 *
 * @param output ログ出力クラス
 */
mhl::output::log::OutputLog::OutputLog(
    const std::shared_ptr<mhl::system::file::text::ITextfileWriter>& writer)
    : writer_(writer) {}

/**
 * デストラクタ
 */
mhl::output::log::OutputLog::~OutputLog() { Finalize(); }

/**
 * @brief 初期化
 *
 * @param file_name ログファイルパス
 * @param mode ファイルオープンモード
 * @return true 初期化成功
 * @return false 初期化失敗
 */
bool mhl::output::log::OutputLog::Initialize(
    const std::string& file_name, mhl::system::file::text::Mode mode) {
  if (writer_.get() == nullptr) {
    return false;
  }
  if (writer_->IsOpened()) {
    return true;
  }
  // ファイルオープンしてないときは開く
  return writer_->Open(file_name, mode);
}

/**
 * @brief 終了処理
 *
 * @return true 終了処理成功
 * @return false 終了処理失敗
 */
bool mhl::output::log::OutputLog::Finalize() {
  if (writer_.get() == nullptr) {
    // 解放済み
    return true;
  }
  bool result = false;
  if (writer_->IsOpened()) {
    result = writer_->Close();
  }
  writer_.reset();
  return result;
}

/**
 * @brief 文字列を出力する
 *
 * @param string 出力する文字列
 */
void mhl::output::log::OutputLog::Print(const std::string& string) {
  if (writer_.get() == nullptr) {
    return;
  }
  writer_->Write(string);
}

/**
 * @brief 改行付き文字列を出力する
 *
 * @param string 出力する文字列
 */
void mhl::output::log::OutputLog::PrintLine(const std::string& string) {
  if (writer_.get() == nullptr) {
    return;
  }
  writer_->WriteLine(string);
}

/**
 * @brief 初期化済みか
 *
 * @return true 初期化済み
 * @return false 未初期化
 */
bool mhl::output::log::OutputLog::IsInitialized() const {
  if (writer_.get() == nullptr) {
    return false;
  }
  return writer_->IsOpened();
}
