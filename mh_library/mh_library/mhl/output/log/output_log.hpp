#ifndef MHL_OUTPUT_LOG_OUTPUT_LOG_HPP_
#define MHL_OUTPUT_LOG_OUTPUT_LOG_HPP_

#include <memory>
#include <string>
#include <vector>

#include "../../system/file/text/itextfile_writer.hpp"
#include "ilog_outputables.hpp"

namespace mhl {

namespace output {

namespace log {

// コンソール出力クラス
class OutputLog : public mhl::output::log::ILogOutputables {
 public:
  using WriterInterface = mhl::system::file::text::ITextfileWriter;

 public:
  /**
   * @brief コンストラクタ
   *
   */
  OutputLog();

  /**
   * デストラクタ
   */
  virtual ~OutputLog();

  /**
   * @brief 終了処理
   *
   * @return true 終了処理成功
   * @return false 終了処理失敗
   */
  bool Finalize() override;

  /**
   * @brief 文字列を出力する
   *
   * @param string 出力する文字列
   */
  void Print(const std::string& string) override;

  /**
   * @brief 改行付き文字列を出力する
   *
   * @param string 出力する文字列
   */
  void PrintLine(const std::string& string) override;

  /**
   * @brief 出力クラスを追加する
   *
   */
  void Add(std::shared_ptr<ILogOutputable>& output_log) override;

  /**
   * @brief 追加された出力クラスをクリアする
   *
   */
  void Clear() override;

  /**
   * @brief 現在登録されている出力クラスの個数を取得する
   *
   * @return size_t 出力クラスの個数
   */
  size_t Size() const override;

 private:
  std::vector<std::shared_ptr<mhl::output::log::ILogOutputable> > outputable_;
};

}  // namespace log

}  // namespace output

}  // namespace mhl

#endif  // MHL_OUTPUT_LOG_OUTPUT_LOG_HPP_
