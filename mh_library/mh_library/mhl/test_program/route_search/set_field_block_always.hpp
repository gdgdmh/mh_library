#ifndef MHL_TEST_PROGRAM_ROUTE_SEARCH_SET_FIELD_BLOCK_ALWAYS_HPP_
#define MHL_TEST_PROGRAM_ROUTE_SEARCH_SET_FIELD_BLOCK_ALWAYS_HPP_

#include <stdint.h>

#include <memory>

#include "field.hpp"
#include "ifield_block_settable.hpp"

namespace test_program {

namespace route_search {

/**
 * @brief ボンバーマンのいつものと同じブロック配置をする
 *
 */
class SetFieldBlockAlways : public IFieldBlockSettable {
 public:
  /**
   * @brief Set the Field Block Always object
   *
   */
  SetFieldBlockAlways();

  /**
   * @brief Destroy the IFieldBlockChangeable object
   *
   */
  virtual ~SetFieldBlockAlways();

  /**
   * @brief フィールドのブロック
   *
   * @param field
   */
  void SetBlock(test_program::route_search::Field& field) override;
};

}  // namespace route_search

}  // namespace test_program

#endif  // MHL_TEST_PROGRAM_ROUTE_SEARCH_SET_FIELD_BLOCK_ALWAYS_HPP_
