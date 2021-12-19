#ifndef MHL_SYSTEM_FILE_FILE_EXISTS_CHECKER_HPP_
#define MHL_SYSTEM_FILE_FILE_EXISTS_CHECKER_HPP_

#include <mhl/system/file/ifile_exists_checker.hpp>

namespace mhl {
namespace system {
namespace file {

/**
 * @brief ファイル存在チェッククラス
 * 存在チェックはいろいろな方法があるがWindows専用のチェック方法をとる
 *
 */
class FileExistsCheckerWin : public IFileExistsChecker {
 public:
  /**
   * @brief コンストラクタ
   *
   */
  FileExistsCheckerWin();

  /**
   * @brief デストラクタ
   *
   */
  virtual ~FileExistsCheckerWin() override;

  /**
   * @brief ファイルが存在するかチェック
   *
   * @param str ファイルパス
   * @return true ファイルが存在する
   * @return false ファイルが存在しない
   */
  bool IsExists(const std::string& str) override;
};
}  // namespace file
}  // namespace system
}  // namespace mhl

#endif  // MHL_SYSTEM_FILE_FILE_EXISTS_CHECKER_HPP_
