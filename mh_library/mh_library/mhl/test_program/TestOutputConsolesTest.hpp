#ifndef MHL_TEST_PROGRAM_TEST_OUTPUT_CONSOLES_TEST_HPP_
#define MHL_TEST_PROGRAM_TEST_OUTPUT_CONSOLES_TEST_HPP_

#include <stdint.h>

#include <memory>
#include <mhl/test/UnittestBase.hpp>

namespace test_program
{

    class TestOutputConsolesTest : public mhl::UnitTestBase
    {
    public:
        /**
         * コンストラクタ
         */
        TestOutputConsolesTest(
            std::shared_ptr<mhl::output::console::IConsoleOutputables>
            output_console);

        /**
         * デストラクタ
         */
        ~TestOutputConsolesTest() override;

        /**
         * @brief テスト
         *
         */
        void ExecuteUnitTest() override;
    };

} // namespace test_program

#endif  // MHL_TEST_PROGRAM_TEST_OUTPUT_CONSOLES_TEST_HPP_
