#ifndef MHL_TEST_PROGRAM_ROUTE_SEARCH_FIELD_POSITION_HPP_
#define MHL_TEST_PROGRAM_ROUTE_SEARCH_FIELD_POSITION_HPP_

#include <stdint.h>

#include <memory>

namespace test_program {

namespace route_search {

/**
 * @brief フィールド位置情報
 *
 */
class FieldPosition {
 public:
  /**
   * @brief Construct a new Field Position object
   *
   */
  FieldPosition();

  /**
   * @brief Construct a new Field Position object
   *
   * @param x 位置X
   * @param y 位置Y
   */
  FieldPosition(int32_t x, int32_t y);

  /**
   * @brief Destroy the Field Position object
   *
   */
  virtual ~FieldPosition();

  /**
   * @brief Set the Position object
   *
   * @param x 位置X
   * @param y 位置Y
   */
  void SetPosition(int32_t x, int32_t y) {
    x_ = x;
    y_ = y;
  }

  /**
   * @brief 位置Xの取得
   *
   * @return int32_t 位置
   */
  int32_t GetX() const { return x_; }

  /**
   * @brief 位置Yの取得
   *
   * @return int32_t 位置
   */
  int32_t GetY() const { return y_; }

 private:
  int32_t x_;  // 位置X
  int32_t y_;  // 位置Y
};

}  // namespace route_search

}  // namespace test_program

#endif  // MHL_TEST_PROGRAM_ROUTE_SEARCH_FIELD_POSITION_HPP_
