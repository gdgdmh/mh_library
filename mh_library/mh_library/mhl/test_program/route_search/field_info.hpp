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
  FieldInfo() : type_(), position_() {}
  FieldInfo(const test_program::route_search::FieldType& type,
            const test_program::route_search::FieldPosition& position)
      : type_(type), position_(position) {}
  virtual ~FieldInfo() {}

  void SetType(const FieldType& type) { type_ = type; }
  void SetPosition(const FieldPosition& position) { position_ = position; }
  const FieldType& GetType() const { return type_; }
  const FieldPosition& GetPosition() const { return position_; }

 private:
  FieldType type_;
  FieldPosition position_;
};

}  // namespace route_search

}  // namespace test_program

#endif  // MHL_TEST_PROGRAM_ROUTE_SEARCH_FIELD_TYPE_HPP_
