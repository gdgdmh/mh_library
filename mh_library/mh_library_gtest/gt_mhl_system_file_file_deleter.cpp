
#include "a_pch.h"
#include "mhl/system/file/file_deleter.hpp"
#include "mhl/system/file/text/textfile_writer.hpp"

namespace mhl {
namespace system {
namespace file {

/**
 * @brief ファイル作成して削除テスト
 *
 */
TEST(FileDeleter, CreateAndDelete) {
  std::string path = "test_filedeleter_createanddelete.txt";
  // 予め消しておく
  mhl::system::file::FileDeleter fd;
  fd.Delete(path);

  // テキスト書き込みをする
  mhl::system::file::text::TextfileWriter tw;
  EXPECT_EQ(tw.Open(path, mhl::system::file::text::Mode::kAdd), true);
  EXPECT_EQ(tw.Write("a"), true);
  EXPECT_EQ(tw.Close(), true);
  // テキストが存在しているので消せる
  EXPECT_EQ(fd.Delete(path), true);
}

/**
 * @brief 存在しないファイルを削除しようとするテスト
 *
 */
TEST(FileDeleter, NotExistsFileDelete) {
  std::string path = "test_filedeleter_notexistsfiledelete.txt";
  // 予め消しておく
  mhl::system::file::FileDeleter fd;
  fd.Delete(path);
  // ファイルが存在しない状態で消そうとしたらfalseになる
  EXPECT_EQ(fd.Delete(path), false);
}

/**
 * @brief 空のパスを指定するテスト
 *
 */
TEST(FileDeleter, PathEmpty) {
  std::string path = "";
  mhl::system::file::FileDeleter fd;
  EXPECT_EQ(fd.Delete(path), false);
}

}  // namespace file
}  // namespace system
}  // namespace mhl
