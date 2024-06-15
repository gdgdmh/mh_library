#ifndef MHL_TEST_CODE_TESTMHL_HPP_
#define MHL_TEST_CODE_TESTMHL_HPP_

#include <memory>
#include <mhl/test/UnittestBase.hpp>

namespace test_code
{

    // MHLテストクラス
    class TestMhl : public mhl::UnitTestBase
    {
    public:
        /**
         * コンストラクタ
         */
        TestMhl(std::shared_ptr<mhl::output::console::IConsoleOutputables>
            output_console);

        /**
         * デストラクタ
         */
        ~TestMhl() override;

        void ExecuteUnitTest() override;
    };

} // namespace test_code

#endif  // MHL_TEST_CODE_TESTMHL_HPP_
