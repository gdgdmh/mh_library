#include "TestFreeTest.hpp"

#include <shlobj.h>
#include <stdint.h>

#include <mhl/output/log/ILogOutputable.hpp>
#include <mhl/output/log/ILogOutputables.hpp>
#include <mhl/output/log/OutputLog.hpp>
#include <mhl/output/log/OutputLogs.hpp>
#include <mhl/system/file/FileDeleter.hpp>
#include <mhl/system/file/FileExistsCheckerWin.hpp>
#include <mhl/system/file/text/TextfileWriter.hpp>
#include <mhl/system/variable_length_arguments/GetVariableLengthArguments.hpp>

/**
 * コンストラクタ
 */
test_program::TestFreeTest::TestFreeTest(
    std::shared_ptr<mhl::output::console::IConsoleOutputables> output_console) :
    UnitTestBase(output_console)
{
}

/**
 * デストラクタ
 */
test_program::TestFreeTest::~TestFreeTest()
{
}

void test_program::TestFreeTest::ExecuteUnitTest()
{
    TestGetVariableLengthArguments();
    TestFileExistsChecker();
    TestTextfileWriter();
    TestFileExistsChecker();
    TestFileDeleter();
    TestFileExistsChecker();
    TestOutputLog();
    TestOutputLogs();
}

void test_program::TestFreeTest::TestGetVariableLengthArguments()
{
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

void test_program::TestFreeTest::TestTextfileWriter()
{
    mhl::system::file::text::TextfileWriter tw;
    tw.Open("test.txt", mhl::system::file::text::Mode::kNewWrite);
    tw.WriteLine("aaa");
    tw.WriteLine("bbb");
    tw.Close();
}

void test_program::TestFreeTest::TestFileExistsChecker()
{
    mhl::system::file::FileExistsCheckerWin fc;

    TCHAR path[MAX_PATH];
    SHGetSpecialFolderPath(nullptr, path, CSIDL_PERSONAL, 0);

    // std::string s = path;
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
    std::string s(&buffer[0]);
#else
  std::string s(path);
#endif  // UNICODE

    // if (fc.IsExists("test.txt")) {
    if (fc.IsExists(s))
    {
        int aa = 10;
        aa = 20;
    }
    else
    {
        int bb = 10;
        bb = 20;
    }
}

void test_program::TestFreeTest::TestFileDeleter()
{
    mhl::system::file::FileDeleter fd;
    fd.Delete("test.txt");
}

void test_program::TestFreeTest::TestOutputLog()
{
    const std::string &file_name = "testoutput.txt";

    // テスト前に消しておく
    mhl::system::file::FileDeleter fd;
    fd.Delete(file_name);

    auto writer =
        std::make_shared<mhl::system::file::text::TextfileWriter>();

    mhl::output::log::OutputLog output_log(writer);

    output_log.Initialize(file_name, mhl::system::file::text::Mode::kNewWrite);

    output_log.PrintLine("testテストtest");
    output_log.PrintLine("yaho-");

    output_log.Finalize();

    // テスト終了後消す
    fd.Delete(file_name);
}

void test_program::TestFreeTest::TestOutputLogs()
{
    const std::string &file_name1 = "testoutput1.txt";
    const std::string &file_name2 = "testoutput2.txt";

    // テスト前に消しておく
    mhl::system::file::FileDeleter fd;
    fd.Delete(file_name1);
    fd.Delete(file_name2);

    mhl::output::log::OutputLogs output_logs;

    {
        std::shared_ptr<mhl::system::file::text::ITextfileWriter> writer =
            std::make_shared<mhl::system::file::text::TextfileWriter>();
        std::shared_ptr<mhl::output::log::ILogOutputable> output_log =
            std::make_shared<mhl::output::log::OutputLog>(writer);

        output_log->Initialize(file_name1,
                               mhl::system::file::text::Mode::kNewWrite);
        output_logs.Add(output_log);
    }
    {
        std::shared_ptr<mhl::system::file::text::ITextfileWriter> writer =
            std::make_shared<mhl::system::file::text::TextfileWriter>();
        std::shared_ptr<mhl::output::log::ILogOutputable> output_log =
            std::make_shared<mhl::output::log::OutputLog>(writer);

        output_log->Initialize(file_name2,
                               mhl::system::file::text::Mode::kNewWrite);
        output_logs.Add(output_log);
    }
    output_logs.PrintLine("abcえーびーしー");

    output_logs.Finalize();

    fd.Delete(file_name1);
    fd.Delete(file_name2);
}
