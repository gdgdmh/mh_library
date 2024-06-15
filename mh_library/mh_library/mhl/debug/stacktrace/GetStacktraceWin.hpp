#ifndef MHL_DEBUG_STACKTRACE_GET_STACKTRACE_WIN_HPP_
#define MHL_DEBUG_STACKTRACE_GET_STACKTRACE_WIN_HPP_

// windows環境
#ifdef _MSC_VER
// #include <imagehlp.h>より先にincludeする必要がある
// cppでincludeすると順番によってはコンパイルエラーが発生する
// 安全のためにヘッダでincludeする
#include <windows.h>

#include <mhl/debug/stacktrace/IStacktraceable.hpp>

namespace mhl
{

    namespace debug
    {

        namespace stacktrace
        {

            /**
             * @brief Windows版スタックトレース情報取得
             *
             */
            class GetStacktraceWin : public IStacktraceable
            {
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
                ~GetStacktraceWin() override;

                /**
                 * @brief スタックトレース情報取得
                 *
                 * @param info スタックトレース情報を返す変数
                 */
                void GetStacktrace(StacktraceInfo &info) override;

                /**
                 * @brief スタックトレース情報を文字列で返す
                 *
                 * @param stacktraceInfo 文字列を受け取る変数
                 * @param info スタックトレース情報
                 */
                void ToStringStacktrace(
                    std::string &stacktraceInfo,
                    const StacktraceInfo &info) override;
            };
        } // namespace stacktrace

    } // namespace debug

} // namespace mhl

#endif  // _MSC_VER

#endif  // MHL_DEBUG_STACKTRACE_GET_STACKTRACE_WIN_HPP_
