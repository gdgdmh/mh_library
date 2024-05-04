#ifndef MHL_SYSTEM_MATH_PROBABILITY_BASISPOINT_HPP_
#define MHL_SYSTEM_MATH_PROBABILITY_BASISPOINT_HPP_

#include <stdint.h>

#include <memory>
#include <vector>

namespace mhl {
class IRandGetable;
}  // namespace mhl

namespace mhl {
namespace system {
namespace math {
namespace probability {

/**
 * @brief 万分率確率計算クラス
 *
 */
class BasisPoint {
 public:
  /**
   * @brief コンストラクタ
   *
   */
  BasisPoint();

  /**
   * @brief デストラクタ
   *
   */
  virtual ~BasisPoint();

  /**
   * @brief 乱数クラスを設定する
   *
   * @param rand 乱数クラス
   */
  void SetRand(std::unique_ptr<mhl::IRandGetable>&& rand);

  /**
   * @brief 配列の中から1つの要素を選ぶ
   *
   * @param target 対象の配列
   * @return int32_t
   */
  virtual int32_t Choose(const std::vector<int32_t>& target);

 private:
  std::unique_ptr<mhl::IRandGetable> rand_;  // 乱数生成
};
}  // namespace probability
}  // namespace math
}  // namespace system
}  // namespace mhl

#endif  // MHL_SYSTEM_MATH_PROBABILITY_BASISPOINT_HPP_
