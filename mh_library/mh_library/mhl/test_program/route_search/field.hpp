#ifndef MHL_TEST_PROGRAM_ROUTE_SEARCH_FIELD_HPP_
#define MHL_TEST_PROGRAM_ROUTE_SEARCH_FIELD_HPP_

#include <stdint.h>

#include <memory>
#include <vector>

#include "../../output/console/iconsole_outputable.hpp"
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
  void Print(const std::shared_ptr<mhl::output::console::IConsoleOutputable>&
                 output_console);

  /**
   * @brief フィールド情報の設定
   *
   * @param info 設定するフィールド情報
   * @param x 設定する位置X
   * @param y 設定する位置Y
   */
  void SetFieldInfo(const FieldInfo& info, int32_t x, int32_t y);

  /**
   * @brief フィールド情報の取得()
   *
   * @param x 取得するフィールドの位置X
   * @param y 取得するフィールドの位置Y
   * @return const FieldInfo& フィールド情報
   */
  const FieldInfo& GetFieldInfo(int32_t x, int32_t y) const;

  /**
   * @brief Get the Field Size object
   *
   * @param x
   * @param y
   */
  void GetFieldSize(size_t& x, size_t& y) const;

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
