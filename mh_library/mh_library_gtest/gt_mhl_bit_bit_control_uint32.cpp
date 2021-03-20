
#include "a_pch.h"
#include "mhl/bit/bit_control_uint32.hpp"

namespace mhl {
namespace bit {
namespace bit_control_uint32 {

/**
 * @brief コンストラクタデフォルト値チェック
 *
 */
TEST(BitControlUint32, ConstructorDefault) {
  mhl::BitControlUint32 b;
  EXPECT_EQ(b.Get(), 0);
}

/**
 * @brief コンストラクタに0を設定する
 *
 */
TEST(BitControlUint32, ConstructorZero) {
  mhl::BitControlUint32 b(0);
  EXPECT_EQ(b.Get(), 0);
}

/**
 * @brief コンストラクタに100を設定する
 *
 */
TEST(BitControlUint32, TestConstructor100) {
  mhl::BitControlUint32 b(100);
  EXPECT_EQ(b.Get(), 100);
}

/**
 * @brief BitControlUint32::Setに0を設定するテスト
 */
TEST(BitControlUint32, SetZero) {
  const uint32_t VALUE = 0;
  mhl::BitControlUint32 b;
  b.Set(VALUE);
  EXPECT_EQ(b.Get(), VALUE);
}

/**
 * @brief BitControlUint32::Setに9999を設定するテスト
 */
TEST(BitControlUint32, Set9999) {
  const uint32_t VALUE = 9999;
  mhl::BitControlUint32 b;
  b.Set(VALUE);
  EXPECT_EQ(b.Get(), VALUE);
}

/**
 * @brief 0ビット目を立てるテスト
 *
 */
TEST(BitControlUint32, BitOn0Bit) {
  const uint32_t VALUE = 0x01;
  mhl::BitControlUint32 b;
  b.BitOn(0);
  EXPECT_EQ(b.Get(), VALUE);
}

/**
 * @brief 1ビット目を立てるテスト
 *
 */
TEST(BitControlUint32, BitOn1Bit) {
  const uint32_t VALUE = 0x02;
  mhl::BitControlUint32 b;
  b.BitOn(1);
  EXPECT_EQ(b.Get(), VALUE);
}

/**
 * @brief 31ビット目を立てるテスト
 *
 */
TEST(BitControlUint32, BitOn31Bit) {
  const uint32_t VALUE = 0x80000000;
  mhl::BitControlUint32 b;
  b.BitOn(31);
  EXPECT_EQ(b.Get(), VALUE);
}

/**
 * @brief 12ビット目を複数回立てるテスト
 *
 */
TEST(BitControlUint32, BitOn12BitMulti) {
  const uint32_t VALUE = 0x1000;
  mhl::BitControlUint32 b;
  b.BitOn(12);
  EXPECT_EQ(b.Get(), VALUE);
  b.BitOn(12);
  EXPECT_EQ(b.Get(), VALUE);
}

/**
 * @brief 0ビット目を立てないテスト
 *
 */
TEST(BitControlUint32, BitOff0Bit) {
  mhl::BitControlUint32 b;
  const uint32_t BIT = 0;
  b.BitOn(BIT);
  EXPECT_EQ(b.Get(), 0x01);
  b.BitOff(BIT);
  EXPECT_EQ(b.Get(), 0);
}

/**
 * @brief 1ビット目を立てないテスト
 *
 */
TEST(BitControlUint32, BitOff1Bit) {
  const uint32_t BIT = 1;
  mhl::BitControlUint32 b;
  b.BitOn(BIT);
  EXPECT_EQ(b.Get(), 0x02);
  b.BitOff(BIT);
  EXPECT_EQ(b.Get(), 0);
}

/**
 * @brief 31ビット目を立てないテスト
 *
 */
TEST(BitControlUint32, BitOff31Bit) {
  const uint32_t BIT = 31;
  mhl::BitControlUint32 b;
  b.BitOn(BIT);
  EXPECT_EQ(b.Get(), 0x80000000);
  b.BitOff(BIT);
  EXPECT_EQ(b.Get(), 0);
}

/**
 * @brief 11ビット目を複数回立てないテスト
 *
 */
TEST(BitControlUint32, BitOff11BitMulti) {
  const uint32_t BIT = 11;
  mhl::BitControlUint32 b;
  b.BitOn(BIT);
  EXPECT_EQ(b.Get(), 0x800);
  b.BitOff(BIT);
  EXPECT_EQ(b.Get(), 0);
  b.BitOff(BIT);
  EXPECT_EQ(b.Get(), 0);
}

/**
 * @brief 0ビット目のtoggleテスト
 *
 */
TEST(BitControlUint32, BitToggle0Bit) {
  const uint32_t BIT = 0;
  mhl::BitControlUint32 b;
  b.BitToggle(BIT);
  EXPECT_EQ(b.Get(), 0x01);
  b.BitToggle(BIT);
  EXPECT_EQ(b.Get(), 0);
}

/**
 * @brief 1ビット目のtoggleテスト
 *
 */
TEST(BitControlUint32, BitToggle1Bit) {
  const uint32_t BIT = 1;
  mhl::BitControlUint32 b;
  b.BitToggle(BIT);
  EXPECT_EQ(b.Get(), 0x02);
  b.BitToggle(BIT);
  EXPECT_EQ(b.Get(), 0);
}

/**
 * @brief 8ビット目のtoggleテスト
 *
 */
TEST(BitControlUint32, BitToggle8Bit) {
  const uint32_t BIT = 8;
  mhl::BitControlUint32 b;
  b.BitToggle(BIT);
  EXPECT_EQ(b.Get(), 0x100);
  b.BitToggle(BIT);
  EXPECT_EQ(b.Get(), 0);
}

/**
 * @brief 31ビット目のtoggleテスト
 *
 */
TEST(BitControlUint32, BitToggle31Bit) {
  const uint32_t BIT = 31;
  mhl::BitControlUint32 b;
  b.BitToggle(BIT);
  EXPECT_EQ(b.Get(), 0x80000000);
  b.BitToggle(BIT);
  EXPECT_EQ(b.Get(), 0);
}

/**
 * @brief 0の値取得テスト
 *
 */
TEST(BitControlUint32, GetZero) {
  const uint32_t VALUE = 0;
  mhl::BitControlUint32 b(VALUE);
  EXPECT_EQ(b.Get(), VALUE);
}

/**
 * @brief 122の値取得テスト
 *
 */
TEST(BitControlUint32, Get122) {
  const uint32_t VALUE = 122;
  mhl::BitControlUint32 b(VALUE);
  EXPECT_EQ(b.Get(), VALUE);
}

/**
 * @brief 12345の値取得テスト
 *
 */
TEST(BitControlUint32, Get12345) {
  const uint32_t VALUE = 12345;
  mhl::BitControlUint32 b(VALUE);
  EXPECT_EQ(b.Get(), VALUE);
}

/**
 * @brief UintMAX値取得テスト
 *
 */
TEST(BitControlUint32, GetUint32Max) {
  const uint32_t VALUE = 0xffffffffui32;
  mhl::BitControlUint32 b(VALUE);
  EXPECT_EQ(b.Get(), VALUE);
}

/**
 * @brief 0ビット目を立てるテスト
 *
 */
TEST(BitControlUint32, GetBitOnZero) {
  const uint32_t BIT = 0;
  mhl::BitControlUint32 b;
  EXPECT_EQ(b.GetBit(0), false);
  b.BitOn(BIT);
  EXPECT_EQ(b.GetBit(0), true);
}

/**
 * @brief 0ビット目を立てないテスト
 *
 */
TEST(BitControlUint32, GetBitOffZero) {
  const uint32_t BIT = 0;
  mhl::BitControlUint32 b;
  b.BitOn(BIT);
  EXPECT_EQ(b.GetBit(BIT), true);
  b.BitOff(BIT);
  EXPECT_EQ(b.GetBit(BIT), false);
}

/**
 * @brief 7ビット目を立てるテスト
 *
 */
TEST(BitControlUint32, GetBitOn7) {
  const uint32_t BIT = 7;
  mhl::BitControlUint32 b;
  EXPECT_EQ(b.GetBit(BIT), false);
  b.BitOn(BIT);
  EXPECT_EQ(b.GetBit(BIT), true);
}

/**
 * @brief 7ビット目を立てないテスト
 *
 */
TEST(BitControlUint32, GetBitOff7) {
  const uint32_t BIT = 7;
  mhl::BitControlUint32 b;
  b.BitOn(BIT);
  EXPECT_EQ(b.GetBit(BIT), true);
  b.BitOff(BIT);
  EXPECT_EQ(b.GetBit(BIT), false);
}

}  // namespace bit_control_uint32
}  // namespace bit
}  // namespace mhl
