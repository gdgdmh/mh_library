#ifndef MHL_DEBUG_STACKTRACE_GET_STACKTRACE_WIN_HPP_
#define MHL_DEBUG_STACKTRACE_GET_STACKTRACE_WIN_HPP_

// windows環境
#ifdef _MSC_VER
// #include <imagehlp.h>より先にincludeする必要がある
// cppでincludeすると順番によってはコンパイルエラーが発生する
// 安全のためにヘッダでincludeする
#include <windows.h>

#include "istacktraceable.hpp"

namespace mhl {

/**
 * @brief Windows版スタックトレース情報取得
 *
 */
class GetStacktraceWin : public IStacktraceable {
 public:
  /**
   * @brief コンストラクタ
   *
   */
  GetStacktraceWin();

  /**
   * @brief デストラクタ
   *
   */
  virtual ~GetStacktraceWin();

 public:
  /**
   * @brief スタックトレース情報取得
   *
   * @param info スタックトレース情報を返す変数
   */
  void GetStacktrace(mhl::StacktraceInfo& info) override;
};

}  // namespace mhl

#endif  // _MSC_VER

#endif  // MHL_DEBUG_STACKTRACE_GET_STACKTRACE_WIN_HPP_
