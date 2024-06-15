#ifndef MHL_OUTPUT_CONSOLE_OUTPUTCONSOLE_HPP_
#define MHL_OUTPUT_CONSOLE_OUTPUTCONSOLE_HPP_

#include <mhl/output/console/IConsoleOutputable.hpp>
#include <string>

namespace mhl
{

    namespace output
    {

        namespace console
        {

            // コンソール出力クラス
            class OutputConsole : public IConsoleOutputable
            {
            public:
                /**
                 * コンストラクタ
                 */
                OutputConsole();

                /**
                 * デストラクタ
                 */
                ~OutputConsole() override;

                /**
                 * 文字列を出力する
                 */
                void Print(std::string string) override;

                /**
                 * 改行付き文字列を出力する
                 */
                void PrintLine(std::string string) override;
            };

        } // namespace console

    } // namespace output

} // namespace mhl

#endif  // MHL_OUTPUT_CONSOLE_OUTPUTCONSOLE_HPP_
