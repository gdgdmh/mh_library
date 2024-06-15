#include "a_pch.h"
#include "mhl/system/file/FileExistsCheckerWin.hpp"
// 他のincludeより下じゃないとおかしくなる
#include <shlobj.h>

namespace mhl
{
    namespace system
    {
        namespace file
        {

            /**
             * @brief ドキュメントフォルダ存在チェック
             *
             */
            TEST(FileExistsCheckerWin, CheckDocumentFolderExists)
            {
                FileExistsCheckerWin fc;

                TCHAR path[MAX_PATH];
                SHGetSpecialFolderPath(nullptr, path, CSIDL_PERSONAL, 0);

                // ドキュメントフォルダパスを取得(普通は存在している)
#ifdef UNICODE
                std::vector<char> buffer;
                int32_t size = WideCharToMultiByte(CP_UTF8, 0, path, -1, nullptr, 0, nullptr, nullptr);
                if (size > 0)
                {
                    buffer.resize(size);
                    WideCharToMultiByte(CP_UTF8, 0, path, -1, &buffer[0],
                                        static_cast<int32_t>(buffer.size()), nullptr, nullptr);
                }
                else
                {
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
            TEST(FileExistsCheckerWin, CheckCurrentDirectoryDummyFileNotExists)
            {
                FileExistsCheckerWin fc;
                // カレントディレクトリに絶対に存在しないファイル名
                std::string notExistsDummyFile = "abcdefghijklmnopqrstuvwxyz0123210.jpg";
                EXPECT_EQ(fc.IsExists(notExistsDummyFile), false);
            }

            /**
             * @brief 空のパスを指定したらfalseになるか
             *
             */
            TEST(FileExistsCheckerWin, PathEmpty)
            {
                FileExistsCheckerWin fc;
                std::string path = "";
                EXPECT_EQ(fc.IsExists(path), false);
            }

        } // namespace file
    } // namespace system
} // namespace mhl
