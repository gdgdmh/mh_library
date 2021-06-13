#include "set_field_block_always.hpp"

//#include "../../debug/assert/mhl_assert.hpp"

/**
 * @brief Set the Field Block Always object
 *
 */
test_program::route_search::SetFieldBlockAlways::SetFieldBlockAlways() {}

/**
 * @brief Destroy the IFieldBlockChangeable object
 *
 */
test_program::route_search::SetFieldBlockAlways::~SetFieldBlockAlways() {}

/**
 * @brief いつもの配置にブロックを設定する
 *
 * @param field
 */
void test_program::route_search::SetFieldBlockAlways::SetBlock(
    test_program::route_search::Field& field) {
  // フィールドの最大長を取得
  size_t sizeX = 0, sizeY = 0;
  field.GetFieldSize(sizeX, sizeY);
  // 広さが足りない
  if (sizeX <= 1) {
    return;
  }
  if (sizeY <= 1) {
    return;
  }
  size_t startX = 0, startY = 0, endX = 0, endY = 0;
  startX = 1;
  startY = 1;
  endX = sizeX - 1;
  endY = sizeY - 1;
 
  for (size_t y = startY; y < endY; ++y) {
    for (size_t x = startX; x < endX; ++x) {
    }
    //field.GetFieldInfo();
  }
}
