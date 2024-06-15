#include <memory>

#include "a_pch.h"  // 必須include
#include "mhl/output/console/IConsoleOutputable.hpp"
#include "mhl/output/console/OutputConsole.hpp"
#include "mhl/output/console/OutputConsoleVsSjis.hpp"
#include "mhl/output/console/OutputConsoles.hpp"

namespace mhl
{
    namespace output
    {
        namespace console
        {

            /**
             * @brief デフォルトのサイズ
             *
             */
            TEST(Output_Console_OutputConsoles, DefaultSize)
            {
                OutputConsoles o;
                EXPECT_EQ(o.Size(), 0);
            }

            /**
             * @brief Add1回追加のテスト
             *
             */
            TEST(Output_Console_OutputConsoles, Add1)
            {
                OutputConsoles o;
                std::shared_ptr<IConsoleOutputable> output_console(
                    new OutputConsole);
                EXPECT_EQ(o.Size(), 0);
                o.Add(output_console);
                EXPECT_EQ(o.Size(), 1);
            }

            /**
             * @brief Add2回追加のテスト
             *
             */
            TEST(Output_Console_OutputConsoles, Add2)
            {
                OutputConsoles o;
                std::shared_ptr<IConsoleOutputable> output_console(
                    new OutputConsole);
                std::shared_ptr<IConsoleOutputable> output_vs(
                    new OutputConsoleVsSjis);
                EXPECT_EQ(o.Size(), 0);
                o.Add(output_console);
                EXPECT_EQ(o.Size(), 1);
                o.Add(output_vs);
                EXPECT_EQ(o.Size(), 2);
            }

            /**
             * @brief サイズ0に対してClearするテスト
             *
             */
            TEST(Output_Console_OutputConsoles, Clear0)
            {
                OutputConsoles o;
                EXPECT_EQ(o.Size(), 0);
                o.Clear();
                EXPECT_EQ(o.Size(), 0);
            }

            /**
             * @brief Add1に対してClearするテスト
             *
             */
            TEST(Output_Console_OutputConsoles, Clear1)
            {
                OutputConsoles o;
                std::shared_ptr<IConsoleOutputable> output_vs(
                    new OutputConsoleVsSjis);
                EXPECT_EQ(o.Size(), 0);
                o.Add(output_vs);
                EXPECT_EQ(o.Size(), 1);
                o.Clear();
                EXPECT_EQ(o.Size(), 0);
            }

            /**
             * @brief Add2に対してClearするテスト
             *
             */
            TEST(Output_Console_OutputConsoles, Clear2)
            {
                OutputConsoles o;
                std::shared_ptr<IConsoleOutputable> output_console(
                    new OutputConsole);
                std::shared_ptr<IConsoleOutputable> output_vs(
                    new OutputConsoleVsSjis);
                EXPECT_EQ(o.Size(), 0);
                o.Add(output_console);
                EXPECT_EQ(o.Size(), 1);
                o.Add(output_vs);
                EXPECT_EQ(o.Size(), 2);
                o.Clear();
                EXPECT_EQ(o.Size(), 0);
            }

            /**
             * @brief ClearをしたあとにAddするテスト
             *
             */
            TEST(Output_Console_OutputConsoles, ClearAfterAdd1)
            {
                OutputConsoles o;
                std::shared_ptr<IConsoleOutputable> output_console(
                    new OutputConsole);
                EXPECT_EQ(o.Size(), 0);
                o.Add(output_console);
                EXPECT_EQ(o.Size(), 1);
                o.Clear();
                EXPECT_EQ(o.Size(), 0);
                o.Add(output_console);
                EXPECT_EQ(o.Size(), 1);
            }

        } // namespace console
    } // namespace output
} // namespace mhl
