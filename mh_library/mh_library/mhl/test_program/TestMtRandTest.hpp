#ifndef MHL_TEST_PROGRAM_TEST_MT_RAND_TEST_HPP_
#define MHL_TEST_PROGRAM_TEST_MT_RAND_TEST_HPP_

#include <stdint.h>

#include <memory>
#include <mhl/system/rand/IRandGetable.hpp>
#include <mhl/test/UnittestBase.hpp>

namespace test_program
{

    /**
     * @brief メルセンヌ・ツイスタ乱数のテスト
     *
     */
    class TestMtRandTest : public mhl::UnitTestBase
    {
    public:
        /**
         * コンストラクタ
         */
        TestMtRandTest(std::shared_ptr<mhl::output::console::IConsoleOutputables>
            output_console);

        /**
         * デストラクタ
         */
        ~TestMtRandTest() override;

        void ExecuteUnitTest() override;

    private:
        std::shared_ptr<mhl::IRandGetable> mt_;
    };

} // namespace test_program

#endif  // MHL_TEST_PROGRAM_TEST_MT_RAND_TEST_HPP_
