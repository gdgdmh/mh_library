#include "test_mt_rand_test.hpp"

#include "../string/format/formatter.hpp"
#include "../system/rand/mt_rand.hpp"

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

  mt_.reset(new mhl::MtRand());

  {
    uint64_t seed = 0;
    mt_->setSeed(seed);
    output_console_->PrintLine("seed=0");
    for (int32_t i = 0; i < 10; ++i) {
      uint32_t rnd = mt_->getRandUint32(0, 10);
      output_console_->Print(
          mhl::string::format::Formatter::Format("%u,", rnd));
    }
  }
  output_console_->PrintLine("");
  {
    mt_->setTimeSeed();
    output_console_->PrintLine("time seed");
    for (int32_t i = 0; i < 10; ++i) {
      uint32_t rnd = mt_->getRandUint32(0, 10);
      output_console_->Print(
          mhl::string::format::Formatter::Format("%u,", rnd));
    }
  }
  output_console_->PrintLine("");
}
