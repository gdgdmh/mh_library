#ifndef MHL_TEST_PROGRAM_ROUTE_SEARCH_IFIELD_BLOCK_SETTABLE_HPP_
#define MHL_TEST_PROGRAM_ROUTE_SEARCH_IFIELD_BLOCK_SETTABLE_HPP_

#include <stdint.h>

#include <memory>

#include "field.hpp"

namespace test_program {

namespace route_search {

/**
 * @brief フィールドにブロックを設定するIFクラス
 *
 */
class IFieldBlockSettable {
 public:
  /**
   * @brief Destroy the IFieldBlockSettable object
   *
   */
  virtual ~IFieldBlockSettable() {}

  /**
   * @brief フィールドのブロックを設定する
   *
   * @param field
   */
  virtual void SetBlock(test_program::route_search::Field& field) = 0;
};

}  // namespace route_search

}  // namespace test_program

#endif  // MHL_TEST_PROGRAM_ROUTE_SEARCH_IFIELD_BLOCK_SETTABLE_HPP_
