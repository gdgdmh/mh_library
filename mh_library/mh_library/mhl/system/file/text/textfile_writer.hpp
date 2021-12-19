#ifndef MHL_SYSTEM_FILE_TEXT_TEXTFILE_WRITER_HPP_
#define MHL_SYSTEM_FILE_TEXT_TEXTFILE_WRITER_HPP_

#include <fstream>
#include <iostream>
#include <mhl/system/file/text/itextfile_writer.hpp>

namespace mhl {
namespace system {
namespace file {
namespace text {

/**
 * @brief テキストファイル書き込みクラス
 *
 */
class TextfileWriter : public ITextfileWriter {
 public:
  /**
   * @brief コンストラクタ
   *
   */
  TextfileWriter();

  /**
   * @brief デストラクタ
   *
   */
  virtual ~TextfileWriter() override;

  /**
   * @brief ファイルオープン
   *
   * @param file_name ファイル名
   * @param mode オープンモード
   * @return true ファイルオープンに成功
   * @return false ファイルオープンに失敗
   */
  bool Open(const std::string& file_name, Mode mode) override;

  /**
   * @brief ファイルクローズ
   *
   * @return true ファイルクローズに成功
   * @return false ファイルクローズに失敗
   */
  bool Close() override;

  /**
   * @brief ファイルオープンしているか
   *
   * @return true ファイルオープン済み
   * @return false ファイルオープンしていない
   */
  bool IsOpened() override { return is_opened_; }

  /**
   * @brief テキスト書き込み
   *
   * @param str 書き込みするテキスト
   * @return true 書き込み成功
   * @return false 書き込み失敗(ファイルオープンしていない、空文字指定など)
   */
  bool Write(const std::string& str) override;

  /**
   * @brief テキスト書き込み(改行付き)
   *
   * @param str 書き込みするテキスト
   * @return true 書き込み成功
   * @return false 書き込み失敗(ファイルオープンしていない、空文字指定など)
   */
  bool WriteLine(const std::string& str) override;

 private:
  /**
   * @brief ファイルオープンモードを取得する
   *
   * @param mode ファイルオープンモード
   * @return std::ios::openmode システムのファイルオープンモード
   */
  std::ios::openmode GetMode(Mode mode);

 private:
  std::string file_name_;  // ファイル名
  std::ofstream ofs_;      // ファイルストリーム
  Mode mode_;              // ファイルオープンモード
  bool is_opened_;         // ファイルを開いているか
};
}  // namespace text
}  // namespace file
}  // namespace system
}  // namespace mhl

#endif  // MHL_SYSTEM_FILE_TEXT_TEXTFILE_WRITER_HPP_
