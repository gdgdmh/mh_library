#ifndef MHL_SYSTEM_FILE_IFILE_DELETER_HPP_
#define MHL_SYSTEM_FILE_IFILE_DELETER_HPP_

#include <string>

namespace mhl {
namespace system {
namespace file {

/**
 * @brief ファイル削除インターフェースクラス
 *
 */
class IFileDeleter {
 public:
  /**
   * @brief デストラクタ
   *
   */
  virtual ~IFileDeleter() {}

  /**
   * @brief ファイル削除
   *
   * @param filePath ファイルパス
   * @return true ファイル削除に成功
   * @return false ファイル削除に失敗
   */
  virtual bool Delete(const std::string& filePath) = 0;
};
}  // namespace file
}  // namespace system
}  // namespace mhl

#endif  // MHL_SYSTEM_FILE_IFILE_DELETER_HPP_
