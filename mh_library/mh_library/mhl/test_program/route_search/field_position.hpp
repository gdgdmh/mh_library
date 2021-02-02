#ifndef MHL_TEST_PROGRAM_ROUTE_SEARCH_FIELD_POSITION_HPP_
#define MHL_TEST_PROGRAM_ROUTE_SEARCH_FIELD_POSITION_HPP_

#include <stdint.h>

#include <memory>

namespace test_program {

namespace route_search {

// 位置情報
class FieldPosition {
 public:
  FieldPosition() : x_(0), y_(0) {}
  FieldPosition(int32_t x, int32_t y) : x_(x), y_(y) {}
  virtual ~FieldPosition() {}

  void SetPosition(int32_t x, int32_t y) {
    x_ = x;
    y_ = y;
  }
  int32_t GetX() const { return x_; }
  int32_t GetY() const { return y_; }

 private:
  int32_t x_;
  int32_t y_;
};

}  // namespace route_search

}  // namespace test_program

#endif  // MHL_TEST_PROGRAM_ROUTE_SEARCH_FIELD_POSITION_HPP_
