#ifndef MHL_OUTPUT_LOG_ILOGOUTPUTABLES_HPP_
#define MHL_OUTPUT_LOG_ILOGOUTPUTABLES_HPP_

#include <memory>
#include <string>

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
   * 文字列を出力する
   */
  virtual void Print(std::string string) = 0;

  /**
   * 改行付き文字列を出力する
   */
  virtual void PrintLine(std::string string) = 0;

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
  virtual size_t Size() = 0;
};

}  // namespace log

}  // namespace output

}  // namespace mhl

#endif  // MHL_OUTPUT_LOG_ILOGOUTPUTABLES_HPP_
