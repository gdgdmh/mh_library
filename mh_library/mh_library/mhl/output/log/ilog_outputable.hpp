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

  void SetFileName(const std::string& fileName);

  /**
   * 文字列を出力する
   */
  virtual void Print(std::string string) = 0;

  /**
   * 改行付き文字列を出力する
   */
  virtual void PrintLine(std::string string) = 0;
};

}  // namespace log

}  // namespace output

}  // namespace mhl

#endif  // MHL_OUTPUT_LOG_ILOG_OUTPUTABLE_HPP_
