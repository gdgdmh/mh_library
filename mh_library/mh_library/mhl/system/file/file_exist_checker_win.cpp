#include "file_exist_checker_win.hpp"

#include <Shlwapi.h>

#pragma comment(lib, "Shlwapi.lib")

/**
 * @brief コンストラクタ
 *
 */
mhl::system::file::FileExistCheckerWin::FileExistCheckerWin() {}

/**
 * @brief デストラクタ
 *
 */
mhl::system::file::FileExistCheckerWin::~FileExistCheckerWin() {}

/**
 * @brief ファイルが存在するかチェック
 *
 * @param str ファイルパス
 * @return true ファイルが存在する
 * @return false ファイルが存在しない
 */
bool mhl::system::file::FileExistCheckerWin::IsExists(const std::string& str) {
  if (str.empty()) {
    return false;
  }
  if (PathFileExistsA(str.c_str())) {
    return true;
  }
  return false;
}
