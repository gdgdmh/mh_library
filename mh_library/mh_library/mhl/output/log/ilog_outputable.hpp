#ifndef MHL_OUTPUT_LOG_ILOG_OUTPUTABLE_HPP_
#define MHL_OUTPUT_LOG_ILOG_OUTPUTABLE_HPP_

#include <string>

namespace mhl {
namespace output {
namespace log {

/**
 * @brief ログ出力インターフェース
 *
 */
class ILogOutputable {
 public:
  /**
   * デストラクタ
   */
  virtual ~ILogOutputable() {}

  /**
   * @brief 初期化
   *
   * @param file_name ログファイルパス
   * @param mode ファイルオープンモード
   * @return true 初期化成功
   * @return false 初期化失敗
   */
  virtual bool Initialize(const std::string& file_name,
                          mhl::system::file::text::Mode mode) = 0;

  /**
   * @brief 終了処理
   *
   * @return true 終了処理成功
   * @return false 終了処理失敗
   */
  virtual bool Finalize() = 0;

  /**
   * @brief 文字列を出力する
   *
   * @param string 出力する文字列
   */
  virtual void Print(const std::string& string) = 0;

  /**
   * @brief 改行付き文字列を出力する
   *
   * @param string 出力する文字列
   */
  virtual void PrintLine(const std::string& string) = 0;

  /**
   * @brief 初期化済みか
   *
   * @return true 初期化済み
   * @return false 未初期化
   */
  virtual bool IsInitialized() const = 0;
};
}  // namespace log
}  // namespace output
}  // namespace mhl

#endif  // MHL_OUTPUT_LOG_ILOG_OUTPUTABLE_HPP_
