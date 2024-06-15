#ifndef MHL_TEST_CODE_TEST_ASSERT_TEST_HPP_
#define MHL_TEST_CODE_TEST_ASSERT_TEST_HPP_

#include <memory>
#include <mhl/test/UnittestBase.hpp>

namespace test_program
{

    // Assertテスト
    class TestDebugAssertTest : public mhl::UnitTestBase
    {
    public:
        /**
         * コンストラクタ
         */
        TestDebugAssertTest(std::shared_ptr<mhl::output::console::IConsoleOutputables>
            output_console);

        /**
         * デストラクタ
         */
        ~TestDebugAssertTest() override;

        void ExecuteUnitTest() override;
    };

} // namespace test_program

#endif  // MHL_TEST_CODE_TEST_ASSERT_TEST_HPP_
