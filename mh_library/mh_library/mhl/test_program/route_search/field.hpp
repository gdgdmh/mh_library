#ifndef MHL_TEST_PROGRAM_ROUTE_SEARCH_FIELD_HPP_
#define MHL_TEST_PROGRAM_ROUTE_SEARCH_FIELD_HPP_

#include <stdint.h>

#include <memory>
#include <vector>

#include "../../util/output/ioutput_console.hpp"
#include "field_info.hpp"

namespace test_program {

namespace route_search {

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
        yInfo[x].SetType(test_program::route_search::FieldType(
            test_program::route_search::FieldType::Type::kNone));
      }
    }
  }

 private:
  std::vector<std::vector<FieldInfo> > field_;  // x,yの二次元配列
};

}  // namespace route_search

}  // namespace test_program

#endif  // MHL_TEST_PROGRAM_ROUTE_SEARCH_FIELD_HPP_
