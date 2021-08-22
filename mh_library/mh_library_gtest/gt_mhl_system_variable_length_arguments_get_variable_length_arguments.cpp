
#include <stdint.h>

#include "a_pch.h"
#include "mhl/system/variable_length_arguments/get_variable_length_arguments.hpp"

namespace mhl {
namespace system {
namespace variable_length_arguments {

/**
 * @brief string変換,引数int10
 *
 */
TEST(GetVariableLengthArguments, ToStringIntValue10) {
  mhl::system::variable_length_arguments::GetVariableLengthArguments g;
  std::string s;
  int32_t v = 10;
  g.ToString(s, "value=%d", v);
  EXPECT_STREQ(s.c_str(), "value=10");
}

/**
 * @brief string変換,引数charFatherInt123456
 *
 */
TEST(GetVariableLengthArguments, ToStringCharFatherInt123456) {
  mhl::system::variable_length_arguments::GetVariableLengthArguments g;
  std::string s;
  constexpr char* v1 = "父";
  int32_t v2 = 123456;
  g.ToString(s, "string=%s value=%d", v1, v2);
  EXPECT_STREQ(s.c_str(), "string=父 value=123456");
}

/**
 * @brief string変換,文字列のみ
 *
 */
TEST(GetVariableLengthArguments, ToStringStringOnly) {
  mhl::system::variable_length_arguments::GetVariableLengthArguments g;
  std::string s;
  g.ToString(s, "stringtest");
  EXPECT_STREQ(s.c_str(), "stringtest");
}

/**
 * @brief string変換,Int64
 *
 */
TEST(GetVariableLengthArguments, ToStringInt64) {
  mhl::system::variable_length_arguments::GetVariableLengthArguments g;
  std::string s;
  int64_t v1 = 9223372036854775807;
  g.ToString(s, "value=%lld", v1);
  EXPECT_STREQ(s.c_str(), "value=9223372036854775807");
}

/**
 * @brief char変換,引数int10
 *
 */
TEST(GetVariableLengthArguments, ToCharIntValue10) {
  mhl::system::variable_length_arguments::GetVariableLengthArguments g;
  constexpr size_t kSize = 100;
  char c[kSize];
  int32_t v = 10;
  g.ToChar(c, kSize, "value=%d", v);
  EXPECT_STREQ(c, "value=10");
}

/**
 * @brief char変換,引数charFatherInt123456
 *
 */
TEST(GetVariableLengthArguments, ToCharCharFatherInt123456) {
  mhl::system::variable_length_arguments::GetVariableLengthArguments g;
  constexpr size_t kSize = 100;
  char c[kSize];
  constexpr char* v1 = "父";
  int32_t v2 = 123456;
  g.ToChar(c, kSize, "string=%s value=%d", v1, v2);
  EXPECT_STREQ(c, "string=父 value=123456");
}

/**
 * @brief char変換,文字列のみ
 *
 */
TEST(GetVariableLengthArguments, ToCharStringOnly) {
  mhl::system::variable_length_arguments::GetVariableLengthArguments g;
  constexpr size_t kSize = 100;
  char c[kSize];
  g.ToChar(c, kSize, "stringtest");
  EXPECT_STREQ(c, "stringtest");
}

/**
 * @brief char変換,Int64
 *
 */
TEST(GetVariableLengthArguments, ToCharInt64) {
  mhl::system::variable_length_arguments::GetVariableLengthArguments g;
  constexpr size_t kSize = 100;
  char c[kSize];
  int64_t v1 = 9223372036854775807;
  g.ToChar(c, kSize, "value=%lld", v1);
  EXPECT_STREQ(c, "value=9223372036854775807");
}

/**
 * @brief char変換,BufferLow
 *
 */
TEST(GetVariableLengthArguments, ToCharBufferLow) {
  mhl::system::variable_length_arguments::GetVariableLengthArguments g;
  constexpr size_t kSize = 8;
  char c[kSize];
  int32_t v1 = 123456;
  g.ToChar(c, kSize, "value=%d", v1);
  EXPECT_STREQ(c, "value=");
}

}  // namespace variable_length_arguments
}  // namespace system
}  // namespace mhl
