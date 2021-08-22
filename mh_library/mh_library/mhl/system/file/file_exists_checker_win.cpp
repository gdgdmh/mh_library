#include "file_exists_checker_win.hpp"

#include <Shlwapi.h>

#pragma comment(lib, "Shlwapi.lib")

/**
 * @brief コンストラクタ
 *
 */
mhl::system::file::FileExistsCheckerWin::FileExistsCheckerWin() {}

/**
 * @brief デストラクタ
 *
 */
mhl::system::file::FileExistsCheckerWin::~FileExistsCheckerWin() {}

/**
 * @brief ファイルが存在するかチェック
 *
 * @param str ファイルパス
 * @return true ファイルが存在する
 * @return false ファイルが存在しない
 */
bool mhl::system::file::FileExistsCheckerWin::IsExists(const std::string& str) {
  if (str.empty()) {
    return false;
  }
  if (PathFileExistsA(str.c_str())) {
    return true;
  }
  return false;
}
