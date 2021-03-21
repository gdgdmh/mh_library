
#include <memory>

#include "a_pch.h"  // 必須include
#include "mhl/output/console/iconsole_outputable.hpp"
#include "mhl/output/console/output_console.hpp"
#include "mhl/output/console/output_console_vs_sjis.hpp"
#include "mhl/output/console/output_consoles.hpp"

namespace mhl {
namespace output {
namespace console {

/**
 * @brief デフォルトのサイズ
 *
 */
TEST(Output_Console_OutputConsoles, DefaultSize) {
  mhl::output::console::OutputConsoles o;
  EXPECT_EQ(o.Size(), 0);
}

/**
 * @brief Add1回追加のテスト
 *
 */
TEST(Output_Console_OutputConsoles, Add1) {
  mhl::output::console::OutputConsoles o;
  std::shared_ptr<mhl::output::console::IConsoleOutputable> output_console(
      new mhl::output::console::OutputConsole);
  EXPECT_EQ(o.Size(), 0);
  o.Add(output_console);
  EXPECT_EQ(o.Size(), 1);
}

/**
 * @brief Add2回追加のテスト
 *
 */
TEST(Output_Console_OutputConsoles, Add2) {
  mhl::output::console::OutputConsoles o;
  std::shared_ptr<mhl::output::console::IConsoleOutputable> output_console(
      new mhl::output::console::OutputConsole);
  std::shared_ptr<mhl::output::console::IConsoleOutputable> output_vs(
      new mhl::output::console::OutputConsoleVsSjis);
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
TEST(Output_Console_OutputConsoles, Clear0) {
  mhl::output::console::OutputConsoles o;
  EXPECT_EQ(o.Size(), 0);
  o.Clear();
  EXPECT_EQ(o.Size(), 0);
}

/**
 * @brief Add1に対してClearするテスト
 *
 */
TEST(Output_Console_OutputConsoles, Clear1) {
  mhl::output::console::OutputConsoles o;
  std::shared_ptr<mhl::output::console::IConsoleOutputable> output_vs(
      new mhl::output::console::OutputConsoleVsSjis);
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
TEST(Output_Console_OutputConsoles, Clear2) {
  mhl::output::console::OutputConsoles o;
  std::shared_ptr<mhl::output::console::IConsoleOutputable> output_console(
      new mhl::output::console::OutputConsole);
  std::shared_ptr<mhl::output::console::IConsoleOutputable> output_vs(
      new mhl::output::console::OutputConsoleVsSjis);
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
TEST(Output_Console_OutputConsoles, ClearAfterAdd1) {
  mhl::output::console::OutputConsoles o;
  std::shared_ptr<mhl::output::console::IConsoleOutputable> output_console(
      new mhl::output::console::OutputConsole);
  EXPECT_EQ(o.Size(), 0);
  o.Add(output_console);
  EXPECT_EQ(o.Size(), 1);
  o.Clear();
  EXPECT_EQ(o.Size(), 0);
  o.Add(output_console);
  EXPECT_EQ(o.Size(), 1);
}

}  // namespace console
}  // namespace output
}  // namespace mhl
