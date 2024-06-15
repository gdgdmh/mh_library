#ifndef MHL_TEST_CODE_TESTCALLBACKTEST_HPP_
#define MHL_TEST_CODE_TESTCALLBACKTEST_HPP_

#include <functional>
#include <memory>
#include <mhl/test/UnittestBase.hpp>

namespace test_program
{

    class CallbackInner
    {
    public:
        using CallbackInnerComplete = std::function<void(uint32_t, uint32_t)>;

        CallbackInner();
        virtual ~CallbackInner();
        void Execute(CallbackInnerComplete callback);
    };

    class CallbackOuter
    {
    public:
        using CallbackOuterComplete = std::function<void(bool)>;

        CallbackOuter();
        virtual ~CallbackOuter();

        void Execute(CallbackOuterComplete callback);
    };

    // callbackテスト
    class TestCallbackTest : public mhl::UnitTestBase
    {
    public:
        /**
         * コンストラクタ
         */
        TestCallbackTest(std::shared_ptr<mhl::output::console::IConsoleOutputables>
            output_console);

        /**
         * デストラクタ
         */
        ~TestCallbackTest() override;

        void ExecuteUnitTest() override;

        bool OuterCallback();
    };

} // namespace test_program

#endif  // MHL_TEST_CODE_TESTCALLBACKTEST_HPP_
