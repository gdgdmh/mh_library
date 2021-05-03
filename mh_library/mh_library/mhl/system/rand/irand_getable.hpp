#ifndef MHL_SYSTEM_RAND_IRAND_GETABLE_HPP_
#define MHL_SYSTEM_RAND_IRAND_GETABLE_HPP_

#include <stdint.h>

namespace mhl {

/**
 * @brief 乱数生成インターフェース
 *
 */
class IRandGetable {
 public:
  /**
   * @brief デストラクタ
   *
   */
  virtual ~IRandGetable() {}

  /**
   * @brief 乱数の種を設定する
   *
   * @param seed 設定する乱数
   */
  virtual void setSeed(uint64_t seed) = 0;

  /**
   * @brief 乱数の種を設定する
   *
   * @param seed 設定する乱数
   */
  virtual void setSeed(uint32_t seed) = 0;

  /**
   * @brief 現在時刻から乱数を設定する
   *
   */
  virtual void setTimeSeed() = 0;

  /**
   * @brief 乱数を取得する
   *
   * @return int32_t 生成された乱数
   */
  virtual int32_t getRandInt32(int32_t min, int32_t max) const = 0;

  /**
   * @brief 乱数を取得する
   *
   * @param min 最小値
   * @param max 最大値
   * @return uint32_t 生成された乱数
   */
  virtual uint32_t getRandUint32(uint32_t min, uint32_t max) const = 0;
};

}  // namespace mhl

#endif  // MHL_SYSTEM_RAND_IRAND_GETABLE_HPP_
