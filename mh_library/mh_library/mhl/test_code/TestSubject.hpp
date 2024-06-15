#ifndef MHL_TEST_CODE_TESTSUBJECT_HPP_
#define MHL_TEST_CODE_TESTSUBJECT_HPP_

#include <memory>
#include <mhl/system/template/IExecuteMethod.hpp>
#include <mhl/system/template/IObservable.hpp>
#include <mhl/system/template/Subject.hpp>
#include <mhl/test/UnittestBase.hpp>

namespace test_code
{

    // テストのためのクラス
    class TestObserver : public mhl::IObservable
    {
    public:
        TestObserver() :
            value(0)
        {
        }

        void Update(mhl::Subject &subject) override
        {
            value = 1;
        }

        int Get() const
        {
            return value;
        }

    private:
        int value;
    };

    // メソッド実行テストクラス
    class TestSubject : public mhl::UnitTestBase
    {
    public:
        /**
         * コンストラクタ
         */
        TestSubject(std::shared_ptr<mhl::output::console::IConsoleOutputables>
            output_console);

        /**
         * デストラクタ
         */
        ~TestSubject() override;

        void ExecuteUnitTest() override;
    };

} // namespace test_code

#endif  // TEST_TESTSUBJECT_HPP_
