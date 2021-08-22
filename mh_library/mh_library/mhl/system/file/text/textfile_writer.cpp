#include "textfile_writer.hpp"

/**
 * @brief コンストラクタ
 *
 */
mhl::system::file::text::TextfileWriter::TextfileWriter()
    : file_name_(""), ofs_(), mode_(Mode::kNone), is_opened_(false) {}

/**
 * @brief デストラクタ
 *
 */
mhl::system::file::text::TextfileWriter::~TextfileWriter() {}

/**
 * @brief ファイルオープン
 *
 * @param file_name ファイル名
 * @param mode オープンモード
 * @return true ファイルオープンに成功
 * @return false ファイルオープンに失敗
 */
bool mhl::system::file::text::TextfileWriter::Open(const std::string& file_name,
                                                   Mode mode) {
  if (IsOpened()) {
    return true;
  }
  if (mode == Mode::kNone) {
    return false;
  }
  if (file_name.empty()) {
    return false;
  }
  mode_ = mode;
  file_name_ = file_name;
  ofs_.open(file_name, GetMode(mode_));
  if (!ofs_) {
    is_opened_ = false;
    return false;
  }
  is_opened_ = true;
  return true;
}

/**
 * @brief ファイルクローズ
 *
 * @return true ファイルクローズに成功
 * @return false ファイルクローズに失敗
 */
bool mhl::system::file::text::TextfileWriter::Close() {
  if (!IsOpened()) {
    return true;
  }
  ofs_.close();
  return true;
}

/**
 * @brief テキスト書き込み
 *
 * @param str 書き込みするテキスト
 * @return true 書き込み成功
 * @return false 書き込み失敗(ファイルオープンしていない、空文字指定など)
 */
bool mhl::system::file::text::TextfileWriter::Write(const std::string& str) {
  if (!IsOpened()) {
    return false;
  }
  ofs_ << str;
  return true;
}

/**
 * @brief テキスト書き込み(改行付き)
 *
 * @param str 書き込みするテキスト
 * @return true 書き込み成功
 * @return false 書き込み失敗(ファイルオープンしていない、空文字指定など)
 */
bool mhl::system::file::text::TextfileWriter::WriteLine(
    const std::string& str) {
  if (!IsOpened()) {
    return false;
  }
  ofs_ << str << std::endl;
  return true;
}

/**
 * @brief ファイルオープンモードを取得する
 *
 * @param mode ファイルオープンモード
 * @return std::ios::openmode システムのファイルオープンモード
 */
std::ios::openmode mhl::system::file::text::TextfileWriter::GetMode(Mode mode) {
  switch (mode) {
    case Mode::kAdd:
      return (std::ios::out | std::ios::app);
    case Mode::kNewWrite:
      return (std::ios::out | std::ios::trunc);
    default:
      return (std::ios::out | std::ios::app);
  }
}
