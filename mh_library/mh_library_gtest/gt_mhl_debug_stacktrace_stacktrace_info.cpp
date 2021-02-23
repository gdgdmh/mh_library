
#include "a_pch.h"
#include "mhl/debug/stacktrace/stacktrace_info.hpp"

namespace mhl {
namespace debug {
namespace stacktrace {
namespace stacktrace_info {

/**
 * @brief サイズ0設定テスト
 *
 */
TEST(Debug_Stacktrace_StacktraceInfo, GetSizeZero) {
  constexpr uint32_t kSize = 0;
  std::vector<mhl::StacktraceInfo::AddressType> addresses;
  std::vector<mhl::StacktraceInfo::SymbolString> symbols;
  mhl::StacktraceInfo s(kSize, std::move(addresses), std::move(symbols));
  EXPECT_EQ(s.GetSize(), kSize);
}

/**
 * @brief サイズ1設定テスト
 *
 */
TEST(Debug_Stacktrace_StacktraceInfo, GetSize1) {
  constexpr uint32_t kSize = 1;
  std::vector<mhl::StacktraceInfo::AddressType> addresses;
  std::vector<mhl::StacktraceInfo::SymbolString> symbols;
  mhl::StacktraceInfo s(kSize, std::move(addresses), std::move(symbols));
  EXPECT_EQ(s.GetSize(), kSize);
}

/**
 * @brief サイズ100設定テスト
 *
 */
TEST(Debug_Stacktrace_StacktraceInfo, GetSize100) {
  constexpr uint32_t kSize = 100;
  std::vector<mhl::StacktraceInfo::AddressType> addresses;
  std::vector<mhl::StacktraceInfo::SymbolString> symbols;
  mhl::StacktraceInfo s(kSize, std::move(addresses), std::move(symbols));
  EXPECT_EQ(s.GetSize(), kSize);
}

// 未作成
TEST(Debug_Stacktrace_StacktraceInfo, GetAddressZero) {
  constexpr uint32_t kSize = 1;
  std::vector<mhl::StacktraceInfo::AddressType> addresses;
  std::vector<mhl::StacktraceInfo::SymbolString> symbols;
  mhl::StacktraceInfo s(kSize, std::move(addresses), std::move(symbols));
  EXPECT_EQ(s.GetSize(), kSize);
}

// 未作成
TEST(Debug_Stacktrace_StacktraceInfo, GetAddress1) {
  constexpr uint32_t kSize = 1;
  std::vector<mhl::StacktraceInfo::AddressType> addresses;
  std::vector<mhl::StacktraceInfo::SymbolString> symbols;
  mhl::StacktraceInfo s(kSize, std::move(addresses), std::move(symbols));
  EXPECT_EQ(s.GetSize(), kSize);
}

// 未作成
TEST(Debug_Stacktrace_StacktraceInfo, GetAddress2) {
  constexpr uint32_t kSize = 1;
  std::vector<mhl::StacktraceInfo::AddressType> addresses;
  std::vector<mhl::StacktraceInfo::SymbolString> symbols;
  mhl::StacktraceInfo s(kSize, std::move(addresses), std::move(symbols));
  EXPECT_EQ(s.GetSize(), kSize);
}

// 未作成
TEST(Debug_Stacktrace_StacktraceInfo, GetSymbolZero) {
  constexpr uint32_t kSize = 1;
  std::vector<mhl::StacktraceInfo::AddressType> addresses;
  std::vector<mhl::StacktraceInfo::SymbolString> symbols;
  mhl::StacktraceInfo s(kSize, std::move(addresses), std::move(symbols));
  EXPECT_EQ(s.GetSize(), kSize);
}

// 未作成
TEST(Debug_Stacktrace_StacktraceInfo, GetSymbol1) {
  constexpr uint32_t kSize = 1;
  std::vector<mhl::StacktraceInfo::AddressType> addresses;
  std::vector<mhl::StacktraceInfo::SymbolString> symbols;
  mhl::StacktraceInfo s(kSize, std::move(addresses), std::move(symbols));
  EXPECT_EQ(s.GetSize(), kSize);
}

// 未作成
TEST(Debug_Stacktrace_StacktraceInfo, GetSymbol2) {
  constexpr uint32_t kSize = 1;
  std::vector<mhl::StacktraceInfo::AddressType> addresses;
  std::vector<mhl::StacktraceInfo::SymbolString> symbols;
  mhl::StacktraceInfo s(kSize, std::move(addresses), std::move(symbols));
  EXPECT_EQ(s.GetSize(), kSize);
}

}  // namespace stacktrace_info
}  // namespace stacktrace
}  // namespace debug
}  // namespace mhl
