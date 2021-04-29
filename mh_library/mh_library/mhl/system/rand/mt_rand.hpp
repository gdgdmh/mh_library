#ifndef MHL_SYSTEM_RAND_MT_RAND_HPP_
#define MHL_SYSTEM_RAND_MT_RAND_HPP_

#include <stdint.h>

#include <memory>
#include <random>

namespace mhl {

/**
 * @brief メルセンヌ・ツイスタ乱数
 *
 */
class MtRand {
 public:
  /**
   * @brief コンストラクタ
   *
   */
  MtRand();

  /**
   * @brief デストラクタ
   *
   */
  virtual ~MtRand();

  /**
   * @brief 乱数の種を設定する
   *
   * @param seed 設定する乱数
   */
  void setSeed(uint64_t seed);

  /**
   * @brief 乱数の種を設定する
   *
   * @param seed 設定する乱数
   */
  void setSeed(uint32_t seed);

  /**
   * @brief 現在時刻から乱数を設定する
   *
   */
  void setTimeSeed();

  /**
   * @brief 乱数を取得する
   *
   * @param min 最小値
   * @param max 最大値
   * @return uint32_t 生成された乱数
   */
  uint32_t getRandUint32(uint32_t min, uint32_t max) const;

  /**
   * @brief 乱数を取得する
   *
   * @return int32_t 生成された乱数
   */
  int32_t getRandInt32(int32_t min, int32_t max) const;

 private:
  std::shared_ptr<std::mt19937_64> mt_;
};

}  // namespace mhl

#endif  // MHL_SYSTEM_RAND_MT_RAND_HPP_
