#include "test_free_test.hpp"

#include <stdint.h>

#include "../system/variable_length_arguments/get_variable_length_arguments.hpp"
#include "../system/file/text/textfile_writer.hpp"
#include "../system/file/file_deleter.hpp"
#include "../system/file/file_exist_checker_win.hpp"

/**
 * コンストラクタ
 */
test_program::TestFreeTest::TestFreeTest(
    std::shared_ptr<mhl::output::console::IConsoleOutputables> output_console)
    : UnitTestBase(output_console) {}

/**
 * デストラクタ
 */
test_program::TestFreeTest::~TestFreeTest() {}

void test_program::TestFreeTest::ExecuteUnitTest() {
  TestGetVariableLengthArguments();
  TestFileExistsChecker();
  TestTextfileWriter();
  TestFileExistsChecker();
  TestFileDeleter();
  TestFileExistsChecker();
}

void test_program::TestFreeTest::TestGetVariableLengthArguments() {
  mhl::system::variable_length_arguments::GetVariableLengthArguments get;
  {
    std::string s;
    int32_t value = 10;
    get.ToString(s, "value=%d", value);
  }
  {
    constexpr size_t kStrSize = 100;
    char str[kStrSize];
    int32_t value = 10;
    get.ToChar(str, kStrSize, "value=%d", value);
    int32_t tmp = 0;
    tmp = 10;
  }
}

void test_program::TestFreeTest::TestTextfileWriter() {
  mhl::system::file::text::TextfileWriter tw;
  tw.Open("test.txt", mhl::system::file::text::Mode::kNewWrite);
  tw.WriteLine("aaa");
  tw.WriteLine("bbb");
  tw.Close();
}

void test_program::TestFreeTest::TestFileExistsChecker() {
  mhl::system::file::FileExistCheckerWin fc;
  if (fc.IsExists("test.txt")) {
  } else {
  }
}

void test_program::TestFreeTest::TestFileDeleter() {
  mhl::system::file::FileDeleter fd;
  fd.DeleteFile("test.txt");
}