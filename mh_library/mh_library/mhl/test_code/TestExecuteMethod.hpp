#ifndef MHL_TEST_CODE_TESTEXECUTEMETHOD_HPP_
#define MHL_TEST_CODE_TESTEXECUTEMETHOD_HPP_

#include <memory>
#include <mhl/system/template/IExecuteMethod.hpp>
#include <mhl/test/UnittestBase.hpp>

namespace test_code
{

    // メソッド実行テストクラス
    class TestExecuteMethod : public mhl::UnitTestBase
    {
    public:
        using MEB = mhl::IExecuteMethod<TestExecuteMethod>;

        enum class SCENE { kInitialize, kLoad, kMain };

        /**
       * コンストラクタ
       */
        TestExecuteMethod(std::shared_ptr<mhl::output::console::IConsoleOutputables>
            output_console);

        /**
         * デストラクタ
         */
        ~TestExecuteMethod() override;

        void ExecuteUnitTest() override;

        void Task();

        SCENE GetScene()
        {
            return scene_;
        }

        mhl::IExecuteMethod<TestExecuteMethod> Initialize();
        mhl::IExecuteMethod<TestExecuteMethod> Load();
        mhl::IExecuteMethod<TestExecuteMethod> Main();

    private:
        mhl::IExecuteMethod<TestExecuteMethod> on_exec_;
        SCENE scene_;
    };

} // namespace test_code

#endif  // TEST_TESTEXECUTEMETHOD_HPP_
