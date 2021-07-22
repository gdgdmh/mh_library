#include "test_route_search_test.hpp"

#include "../../exception/argument_exception.hpp"
#include "../../string/format/formatter.hpp"
#include "set_field_block_always.hpp"

/**
 * @brief Construct a new test program::TestRouteSearchTest::TestRouteSearchTest
 * object
 *
 * @param output_console コンソール出力クラス
 */
test_program::route_search::TestRouteSearchTest::TestRouteSearchTest(
    std::shared_ptr<mhl::output::console::IConsoleOutputables> output_console)
    : UnitTestBase(output_console) {
  block_set_.reset(new test_program::route_search::SetFieldBlockAlways());
}

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
  field_.Initialize(4, 5);
  block_set_->SetBlock(field_);

  size_t x = 0, y = 0;
  field_.GetFieldSize(x, y);

  try {
    mhl::exception::ArgumentException a("test error", 0);
    throw a;
  } catch (mhl::exception::ArgumentException ae) {
    output_console_->PrintLine(mhl::string::format::Formatter::Format(
        "%s:%d", ae.what(), ae.GetResult()));
  }
}
