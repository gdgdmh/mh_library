
#include "a_pch.h"
#include "mhl/output/log/output_log.hpp"
#include "mhl/output/log/output_logs.hpp"
#include "mhl/system/file/file_deleter.hpp"
#include "mhl/system/file/file_exists_checker_win.hpp"
#include "mhl/system/file/text/textfile_writer.hpp"

namespace mhl {
namespace output {
namespace log {

/**
 * @brief コンストラクタがサイズが0を返すか
 *
 */
TEST(OutputLogs, ConstractorSizeZero) {
  mhl::output::log::OutputLogs output_logs;
  EXPECT_EQ(output_logs.Size(), 0);
}

/**
 * @brief 2つのoutputlogsを登録してprintで2つファイルが生成されるか
 *
 */
TEST(OutputLogs, Print2MakeFile2) {
  const std::string file_name1 = "gtest_output_logs_print2_1.txt";
  const std::string file_name2 = "gtest_output_logs_print2_2.txt";
  std::vector<std::string> file_names;
  file_names.emplace_back(file_name1);
  file_names.emplace_back(file_name2);

  // Arrange
  mhl::system::file::FileDeleter fd;
  for (const auto& name : file_names) {
    fd.Delete(name);
  }

  // Act
  mhl::output::log::OutputLogs output_logs;
  for (const auto& name : file_names) {
    std::shared_ptr<mhl::system::file::text::TextfileWriter> writer =
        std::make_shared<mhl::system::file::text::TextfileWriter>();
    std::shared_ptr<mhl::output::log::OutputLog> output_log =
        std::make_shared<mhl::output::log::OutputLog>(writer);
    output_log->Initialize(name, mhl::system::file::text::Mode::kAdd);

    EXPECT_EQ(output_logs.Add(output_log), true);
  }
  EXPECT_EQ(output_logs.Size(), 2);

  // 厳密な書き込みチェックができないのでファイルが存在するかでチェック
  output_logs.Print("abcあいうえお");

  output_logs.Finalize();
  // Assert
  for (const auto& name : file_names) {
    mhl::system::file::FileExistsCheckerWin fe;
    bool is_exist = fe.IsExists(name);
    EXPECT_EQ(is_exist, true);
  }

  // Cleanup
  for (const auto& name : file_names) {
    fd.Delete(name);
  }
}

TEST(OutputLogs, PrintLine2) {
  const std::string file_name1 = "gtest_output_logs_printline2_1.txt";
  const std::string file_name2 = "gtest_output_logs_printline2_2.txt";
  std::vector<std::string> file_names;
  file_names.emplace_back(file_name1);
  file_names.emplace_back(file_name2);

  // Arrange
  mhl::system::file::FileDeleter fd;
  for (const auto& name : file_names) {
    fd.Delete(name);
  }

  // Act
  mhl::output::log::OutputLogs output_logs;
  for (const auto& name : file_names) {
    std::shared_ptr<mhl::system::file::text::TextfileWriter> writer =
        std::make_shared<mhl::system::file::text::TextfileWriter>();
    std::shared_ptr<mhl::output::log::OutputLog> output_log =
        std::make_shared<mhl::output::log::OutputLog>(writer);
    output_log->Initialize(name, mhl::system::file::text::Mode::kAdd);

    EXPECT_EQ(output_logs.Add(output_log), true);
  }
  EXPECT_EQ(output_logs.Size(), 2);

  // 厳密な書き込みチェックができないのでファイルが存在するかでチェック
  output_logs.PrintLine("abcあいうえお");

  output_logs.Finalize();
  // Assert
  for (const auto& name : file_names) {
    mhl::system::file::FileExistsCheckerWin fe;
    bool is_exist = fe.IsExists(name);
    EXPECT_EQ(is_exist, true);
  }

  // Cleanup
  for (const auto& name : file_names) {
    fd.Delete(name);
  }
}

/**
 * @brief test
 *
 */
TEST(OutputLogs, Add2) {
  const std::string file_name1 = "gtest_output_logs_add2_1.txt";
  const std::string file_name2 = "gtest_output_logs_add2_2.txt";
  std::vector<std::string> file_names;
  file_names.emplace_back(file_name1);
  file_names.emplace_back(file_name2);

  // Arrange
  mhl::system::file::FileDeleter fd;
  for (const auto& name : file_names) {
    fd.Delete(name);
  }

  // Act
  mhl::output::log::OutputLogs output_logs;
  for (const auto& name : file_names) {
    std::shared_ptr<mhl::system::file::text::TextfileWriter> writer =
        std::make_shared<mhl::system::file::text::TextfileWriter>();
    std::shared_ptr<mhl::output::log::OutputLog> output_log =
        std::make_shared<mhl::output::log::OutputLog>(writer);
    output_log->Initialize(name, mhl::system::file::text::Mode::kAdd);

    EXPECT_EQ(output_logs.Add(output_log), true);
  }
  // Assert
  EXPECT_EQ(output_logs.Size(), 2);
  output_logs.Finalize();
  for (const auto& name : file_names) {
    mhl::system::file::FileExistsCheckerWin fe;
    bool is_exist = fe.IsExists(name);
    EXPECT_EQ(is_exist, true);
  }

  // Cleanup
  for (const auto& name : file_names) {
    fd.Delete(name);
  }
}

TEST(OutputLogs, AddNotInitializedObject) {
  const std::string file_name1 =
      "gtest_output_logs_addnotinitializedobject1.txt";
  std::vector<std::string> file_names;
  file_names.emplace_back(file_name1);

  // Arrange
  mhl::system::file::FileDeleter fd;
  for (const auto& name : file_names) {
    fd.Delete(name);
  }

  // Act
  // Assert
  mhl::output::log::OutputLogs output_logs;
  for (const auto& name : file_names) {
    std::shared_ptr<mhl::system::file::text::TextfileWriter> writer =
        std::make_shared<mhl::system::file::text::TextfileWriter>();
    std::shared_ptr<mhl::output::log::OutputLog> output_log =
        std::make_shared<mhl::output::log::OutputLog>(writer);
    EXPECT_EQ(output_logs.Add(output_log), false);
  }

  // Cleanup
  output_logs.Finalize();
  for (const auto& name : file_names) {
    fd.Delete(name);
  }
}

TEST(OutputLogs, ClearSize0) {
  mhl::output::log::OutputLogs output_logs;
  EXPECT_EQ(output_logs.Size(), 0);
  output_logs.Clear();
  EXPECT_EQ(output_logs.Size(), 0);
}

TEST(OutputLogs, ClearSize2) {
  const std::string file_name1 = "gtest_output_logs_clearsize2_1.txt";
  const std::string file_name2 = "gtest_output_logs_clearsize2_2.txt";
  std::vector<std::string> file_names;
  file_names.emplace_back(file_name1);
  file_names.emplace_back(file_name2);

  // Arrange
  mhl::system::file::FileDeleter fd;
  for (const auto& name : file_names) {
    fd.Delete(name);
  }

  // Act
  mhl::output::log::OutputLogs output_logs;
  for (const auto& name : file_names) {
    std::shared_ptr<mhl::system::file::text::TextfileWriter> writer =
        std::make_shared<mhl::system::file::text::TextfileWriter>();
    std::shared_ptr<mhl::output::log::OutputLog> output_log =
        std::make_shared<mhl::output::log::OutputLog>(writer);
    output_log->Initialize(name, mhl::system::file::text::Mode::kAdd);

    output_logs.Add(output_log);
  }
  EXPECT_EQ(output_logs.Size(), 2);
  output_logs.Clear();
  EXPECT_EQ(output_logs.Size(), 0);

  // Assert
  for (const auto& name : file_names) {
    mhl::system::file::FileExistsCheckerWin fe;
    bool is_exist = fe.IsExists(name);
    EXPECT_EQ(is_exist, true);
  }

  // Cleanup
  for (const auto& name : file_names) {
    fd.Delete(name);
  }
}

}  // namespace log
}  // namespace output
}  // namespace mhl
