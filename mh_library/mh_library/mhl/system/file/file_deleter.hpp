#ifndef MHL_SYSTEM_FILE_FILE_DELETER_HPP_
#define MHL_SYSTEM_FILE_FILE_DELETER_HPP_

#include "ifile_deleter.hpp"

namespace mhl {
namespace system {
namespace file {

/**
 * @brief ファイル削除クラス
 *
 */
class FileDeleter : public IFileDeleter {
 public:
  /**
   * @brief コンストラクタ
   *
   */
  FileDeleter();

  /**
   * @brief デストラクタ
   *
   */
  virtual ~FileDeleter() override;

  /**
   * @brief ファイル削除
   *
   * @param file_path ファイルパス
   * @return true ファイル削除に成功
   * @return false ファイル削除に失敗
   */
  bool DeleteFile(const std::string& file_path) override;
};
}  // namespace file
}  // namespace system
}  // namespace mhl

#endif  // MHL_SYSTEM_FILE_FILE_DELETER_HPP_
