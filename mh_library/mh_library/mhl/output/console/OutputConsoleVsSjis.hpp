#ifndef MHL_OUTPUT_CONSOLE_OUTPUTCONSOLE_VS_SJIS_HPP_
#define MHL_OUTPUT_CONSOLE_OUTPUTCONSOLE_VS_SJIS_HPP_

#include <mhl/output/console/IConsoleOutputable.hpp>
#include <string>

namespace mhl
{

    namespace output
    {

        namespace console
        {

            /**
             * @brief VisualStudioの出力ウィンドウに出力
             *
             */
            class OutputConsoleVsSjis : public IConsoleOutputable
            {
            public:
                /**
                 * コンストラクタ
                 */
                OutputConsoleVsSjis();

                /**
                 * デストラクタ
                 */
                ~OutputConsoleVsSjis() override;

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

#endif  // MHL_OUTPUT_CONSOLE_OUTPUTCONSOLE_VS_SJIS_HPP_
