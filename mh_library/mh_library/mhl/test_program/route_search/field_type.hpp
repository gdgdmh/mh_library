#ifndef MHL_TEST_PROGRAM_ROUTE_SEARCH_FIELD_TYPE_HPP_
#define MHL_TEST_PROGRAM_ROUTE_SEARCH_FIELD_TYPE_HPP_

#include <stdint.h>

#include <memory>
#include <string>

namespace test_program {

namespace route_search {

// フィールド情報
class FieldType {
 public:
  enum class Type : int32_t {
    kNone,   // 何もなし
    kBlock,  // ブロック
  };

 public:
  FieldType() : type_(Type::kNone) {}
  FieldType(const Type& type) : type_(type) {}
  virtual ~FieldType() {}

  void SetType(Type type) { type_ = type; }
  Type GetType() const { return type_; }

  std::string ToString() const {
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

 private:
  Type type_;
};

}  // namespace route_search

}  // namespace test_program

#endif  // MHL_TEST_PROGRAM_ROUTE_SEARCH_FIELD_TYPE_HPP_
