#include "test_mt_rand_test.hpp"

/**
 * コンストラクタ
 */
test_program::TestMtRandTest::TestMtRandTest(
    std::shared_ptr<mhl::output::console::IConsoleOutputables> output_console)
    : UnitTestBase(output_console) {}

/**
 * デストラクタ
 */
test_program::TestMtRandTest::~TestMtRandTest() {}

void test_program::TestMtRandTest::ExecuteUnitTest() {

  uint64_t seed = 0;
  mt_.setSeed(seed);
  for (int32_t i = 0; i < 10; ++i) {
    seed = mt_.getRandUint32(0, 10);
    int32_t aa = 10;
    aa = 20;
  }

}
