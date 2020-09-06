#include "test_multithread_test.hpp"

#include <algorithm>
#include <iostream>
#include <thread>
#include <vector>

test::MultiThreadTestTask::MultiThreadTestTask(
    std::shared_ptr<mhl::IOutputConsole> output_console)
    : output_console_(output_console), id_(0), value_(0) {}

test::MultiThreadTestTask::~MultiThreadTestTask() {}

void test::MultiThreadTestTask::Task1() {
  Add();
  Print();
}
void test::MultiThreadTestTask::Task2() {
    std::lock_guard<std::mutex> lock(mutex_);
    Add();
    Print();
}


/**
 * コンストラクタ
 */
test::TestMultithreadTest::TestMultithreadTest(
    std::shared_ptr<mhl::IOutputConsole> output_console)
    : UnitTestBase(output_console) {}

/**
 * デストラクタ
 */
test::TestMultithreadTest::~TestMultithreadTest() {}

void test::TestMultithreadTest::ExecuteUnitTest() {
  MultiThreadTestTask mt(output_console_);
  std::vector<std::thread> ths(4);
  const int pattern = 0;
  if (pattern == 0) {
    // 競合起きるケース
    for (auto& th : ths) {
      th = std::thread([&mt] { mt.Task1(); });
    }
  } else if (pattern == 1) {
    // mutexで防ぐケース
    for (auto& th : ths) {
      th = std::thread([&mt] { mt.Task2(); });
    }
  }
  // スレッド終了まで待機
  for (auto& th : ths) {
    th.join();
  }
}
