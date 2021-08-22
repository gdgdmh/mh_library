#ifndef MHL_SYSTEM_FILE_TEXT_ITEXTFILE_WRITER_HPP_
#define MHL_SYSTEM_FILE_TEXT_ITEXTFILE_WRITER_HPP_

#include <string>

#include "textfile_write_mode.hpp"

namespace mhl {
namespace system {
namespace file {
namespace text {

/**
 * @brief テキスト書き込みインターフェースクラス
 *
 */
class ITextfileWriter {
 public:
  /**
   * @brief デストラクタ
   *
   */
  virtual ~ITextfileWriter() {}

  /**
   * @brief ファイルオープン
   *
   * @param file_name ファイル名
   * @param mode オープンモード
   * @return true ファイルオープンに成功
   * @return false ファイルオープンに失敗
   */
  virtual bool Open(const std::string& file_name, Mode mode) = 0;

  /**
   * @brief ファイルクローズ
   *
   * @return true ファイルクローズに成功
   * @return false ファイルクローズに失敗
   */
  virtual bool Close() = 0;

  /**
   * @brief ファイルオープンしているか
   *
   * @return true ファイルオープン済み
   * @return false ファイルオープンしていない
   */
  virtual bool IsOpened() = 0;

  /**
   * @brief テキスト書き込み
   *
   * @param str 書き込みするテキスト
   * @return true 書き込み成功
   * @return false 書き込み失敗(ファイルオープンしていない、空文字指定など)
   */
  virtual bool Write(const std::string& str) = 0;

  /**
   * @brief テキスト書き込み(改行付き)
   *
   * @param str 書き込みするテキスト
   * @return true 書き込み成功
   * @return false 書き込み失敗(ファイルオープンしていない、空文字指定など)
   */
  virtual bool WriteLine(const std::string& str) = 0;
};
}  // namespace text
}  // namespace file
}  // namespace system
}  // namespace mhl

#endif  // MHL_SYSTEM_FILE_TEXT_ITEXTFILE_WRITER_HPP_
