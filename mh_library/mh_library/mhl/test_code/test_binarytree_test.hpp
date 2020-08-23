#ifndef MHL_TEST_CODE_TEST_BINARYTREE_TEST_HPP_
#define MHL_TEST_CODE_TEST_BINARYTREE_TEST_HPP_

#include <memory>

#include "../test/unittest_base.hpp"

namespace test {

// 2分木テスト
class TestBinaryTest : public mhl::UnitTestBase {
 public:
  /**
   * コンストラクタ
   */
  TestBinaryTest(std::shared_ptr<mhl::IOutputConsole> output_console);

  /**
   * デストラクタ
   */
  virtual ~TestBinaryTest();

  void ExecuteUnitTest();
};

}  // namespace test

#endif  // MHL_TEST_CODE_TEST_BINARYTREE_TEST_HPP_
