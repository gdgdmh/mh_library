
#include "a_pch.h"
#include "mhl/debug/stacktrace/stacktrace_info.hpp"
#include "mhl/debug/stacktrace/get_stacktrace_win.hpp"

namespace mhl {
namespace debug {
namespace stacktrace {
namespace get_stacktrace_win {

/**
 * @brief スタックトレース情報取得(win)
 *
 */
TEST(Debug_Stacktrace_GetStacktraceWin, Get) {
  mhl::GetStacktraceWin getStacktrace;
  mhl::StacktraceInfo info;
  getStacktrace.GetStacktrace(info);

  // 取得できるスタックトレースは1より大きいはず
  EXPECT_GT(info.GetSize(), static_cast<uint32_t>(1));
  // サイズは同一
  EXPECT_EQ(info.GetSize(), info.GetAddresses().size());
  EXPECT_EQ(info.GetSize(), info.GetSymbols().size());
  EXPECT_EQ(info.GetSize(), info.GetFileNames().size());
  EXPECT_EQ(info.GetSize(), info.GetLineNumbers().size());
}

}  // namespace stacktrace_info
}  // namespace stacktrace
}  // namespace debug
}  // namespace mhl
