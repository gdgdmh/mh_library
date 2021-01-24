#ifndef MHL_TEST_PROGRAM_TEST_ROUTE_SEARCH_TEST_HPP_
#define MHL_TEST_PROGRAM_TEST_ROUTE_SEARCH_TEST_HPP_

#include <stdint.h>

#include <memory>

#include "../test/unittest_base.hpp"

namespace test_program {

// フィールド全体情報
class Field {

};

// フィールド情報
class FieldType {
 public:
  enum class Type : int32_t {
    kNone,  // 何もなし
    kBlock, // ブロック
  };
 public:
  FieldType() : type_(Type::kNone) {}
  virtual ~FieldType() {}

  void SetType(Type type) { type_ = type; }
  Type GetType() const { return type_; }

 private:
  Type type_;
};

// 位置情報
class Position {
 public:
  Position() : x_(0), y_(0) {}
  virtual ~Position() {}

  void SetPosition(int32_t x, int32_t y) { x_ = x; y_ = y; }
  int32_t GetX() const { return x_; }
  int32_t GetY() const { return y_; }
 private:
  int32_t x_;
  int32_t y_;
};

// vector
class TestRouteSearchTest : public mhl::UnitTestBase {
 public:
  /**
   * コンストラクタ
   */
  TestRouteSearchTest(std::shared_ptr<mhl::IOutputConsole> output_console);

  /**
   * デストラクタ
   */
  virtual ~TestRouteSearchTest();

  void ExecuteUnitTest();
};

}  // namespace test_program

#endif  // MHL_TEST_PROGRAM_TEST_ROUTE_SEARCH_TEST_HPP_
