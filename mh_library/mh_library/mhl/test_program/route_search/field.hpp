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
  /**
   * @brief Construct a new Field object
   *
   */
  Field();

  /**
   * @brief フィールド生成
   *
   * @param fieldXSize 横方向サイズ
   * @param fieldYSize 縦方向サイズ
   */
  void Initialize(uint32_t fieldXSize, uint32_t fieldYSize);

  /**
   * @brief フィールドの状態を出力
   *
   * @param output_console
   */
  void Print(const std::shared_ptr<mhl::IOutputConsole>& output_console);

 private:
  /**
   * @brief 位置を設定
   *
   */
  void SetPosition();

  /**
   * @brief 全てのフィールドのタイプをNoneに設定
   *
   */
  void SetAllTypeNone();

 private:
  std::vector<std::vector<FieldInfo> > field_;  // x,yの二次元配列
};

}  // namespace route_search

}  // namespace test_program

#endif  // MHL_TEST_PROGRAM_ROUTE_SEARCH_FIELD_HPP_
