#ifndef MHL_TEST_PROGRAM_ROUTE_SEARCH_TEST_ROUTE_SEARCH_TEST_HPP_
#define MHL_TEST_PROGRAM_ROUTE_SEARCH_TEST_ROUTE_SEARCH_TEST_HPP_

#include <stdint.h>

#include <memory>

#include "../../test/unittest_base.hpp"
#include "field.hpp"

namespace test_program {

namespace route_search {

class TestRouteSearchTest : public mhl::UnitTestBase {
 public:
  /**
   * @brief Construct a new Test Route Search Test object
   *
   * @param output_console コンソール出力クラス
   */
  TestRouteSearchTest(
      std::shared_ptr<mhl::output::console::IOutputConsole> output_console);

  /**
   * @brief Destroy the Test Route Search Test object
   *
   */
  virtual ~TestRouteSearchTest();

  /**
   * @brief テスト実行
   *
   */
  void ExecuteUnitTest();

 private:
  Field field_;
};

}  // namespace route_search

}  // namespace test_program

#endif  // MHL_TEST_PROGRAM_TEST_ROUTE_SEARCH_TEST_HPP_
