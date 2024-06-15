#ifndef MHL_TEST_PROGRAM_TEST_VECTOR_TEST_HPP_
#define MHL_TEST_PROGRAM_TEST_VECTOR_TEST_HPP_

#include <stdint.h>

#include <memory>
#include <mhl/test/UnittestBase.hpp>

namespace test_program
{

    class TestVectorData
    {
    public:
        TestVectorData(int32_t a, int32_t b, int32_t c);

        int32_t a_;
        int32_t b_;
        int32_t c_;
    };

    // vector
    class TestVectorTest : public mhl::UnitTestBase
    {
    public:
        /**
         * コンストラクタ
         */
        TestVectorTest(std::shared_ptr<mhl::output::console::IConsoleOutputables>
            output_console);

        /**
         * デストラクタ
         */
        ~TestVectorTest() override;

        void ExecuteUnitTest() override;

        /*
        void SetVector(std::vector<int>& v1,
                       std::vector<int*>& v2);
      
        // vectorのコピー(うまく行かない)
        void CopyVector(std::vector<int*>& v);
      
        void CopyVector2(std::vector<int*>& v);
      
       private:
        std::vector<std::vector<int*> > v_;
        */

        void SetVector(std::vector<TestVectorData> &v1,
                       std::vector<TestVectorData *> &v2);

        // vectorのコピー(うまく行かない)
        void CopyVector(std::vector<TestVectorData *> &v);

        void CopyVector2(std::vector<TestVectorData *> &v);

    private:
        std::vector<std::vector<TestVectorData *>> v_;
    };

} // namespace test_program

#endif  // MHL_TEST_PROGRAM_TEST_VECTOR_TEST_HPP_
