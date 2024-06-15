#ifndef MHL_OUTPUT_CONSOLE_DUMMYOUTPUTCONSOLE_HPP_
#define MHL_OUTPUT_CONSOLE_DUMMYOUTPUTCONSOLE_HPP_

#include <mhl/output/console/IConsoleOutputable.hpp>
#include <string>

namespace mhl
{

    namespace output
    {

        namespace console
        {

            // ダミーコンソール出力クラス
            class DummyOutputConsole : public IConsoleOutputable
            {
            public:
                /**
                 * コンストラクタ
                 */
                DummyOutputConsole();

                /**
                 * デストラクタ
                 */
                ~DummyOutputConsole() override;

                /**
                 * 文字列を出力する(ダミーなので出力はしない)
                 */
                void Print(std::string string) override;

                /**
                 * 改行付き文字列を出力する(ダミーなので出力はしない)
                 */
                void PrintLine(std::string string) override;
            };

        } // namespace console

    } // namespace output

} // namespace mhl

#endif  // MHL_OUTPUT_CONSOLE_DUMMYOUTPUTCONSOLE_HPP_
