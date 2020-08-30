﻿#include "test_binarytree_test.hpp"

#include <algorithm>
#include <vector>

/**
 * コンストラクタ
 */
test::TestBinaryTest::TestBinaryTest(
    std::shared_ptr<mhl::IOutputConsole> output_console)
    : UnitTestBase(output_console) {}

/**
 * デストラクタ
 */
test::TestBinaryTest::~TestBinaryTest() {}

void test::TestBinaryTest::ExecuteUnitTest() {
  TestIntTest();
  TestBinaryClassTest();
}

void test::TestBinaryTest::TestIntTest() {
  std::vector<int> v;
  for (int i = 0; i < 10; ++i) {
    v.push_back(i);
  }
  {
    // ソート済み配列が必須
    std::sort(v.begin(), v.end());
    // 5を探す
    {
      {
        std::vector<int>::iterator lower_it =
            std::lower_bound(v.begin(), v.end(), 5);
        std::string s =
            mhl::StdStringFormatter::Format("low 5 find -> %d", (*lower_it));
        output_console_->PrintLine(s);
      }
    }
  }
  // 無い数字を探す(endのイテレータが返ってくる)
  {
    std::vector<int>::iterator it = std::lower_bound(v.begin(), v.end(), 11);
    if (it != v.end()) {
      std::string s2 = mhl::StdStringFormatter::Format("low none -> %d", (*it));
      output_console_->PrintLine(s2);
    }
  }
  // 7を探す
  {
    std::vector<int>::iterator it = std::lower_bound(v.begin(), v.end(), 7);
    if (it != v.end()) {
      std::string s =
          mhl::StdStringFormatter::Format("low 7 find -> %d", (*it));
      output_console_->PrintLine(s);
    }
  }
  // 9を探す
  {
    std::vector<int>::iterator it = std::lower_bound(v.begin(), v.end(), 9);
    if (it != v.end()) {
      std::string s =
          mhl::StdStringFormatter::Format("low 9 find -> %d", (*it));
      output_console_->PrintLine(s);
    }
  }

  // upper_bound
  {
    // 7
    {
      std::vector<int>::iterator it = std::upper_bound(v.begin(), v.end(), 7);
      if (it != v.end()) {
        std::string s =
            mhl::StdStringFormatter::Format("up 7 find -> %d", (*it));
        output_console_->PrintLine(s);
      }
    }
    // 0
    {
      std::vector<int>::iterator it = std::upper_bound(v.begin(), v.end(), 0);
      if (it != v.end()) {
        std::string s =
            mhl::StdStringFormatter::Format("up 0 find -> %d", (*it));
        output_console_->PrintLine(s);
      }
    }
  }
}

void test::TestBinaryTest::TestBinaryClassTest() {
  std::vector<TestBinaryClass> v;
  for (int i = 0; i < 10000; ++i) {
    TestBinaryClass t(i, mhl::StdStringFormatter::Format("%d", i));
    v.push_back(t);
  }
  // lower_bound
  {
    TestBinaryClass t(500, "AAA");
    std::vector<TestBinaryClass>::iterator it = std::lower_bound(v.begin(), v.end(), t,
        [](const TestBinaryClass& a, const TestBinaryClass& b) {
          return a.GetId() < b.GetId();
      });
    if (it != v.end()) {
      std::string s = mhl::StdStringFormatter::Format("lower 500 find -> id %d val %s", (*it).GetId(), (*it).GetValue().c_str());
      output_console_->PrintLine(s);
    }
  }
}
