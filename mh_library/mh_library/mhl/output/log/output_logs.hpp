#ifndef MHL_OUTPUT_LOG_OUTPUT_LOGS_HPP_
#define MHL_OUTPUT_LOG_OUTPUT_LOGS_HPP_

#include <memory>
#include <string>
#include <vector>

#include "../../system/file/text/itextfile_writer.hpp"
#include "ilog_outputables.hpp"

namespace mhl {

namespace output {

namespace log {

// コンソール出力クラス
class OutputLogs : public mhl::output::log::ILogOutputables {
 public:
  using WriterInterface = mhl::system::file::text::ITextfileWriter;

 public:
  /**
   * @brief コンストラクタ
   *
   */
  OutputLogs();

  /**
   * デストラクタ
   */
  virtual ~OutputLogs();

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
   * @brief ログ出力クラスを追加する.初期化済みであることが前提
   *
   * @param output_log 追加するログ出力クラス(初期化済み)
   * @return true 追加成功
   * @return false 初期化されてないなどの理由で追加しなかった
   */
  bool Add(const std::shared_ptr<ILogOutputable>& output_log) override;

  /**
   * @brief 追加されたログ出力クラスをクリアする
   *
   * @return true 成功
   * @return false どれかが失敗
   */
  bool Clear() override;

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

#endif  // MHL_OUTPUT_LOG_OUTPUT_LOGS_HPP_
