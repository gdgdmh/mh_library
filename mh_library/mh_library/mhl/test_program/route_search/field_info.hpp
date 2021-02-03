#ifndef MHL_TEST_PROGRAM_ROUTE_SEARCH_FIELD_INFO_HPP_
#define MHL_TEST_PROGRAM_ROUTE_SEARCH_FIELD_INFO_HPP_

#include <stdint.h>

#include <memory>

#include "field_position.hpp"
#include "field_type.hpp"

namespace test_program {

namespace route_search {

// 1つのフィールドに対する情報
class FieldInfo {
 public:
  /**
   * @brief Construct a new Field Info object
   *
   */
  FieldInfo();

  /**
   * @brief Construct a new Field Info object
   *
   * @param type フィールドのタイプ
   * @param position フィールドの位置
   */
  FieldInfo(const test_program::route_search::FieldType& type,
            const test_program::route_search::FieldPosition& position);

  /**
   * @brief Destroy the Field Info object
   *
   */
  virtual ~FieldInfo();

  /**
   * @brief フィールド情報を設定
   *
   * @param info 設定するフィールド情報
   */
  void Set(const FieldInfo& info);

  /**
   * @brief Set the Type object
   *
   * @param type フィールドのタイプ
   */
  void SetType(const FieldType& type) { type_ = type; }

  /**
   * @brief Set the Position object
   *
   * @param position フィールドの位置
   */
  void SetPosition(const FieldPosition& position) { position_ = position; }

  /**
   * @brief Get the Type object
   *
   * @return const FieldType& フィールドのタイプ
   */
  const FieldType& GetType() const { return type_; }

  /**
   * @brief Get the Position object
   *
   * @return const FieldPosition& フィールドの位置
   */
  const FieldPosition& GetPosition() const { return position_; }

 private:
  FieldType type_;
  FieldPosition position_;
};

}  // namespace route_search

}  // namespace test_program

#endif  // MHL_TEST_PROGRAM_ROUTE_SEARCH_FIELD_TYPE_HPP_
