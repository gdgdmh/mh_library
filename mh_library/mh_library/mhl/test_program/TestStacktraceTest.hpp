#ifndef MHL_TEST_PROGRAM_TEST_STACKTRACE_TEST_HPP_
#define MHL_TEST_PROGRAM_TEST_STACKTRACE_TEST_HPP_

#include <stdint.h>

#include <memory>
#include <mhl/test/UnittestBase.hpp>

namespace test_program
{

    /**
     * @brief スタックトレース情報取得テスト
     *
     */
    class TestStacktraceTest : public mhl::UnitTestBase
    {
    public:
        /**
         * コンストラクタ
         */
        TestStacktraceTest(std::shared_ptr<mhl::output::console::IConsoleOutputables>
            output_console);

        /**
         * デストラクタ
         */
        ~TestStacktraceTest() override;

        void ExecuteUnitTest() override;
    };

} // namespace test_program

#endif  // MHL_TEST_PROGRAM_TEST_STACKTRACE_TEST_HPP_
