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
  /**
   * @brief Construct a new Field Type object
   *
   */
  FieldType();

  /**
   * @brief Construct a new Field Type object
   *
   * @param type フィールドのタイプ
   */
  FieldType(const Type& type);

  /**
   * @brief Destroy the Field Type object
   *
   */
  virtual ~FieldType();

  /**
   * @brief Set the Type object
   *
   * @param type タイプ
   */
  void SetType(Type type) { type_ = type; }

  /**
   * @brief Get the Type object
   *
   * @return Type タイプ
   */
  Type GetType() const { return type_; }

  /**
   * @brief タイプを文字列で返す
   *
   * @return std::string 文字列
   */
  std::string ToString() const;

 private:
  Type type_;  // タイプ
};

}  // namespace route_search

}  // namespace test_program

#endif  // MHL_TEST_PROGRAM_ROUTE_SEARCH_FIELD_TYPE_HPP_
