#include "test_callback_test.hpp"

#include <chrono>
#include <iostream>
#include <thread>

test::CallbackInner::CallbackInner() {}

test::CallbackInner::~CallbackInner() {}

void test::CallbackInner::Execute(CallbackInnerComplete callback) {
  std::this_thread::sleep_for(std::chrono::milliseconds(1000 * 5));
  std::cout << "inner";
  if (callback != nullptr) {
    callback(1, 0);
  }
}

test::CallbackOuter::CallbackOuter() {}
test::CallbackOuter::~CallbackOuter() {}

void test::CallbackOuter::Execute(CallbackOuterComplete callback) {
  test::CallbackInner inner;
  inner.Execute([callback](uint32_t p1, uint32_t p2) {
    if ((p1 == 0) && (p2 == 0)) {
      callback(true);
    } else {
      callback(false);
    }
  });
}

/**
 * コンストラクタ
 */
test::TestCallbackTest::TestCallbackTest(
    std::shared_ptr<mhl::IOutputConsole> output_console)
    : UnitTestBase(output_console) {}

/**
 * デストラクタ
 */
test::TestCallbackTest::~TestCallbackTest() {}

void test::TestCallbackTest::ExecuteUnitTest() {
  test::CallbackOuter outer;
  outer.Execute([](bool result) {
    if (result) {
      std::cout << "success";
    } else {
      std::cout << "failure";
    }
  });

  // TestCpp11Nullptr();
}
