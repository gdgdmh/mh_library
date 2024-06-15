#ifndef MHL_TEST_PROGRAM_ROUTE_SEARCH_TEST_ROUTE_SEARCH_TEST_HPP_
#define MHL_TEST_PROGRAM_ROUTE_SEARCH_TEST_ROUTE_SEARCH_TEST_HPP_

#include <stdint.h>

#include <memory>
#include <mhl/test/UnittestBase.hpp>
#include <mhl/test_program/route_search/Field.hpp>
#include <mhl/test_program/route_search/IFieldBlockSettable.hpp>

namespace test_program
{

    namespace route_search
    {

        class TestRouteSearchTest : public mhl::UnitTestBase
        {
        public:
            /**
             * @brief Construct a new Test Route Search Test object
             *
             * @param output_console コンソール出力クラス
             */
            TestRouteSearchTest(std::shared_ptr<mhl::output::console::IConsoleOutputables>
                output_console);

            /**
             * @brief Destroy the Test Route Search Test object
             *
             */
            ~TestRouteSearchTest() override;

            /**
             * @brief テスト実行
             *
             */
            void ExecuteUnitTest() override;

        private:
            Field field_;
            std::unique_ptr<IFieldBlockSettable> block_set_;
        };

    } // namespace route_search

} // namespace test_program

#endif  // MHL_TEST_PROGRAM_TEST_ROUTE_SEARCH_TEST_HPP_
