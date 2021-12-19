#ifndef MHL_OUTPUT_LOG_ILOGOUTPUTABLES_HPP_
#define MHL_OUTPUT_LOG_ILOGOUTPUTABLES_HPP_

#include <memory>
#include <mhl/output/log/ilog_outputable.hpp>
#include <mhl/system/file/text/textfile_write_mode.hpp>
#include <string>

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
   * @brief ログ出力クラスを追加する.初期化済みであることが前提
   *
   * @param output_log 追加するログ出力クラス(初期化済み)
   * @return true 追加成功
   * @return false 初期化されてないなどの理由で追加しなかった
   */
  virtual bool Add(const std::shared_ptr<ILogOutputable>& output_log) = 0;

  /**
   * @brief 追加されたログ出力クラスをクリアする
   *
   * @return true 成功
   * @return false どれかが失敗
   */
  virtual bool Clear() = 0;

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
