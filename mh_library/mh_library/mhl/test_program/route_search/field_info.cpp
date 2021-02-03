#include "field_info.hpp"

/**
 * @brief Construct a new Field Info object
 *
 */
test_program::route_search::FieldInfo::FieldInfo() : type_(), position_() {}

/**
 * @brief Construct a new Field Info object
 *
 * @param type フィールドのタイプ
 * @param position フィールドの位置
 */
test_program::route_search::FieldInfo::FieldInfo(
    const test_program::route_search::FieldType& type,
    const test_program::route_search::FieldPosition& position)
    : type_(type), position_(position) {}

/**
 * @brief Destroy the Field Info object
 *
 */
test_program::route_search::FieldInfo::~FieldInfo() {}

/**
 * @brief フィールド情報を設定
 *
 * @param info 設定するフィールド情報
 */
void test_program::route_search::FieldInfo::Set(const FieldInfo& info) {
  type_ = info.type_;
  position_ = info.position_;
}