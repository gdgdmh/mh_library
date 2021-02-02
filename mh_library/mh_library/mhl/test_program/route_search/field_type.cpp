#include "field_type.hpp"

/**
 * @brief Construct a new Field Type object
 *
 */
test_program::route_search::FieldType::FieldType() : type_(Type::kNone) {}

/**
 * @brief Construct a new Field Type object
 *
 * @param type フィールドのタイプ
 */
test_program::route_search::FieldType::FieldType(const Type& type)
    : type_(type) {}

/**
 * @brief Destroy the Field Type object
 *
 */
test_program::route_search::FieldType::~FieldType() {}

/**
 * @brief タイプを文字列で返す
 *
 * @return std::string 文字列
 */
std::string test_program::route_search::FieldType::ToString() const {
  std::string s = "";
  switch (type_) {
    case FieldType::Type::kNone:
      s = " ";
      break;
    case FieldType::Type::kBlock:
      s = "B";
      break;
    default:
      break;
  }
  return s;
}
