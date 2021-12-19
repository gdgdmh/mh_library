#ifndef MHL_OUTPUT_LOG_OUTPUT_LOG_HPP_
#define MHL_OUTPUT_LOG_OUTPUT_LOG_HPP_

#include <memory>
#include <mhl/output/log/ilog_outputable.hpp>
#include <mhl/system/file/text/itextfile_writer.hpp>
#include <string>
#include <vector>

namespace mhl {

namespace output {

namespace log {

// ログ出力クラス
class OutputLog : public mhl::output::log::ILogOutputable {
 public:
  /**
   * @brief コンストラクタ
   *
   * @param output ログ出力クラス
   */
  OutputLog(
      const std::shared_ptr<mhl::system::file::text::ITextfileWriter>& writer);

  /**
   * デストラクタ
   */
  virtual ~OutputLog();

  /**
   * @brief 初期化
   *
   * @param file_name ログファイルパス
   * @param mode ファイルオープンモード
   * @return true 初期化成功
   * @return false 初期化失敗
   */
  bool Initialize(const std::string& file_name,
                  mhl::system::file::text::Mode mode) override;

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
   * @brief 初期化済みか
   *
   * @return true 初期化済み
   * @return false 未初期化
   */
  bool IsInitialized() const override;

 private:
  std::shared_ptr<mhl::system::file::text::ITextfileWriter> writer_;
};

}  // namespace log

}  // namespace output

}  // namespace mhl

#endif  // MHL_OUTPUT_LOG_OUTPUT_LOG_HPP_
