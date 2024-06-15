#ifndef MHL_TEST_PROGRAM_TEST_FREE_TEST_HPP_
#define MHL_TEST_PROGRAM_TEST_FREE_TEST_HPP_

#include <mhl/test/UnittestBase.hpp>

namespace test_program
{

    /**
     * @brief 自由テスト
     *
     */
    class TestFreeTest : public mhl::UnitTestBase
    {
    public:
        /**
         * コンストラクタ
         */
        TestFreeTest(std::shared_ptr<mhl::output::console::IConsoleOutputables>
            output_console);

        /**
         * デストラクタ
         */
        ~TestFreeTest() override;

        /**
         * @brief テスト実行
         *
         */
        void ExecuteUnitTest() override;

    private:
        void TestGetVariableLengthArguments();
        void TestTextfileWriter();
        void TestFileExistsChecker();
        void TestFileDeleter();
        void TestOutputLog();
        void TestOutputLogs();
    };

} // namespace test_program

#endif  // MHL_TEST_PROGRAM_TEST_FREE_TEST_HPP_
