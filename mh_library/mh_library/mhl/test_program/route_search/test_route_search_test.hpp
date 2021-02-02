#ifndef MHL_TEST_PROGRAM_ROUTE_SEARCH_TEST_ROUTE_SEARCH_TEST_HPP_
#define MHL_TEST_PROGRAM_ROUTE_SEARCH_TEST_ROUTE_SEARCH_TEST_HPP_

#include <stdint.h>

#include <memory>

#include "../../test/unittest_base.hpp"

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

// 位置情報
class FieldPosition {
 public:
  FieldPosition() : x_(0), y_(0) {}
  FieldPosition(int32_t x, int32_t y) : x_(x), y_(y) {}
  virtual ~FieldPosition() {}

  void SetPosition(int32_t x, int32_t y) {
    x_ = x;
    y_ = y;
  }
  int32_t GetX() const { return x_; }
  int32_t GetY() const { return y_; }

 private:
  int32_t x_;
  int32_t y_;
};

// 1つのフィールドに対する情報
class FieldInfo {
 public:
  FieldInfo() : type_(), position_() {}
  FieldInfo(const FieldType& type, const FieldPosition& position)
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

// ブロックフィールド追加IF
class IFieldBlockChangeable {
public:
  virtual ~IFieldBlockChangeable() {}
};

// フィールド全体情報
class Field {
 public:
  Field() {}

  /**
   * @brief フィールド生成
   *
   * @param fieldXSize 横方向サイズ
   * @param fieldYSize 縦方向サイズ
   */
  void Initialize(uint32_t fieldXSize, uint32_t fieldYSize) {
    field_.resize(fieldYSize);
    for (std::vector<FieldInfo>& info : field_) {
      info.resize(fieldXSize);
    }
    // 位置初期値入れる
    SetPosition();
    // タイプをすべてkNoneに設定
    SetAllTypeNone();
  }

  void Print(const std::shared_ptr<mhl::IOutputConsole>& output_console) {
    for (const auto& y : field_) {
      std::string line = "";
      for (const auto& x : y) {
        line += x.GetType().ToString();
      }
      output_console->PrintLine(line);
    }
  }

 private:
  void SetPosition() {
    size_t yLength = field_.size();
    for (size_t y = 0; y < yLength; ++y) {
      auto& yInfo = field_[y];
      for (size_t x = 0; x < yInfo.size(); ++x) {
        yInfo[x].SetPosition(test_program::route_search::FieldPosition(
            static_cast<int32_t>(x), static_cast<int32_t>(y)));
      }
    }
  }

  void SetAllTypeNone() {
    size_t yLength = field_.size();
    for (size_t y = 0; y < yLength; ++y) {
      auto& yInfo = field_[y];
      for (size_t x = 0; x < yInfo.size(); ++x) {
        yInfo[x].SetType(
            test_program::route_search::FieldType(test_program::route_search::FieldType::Type::kNone));
      }
    }
  }

 private:
  std::vector<std::vector<FieldInfo> > field_;  // x,yの二次元配列
};

class TestRouteSearchTest : public mhl::UnitTestBase {
 public:
  /**
   * @brief Construct a new Test Route Search Test object
   *
   * @param output_console コンソール出力クラス
   */
  TestRouteSearchTest(std::shared_ptr<mhl::IOutputConsole> output_console);

  /**
   * @brief Destroy the Test Route Search Test object
   *
   */
  virtual ~TestRouteSearchTest();

  /**
   * @brief テスト実行
   *
   */
  void ExecuteUnitTest();

 private:
  Field field_;
};

} // namespace route_search

}  // namespace test_program

#endif  // MHL_TEST_PROGRAM_TEST_ROUTE_SEARCH_TEST_HPP_
