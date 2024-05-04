#include "basis_point.hpp"

#include "../../rand/irand_getable.hpp"
#include "../../../exception/argument_exception.hpp"

/**
 * @brief コンストラクタ
 *
 */
mhl::system::math::probability::BasisPoint::BasisPoint() {}

/**
 * @brief デストラクタ
 *
 */
mhl::system::math::probability::BasisPoint::~BasisPoint() {}

/**
 * @brief 乱数クラスを設定する
 *
 * @param rand 乱数クラス
 */
void mhl::system::math::probability::BasisPoint::SetRand(
    std::unique_ptr<mhl::IRandGetable>&& rand) {
      rand_ = std::move(rand);
}

/**
 * @brief 配列の中から1つの要素を選ぶ
 *
 * @param target 対象の配列
 * @return int32_t
 */
int32_t mhl::system::math::probability::BasisPoint::Choose(
    const std::vector<int32_t>& target) {
      if (!rand_.get()) {
        throw mhl::exception::ArgumentException("Rand Not Set", 1);
      }

      if (target.size() != 10000) {
        throw mhl::exception::ArgumentException("target Size Not 10000", 2);        
      }

      return 0;
    }
