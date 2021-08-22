
#include "a_pch.h"
#include "mhl/system/file/file_deleter.hpp"
#include "mhl/system/file/file_exists_checker_win.hpp"
#include "mhl/system/file/text/textfile_writer.hpp"

namespace mhl {
namespace system {
namespace file {
namespace text {

/**
 * @brief 作成テスト
 * ファイル読み込みはまだ作ってないので厳密にテストできてない
 */
TEST(TextfileWriter, AddCreateTest) {
  std::string path = "test_textfile_writer_addcreatetest.txt";
  // 念の為に消しておく
  mhl::system::file::FileDeleter fd;
  fd.Delete(path);

  mhl::system::file::text::TextfileWriter tw;
  EXPECT_EQ(tw.Open(path, mhl::system::file::text::Mode::kAdd), true);
  EXPECT_EQ(tw.WriteLine("a"), true);
  EXPECT_EQ(tw.Close(), true);
  // ファイルが存在していることを確認
  mhl::system::file::FileExistsCheckerWin fc;
  EXPECT_EQ(fc.IsExists(path), true);
  // cleanup
  fd.Delete(path);
}

TEST(TextfileWriter, NewWriteCreateTest) {
  std::string path = "test_textfile_writer_newwritecreatetest.txt";
  // 念の為に消しておく
  mhl::system::file::FileDeleter fd;
  fd.Delete(path);

  mhl::system::file::text::TextfileWriter tw;
  EXPECT_EQ(tw.Open(path, mhl::system::file::text::Mode::kNewWrite), true);
  EXPECT_EQ(tw.WriteLine("a"), true);
  EXPECT_EQ(tw.Close(), true);
  // ファイルが存在していることを確認
  mhl::system::file::FileExistsCheckerWin fc;
  EXPECT_EQ(fc.IsExists(path), true);
  // cleanup
  fd.Delete(path);
}

}  // namespace text
}  // namespace file
}  // namespace system
}  // namespace mhl
