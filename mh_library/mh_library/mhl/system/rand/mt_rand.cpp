#include "mt_rand.hpp"

/**
 * @brief コンストラクタ
 *
 */
mhl::MtRand::MtRand() : mt_(new std::mt19937_64(0)) {}

/**
 * @brief デストラクタ
 *
 */
mhl::MtRand::~MtRand() {}

/**
 * @brief 乱数の種を設定する
 *
 * @param seed 設定する乱数
 */
void mhl::MtRand::setSeed(uint64_t seed) { mt_->seed(seed); }

/**
 * @brief 乱数の種を設定する
 *
 * @param seed 設定する乱数
 */
void mhl::MtRand::setSeed(uint32_t seed) { mt_->seed(seed); }

/**
 * @brief 現在時刻から乱数を設定する
 *
 */
void mhl::MtRand::setTimeSeed() {
  std::random_device seed;
  mt_->seed(seed());
}

/**
 * @brief 乱数を取得する
 *
 * @return int32_t 生成された乱数
 */
int32_t mhl::MtRand::getRandInt32(int32_t min, int32_t max) const {
  // minからmaxまでの乱数を等間隔生成
  std::uniform_int_distribution<int64_t> get_rand_int(min, max);
  return static_cast<int32_t>(get_rand_int(*mt_.get()));
}

/**
 * @brief 乱数を取得する
 *
 * @param min 最小値
 * @param max 最大値
 * @return uint32_t 生成された乱数
 */
uint32_t mhl::MtRand::getRandUint32(uint32_t min, uint32_t max) const {
  // minからmaxまでの乱数を等間隔生成
  std::uniform_int_distribution<uint64_t> get_rand_int(min, max);
  return static_cast<uint32_t>(get_rand_int(*mt_.get()));
}
