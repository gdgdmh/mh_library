#include "test_route_search_test.hpp"

/**
 * @brief Construct a new test program::TestRouteSearchTest::TestRouteSearchTest
 * object
 *
 * @param output_console コンソール出力クラス
 */
test_program::route_search::TestRouteSearchTest::TestRouteSearchTest(
    std::shared_ptr<mhl::IOutputConsole> output_console)
    : UnitTestBase(output_console) {}

/**
 * @brief Destroy the test program::TestRouteSearchTest::TestRouteSearchTest
 * object
 *
 */
test_program::route_search::TestRouteSearchTest::~TestRouteSearchTest() {}

/**
 * @brief テスト実行
 *
 */
void test_program::route_search::TestRouteSearchTest::ExecuteUnitTest() {
  field_.Initialize(5, 5);
}
