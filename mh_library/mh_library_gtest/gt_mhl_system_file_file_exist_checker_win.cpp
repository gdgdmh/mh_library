#include "a_pch.h"
#include "mhl/system/file/file_exists_checker_win.hpp"
// 他のincludeより下じゃないとおかしくなる
#include <shlobj.h>

namespace mhl {
namespace system {
namespace file {

/**
 * @brief ドキュメントフォルダ存在チェック
 *
 */
TEST(FileExistsCheckerWin, CheckDocumentFolderExists) {
  mhl::system::file::FileExistsCheckerWin fc;

  TCHAR path[MAX_PATH];
  SHGetSpecialFolderPath(NULL, path, CSIDL_PERSONAL, 0);

  // ドキュメントフォルダパスを取得(普通は存在している)
#ifdef UNICODE
  std::vector<char> buffer;
  int32_t size = WideCharToMultiByte(CP_UTF8, 0, path, -1, NULL, 0, NULL, NULL);
  if (size > 0) {
    buffer.resize(size);
    WideCharToMultiByte(CP_UTF8, 0, path, -1, static_cast<LPSTR>(&buffer[0]),
                        static_cast<int32_t>(buffer.size()), NULL, NULL);
  } else {
    // Error
  }
  std::string pathStr(&buffer[0]);
#else
  std::string pathStr(path);
#endif  // UNICODE

  EXPECT_EQ(fc.IsExists(pathStr), true);
}

/**
 * @brief 現在のディレクトリに絶対存在しないファイルを指定してfalseになるか
 *
 */
TEST(FileExistsCheckerWin, CheckCurrentDirectoryDummyFileNotExists) {
  mhl::system::file::FileExistsCheckerWin fc;
  // カレントディレクトリに絶対に存在しないファイル名
  std::string notExistsDummyFile = "abcdefghijklmnopqrstuvwxyz0123210.jpg";
  EXPECT_EQ(fc.IsExists(notExistsDummyFile), false);
}

/**
 * @brief 空のパスを指定したらfalseになるか
 *
 */
TEST(FileExistsCheckerWin, PathEmpty) {
  mhl::system::file::FileExistsCheckerWin fc;
  std::string path = "";
  EXPECT_EQ(fc.IsExists(path), false);
}

}  // namespace file
}  // namespace system
}  // namespace mhl
