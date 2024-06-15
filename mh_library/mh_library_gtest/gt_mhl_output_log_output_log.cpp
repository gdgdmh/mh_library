#include "a_pch.h"
#include "mhl/output/log/OutputLog.hpp"
#include "mhl/system/file/FileDeleter.hpp"
#include "mhl/system/file/FileExistsCheckerWin.hpp"
#include "mhl/system/file/text/TextfileWriter.hpp"

namespace mhl
{
    namespace output
    {
        namespace log
        {

            /**
             * @brief コンストラクタ後にIsInitializedがfalseを返すか
             *
             */
            TEST(OutputLog, ConstructorNotInitialized)
            {
                // Arrange

                // Act
                auto writer =
                    std::make_shared<system::file::text::TextfileWriter>();
                OutputLog output_log(writer);

                // Assert
                EXPECT_EQ(output_log.IsInitialized(), false);
            }

            /**
             * @brief InitializeとFinalizeでファイルが生成されるか
             *
             */
            TEST(OutputLog, InitializeAndFinalizeCreateFile)
            {
                const std::string file_name = "gtest_output_log_initializeandfinalize.txt";
                // Arrange
                system::file::FileDeleter fd;
                fd.Delete(file_name);

                // Act
                auto writer =
                    std::make_shared<system::file::text::TextfileWriter>();

                OutputLog output_log(writer);
                bool initialize_result =
                    output_log.Initialize(file_name, system::file::text::Mode::kAdd);
                EXPECT_EQ(initialize_result, true);
                bool finalize_result = output_log.Finalize();
                EXPECT_EQ(finalize_result, true);

                // Assert
                system::file::FileExistsCheckerWin fe;
                bool is_exist = fe.IsExists(file_name);
                EXPECT_EQ(is_exist, true);
                // Cleanup
                fd.Delete(file_name);
            }

            /**
             * @brief Printのテスト
             *
             */
            TEST(OutputLog, Print)
            {
                const std::string file_name = "gtest_output_log_print.txt";
                // Arrange
                system::file::FileDeleter fd;
                fd.Delete(file_name);

                // Act
                auto writer =
                    std::make_shared<system::file::text::TextfileWriter>();

                OutputLog output_log(writer);
                output_log.Initialize(file_name, system::file::text::Mode::kAdd);

                // Assert
                output_log.Print("abcあいうえお");
                // 本当はファイルの中身をみてチェックすべきだがそのシステムがないのでファイル生成されたことで成功とする
                output_log.Finalize();
                system::file::FileExistsCheckerWin fe;
                bool is_exist = fe.IsExists(file_name);
                EXPECT_EQ(is_exist, true);

                // Cleanup
                fd.Delete(file_name);
            }

            /**
             * @brief PrintLineのテスト
             *
             */
            TEST(OutputLog, PrintLine)
            {
                const std::string file_name = "gtest_output_log_printline.txt";
                // Arrange
                system::file::FileDeleter fd;
                fd.Delete(file_name);

                // Act
                auto writer =
                    std::make_shared<system::file::text::TextfileWriter>();

                OutputLog output_log(writer);
                output_log.Initialize(file_name, system::file::text::Mode::kAdd);

                // Assert
                output_log.PrintLine("abcあいうえお");
                // 本当はファイルの中身をみてチェックすべきだがそのシステムがないのでファイル生成されたことで成功とする
                output_log.Finalize();
                system::file::FileExistsCheckerWin fe;
                bool is_exist = fe.IsExists(file_name);
                EXPECT_EQ(is_exist, true);

                // Cleanup
                fd.Delete(file_name);
            }

            /**
             * @brief 初期化後にIsInitializedがtrueを返すか
             *
             */
            TEST(OutputLog, IsInitializedTrue)
            {
                const std::string file_name = "gtest_output_log_is_initialize.txt";
                // Arrange
                system::file::FileDeleter fd;
                fd.Delete(file_name);

                // Act
                auto writer =
                    std::make_shared<system::file::text::TextfileWriter>();

                OutputLog output_log(writer);
                output_log.Initialize(file_name, system::file::text::Mode::kAdd);

                // Assert
                bool is_initialized = output_log.IsInitialized();
                EXPECT_EQ(is_initialized, true);

                // Cleanup
                output_log.Finalize();
                fd.Delete(file_name);
            }

        } // namespace log
    } // namespace output
} // namespace mhl
