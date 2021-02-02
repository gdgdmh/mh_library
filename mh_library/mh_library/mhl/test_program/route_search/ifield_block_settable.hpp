#ifndef MHL_TEST_PROGRAM_ROUTE_SEARCH_IFIELD_BLOCK_CHANGEABLE_HPP_
#define MHL_TEST_PROGRAM_ROUTE_SEARCH_IFIELD_BLOCK_CHANGEABLE_HPP_

#include <stdint.h>

#include <memory>

#include "field.hpp"

namespace test_program {

namespace route_search {

/**
 * @brief フィールドにブロックを変更(設定)するIFクラス
 *
 */
class IFieldBlockSettable {
 public:
  /**
   * @brief Destroy the IFieldBlockChangeable object
   *
   */
  virtual ~IFieldBlockSettable() {}

  /**
   * @brief フィールドのブロック
   *
   * @param field
   */
  virtual void SetBlock(test_program::route_search::FieldType& field) = 0;
};

}  // namespace route_search

}  // namespace test_program

#endif  // MHL_TEST_PROGRAM_ROUTE_SEARCH_IFIELD_BLOCK_CHANGEABLE_HPP_
