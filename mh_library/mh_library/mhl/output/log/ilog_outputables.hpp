#ifndef MHL_OUTPUT_LOG_ILOGOUTPUTABLES_HPP_
#define MHL_OUTPUT_LOG_ILOGOUTPUTABLES_HPP_

#include <memory>
#include <string>

#include "../../system/file/text/textfile_write_mode.hpp"
#include "ilog_outputable.hpp"

namespace mhl {

namespace output {

namespace log {

/**
 * @brief 複数環境ログ出力クラス
 *
 */
class ILogOutputables {
 public:
  /**
   * デストラクタ
   */
  virtual ~ILogOutputables() {}

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
   * @brief 出力クラスを追加する
   *
   */
  virtual void Add(std::shared_ptr<ILogOutputable>& output_log) = 0;

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
  virtual size_t Size() const = 0;
};

}  // namespace log

}  // namespace output

}  // namespace mhl

#endif  // MHL_OUTPUT_LOG_ILOGOUTPUTABLES_HPP_
