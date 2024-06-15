#ifndef MHL_OUTPUT_CONSOLE_OUTPUTCONSOLES_HPP_
#define MHL_OUTPUT_CONSOLE_OUTPUTCONSOLES_HPP_

#include <mhl/output/console/IConsoleOutputable.hpp>
#include <mhl/output/console/IConsoleOutputables.hpp>
#include <string>
#include <vector>

namespace mhl
{

    namespace output
    {

        namespace console
        {

            /**
             * @brief 複数コンソール出力クラス
             *
             */
            class OutputConsoles : public IConsoleOutputables
            {
            public:
                /**
                 * コンストラクタ
                 */
                OutputConsoles();

                /**
                 * デストラクタ
                 */
                ~OutputConsoles() override;

                /**
                 * 文字列を出力する
                 */
                void Print(std::string string) override;

                /**
                 * 改行付き文字列を出力する
                 */
                void PrintLine(std::string string) override;

                /**
                 * @brief 出力クラスを追加する
                 *
                 */
                void Add(std::shared_ptr<IConsoleOutputable> &output_console) override;

                /**
                 * @brief 追加された出力クラスをクリアする
                 *
                 */
                void Clear() override;

                /**
                 * @brief 現在登録されている出力クラスの個数を取得する
                 *
                 * @return size_t 出力クラスの個数
                 */
                size_t Size() override;

            private:
                std::vector<std::shared_ptr<IConsoleOutputable>> output_;
            };

        } // namespace console

    } // namespace output

} // namespace mhl

#endif  // MHL_OUTPUT_CONSOLE_OUTPUTCONSOLES_HPP_
