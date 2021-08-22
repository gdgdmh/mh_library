#include "file_deleter.hpp"

/**
 * @brief コンストラクタ
 *
 */
mhl::system::file::FileDeleter::FileDeleter() {}

/**
 * @brief デストラクタ
 *
 */
mhl::system::file::FileDeleter::~FileDeleter() {}

/**
 * @brief ファイル削除
 *
 * @param file_path ファイルパス
 * @return true ファイル削除に成功
 * @return false ファイル削除に失敗
 */
bool mhl::system::file::FileDeleter::DeleteFile(const std::string& file_path) {
  if (file_path.empty()) {
    return false;
  }
  if (std::remove(file_path.c_str()) == 0) {
    return true;
  }
  return false;
}
