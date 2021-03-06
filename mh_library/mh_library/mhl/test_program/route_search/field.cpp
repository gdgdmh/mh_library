﻿#include "field.hpp"

/**
 * @brief Construct a new Field object
 *
 */
test_program::route_search::Field::Field() {}

/**
 * @brief フィールド生成
 *
 * @param fieldXSize 横方向サイズ
 * @param fieldYSize 縦方向サイズ
 */
void test_program::route_search::Field::Initialize(uint32_t fieldXSize,
                                                   uint32_t fieldYSize) {
  field_.resize(fieldYSize);
  for (std::vector<FieldInfo>& info : field_) {
    info.resize(fieldXSize);
  }
  // 位置初期値入れる
  SetPosition();
  // タイプをすべてkNoneに設定
  SetAllTypeNone();
}

/**
 * @brief フィールドの状態を出力
 *
 * @param output_console
 */
void test_program::route_search::Field::Print(
    const std::shared_ptr<mhl::output::console::IOutputConsole>&
        output_console) {
  for (const auto& y : field_) {
    std::string line = "";
    for (const auto& x : y) {
      line += x.GetType().ToString();
    }
    output_console->PrintLine(line);
  }
}

/**
 * @brief フィールド情報の設定
 *
 * @param info 設定するフィールド情報
 * @param x 設定する位置X
 * @param y 設定する位置Y
 */
void test_program::route_search::Field::SetFieldInfo(const FieldInfo& info,
                                                     int32_t x, int32_t y) {
  field_.at(y).at(x).Set(info);
}

/**
 * @brief フィールド情報の取得()
 *
 * @param x 取得するフィールドの位置X
 * @param y 取得するフィールドの位置Y
 * @return const FieldInfo& フィールド情報
 */
const test_program::route_search::FieldInfo&
test_program::route_search::Field::GetFieldInfo(int32_t x, int32_t y) const {
  return field_.at(y).at(x);
}

/**
 * @brief Get the Field Size object
 *
 * @param x
 * @param y
 */
void test_program::route_search::Field::GetFieldSize(size_t& x,
                                                     size_t& y) const {
  y = field_.size();
  x = field_.at(y - 1).size();
}

/**
 * @brief 位置を設定
 *
 */
void test_program::route_search::Field::SetPosition() {
  size_t yLength = field_.size();
  for (size_t y = 0; y < yLength; ++y) {
    auto& yInfo = field_[y];
    for (size_t x = 0; x < yInfo.size(); ++x) {
      yInfo[x].SetPosition(test_program::route_search::FieldPosition(
          static_cast<int32_t>(x), static_cast<int32_t>(y)));
    }
  }
}

/**
 * @brief 全てのフィールドのタイプをNoneに設定
 *
 */
void test_program::route_search::Field::SetAllTypeNone() {
  size_t yLength = field_.size();
  for (size_t y = 0; y < yLength; ++y) {
    auto& yInfo = field_[y];
    for (size_t x = 0; x < yInfo.size(); ++x) {
      yInfo[x].SetType(test_program::route_search::FieldType(
          test_program::route_search::FieldType::Type::kNone));
    }
  }
}
