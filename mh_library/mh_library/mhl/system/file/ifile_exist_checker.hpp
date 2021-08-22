#ifndef MHL_SYSTEM_FILE_IFILE_EXIST_CHECKER_HPP_
#define MHL_SYSTEM_FILE_IFILE_EXIST_CHECKER_HPP_

#include <string>

namespace mhl {
namespace system {
namespace file {

/**
 * @brief ファイル存在確認インターフェースクラス
 *
 */
class IFileExistChecker {
 public:
  /**
   * @brief デストラクタ
   *
   */
  virtual ~IFileExistChecker() {}

  /**
   * @brief ファイルが存在するかチェック
   *
   * @param str ファイルパス
   * @return true ファイルが存在する
   * @return false ファイルが存在しない
   */
  virtual bool IsExists(const std::string& str) = 0;
};
}  // namespace file
}  // namespace system
}  // namespace mhl

#endif  // MHL_SYSTEM_FILE_IFILE_EXIST_CHECKER_HPP_
