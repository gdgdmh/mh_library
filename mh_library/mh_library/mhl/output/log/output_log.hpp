#ifndef MHL_OUTPUT_LOG_OUTPUT_LOG_HPP_
#define MHL_OUTPUT_LOG_OUTPUT_LOG_HPP_

#include <memory>
#include <string>
#include <ostream>

#include "ilog_outputable.hpp"

namespace mhl {

namespace output {

namespace log {

// コンソール出力クラス
class OutputLog : public mhl::output::log::ILogOutputable {
 public:
  /**
   * @brief コンストラクタ
   *
   * @param file_name ファイル名
   */
  OutputLog(const std::string file_name);

  /**
   * デストラクタ
   */
  virtual ~OutputLog();

  /**
   * 文字列を出力する
   */
  void Print(std::string string);

  /**
   * 改行付き文字列を出力する
   */
  void PrintLine(std::string string);

 public:
  std::string file_path_;
  std::shared_ptr<std::ofstream> out_stream_;
  bool is_open_;
  bool open_error_;
};

}  // namespace log

}  // namespace output

}  // namespace mhl

#endif  // MHL_OUTPUT_LOG_OUTPUT_LOG_HPP_
