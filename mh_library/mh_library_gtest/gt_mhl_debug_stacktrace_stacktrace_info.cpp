
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
  std::vector<mhl::debug::stacktrace::StacktraceInfo::AddressType> addresses;
  std::vector<mhl::debug::stacktrace::StacktraceInfo::SymbolString> symbols;
  std::vector<mhl::debug::stacktrace::StacktraceInfo::FileName> file_names;
  std::vector<mhl::debug::stacktrace::StacktraceInfo::LineNumber> line_numbers;

  mhl::debug::stacktrace::StacktraceInfo s(
      kSize, std::move(addresses), std::move(symbols),
                        std::move(file_names), std::move(line_numbers));
  EXPECT_EQ(s.GetSize(), kSize);
}

/**
 * @brief サイズ1設定テスト
 *
 */
TEST(Debug_Stacktrace_StacktraceInfo, GetSize1) {
  constexpr uint32_t kSize = 1;
  std::vector<mhl::debug::stacktrace::StacktraceInfo::AddressType> addresses;
  std::vector<mhl::debug::stacktrace::StacktraceInfo::SymbolString> symbols;
  std::vector<mhl::debug::stacktrace::StacktraceInfo::FileName> file_names;
  std::vector<mhl::debug::stacktrace::StacktraceInfo::LineNumber> line_numbers;
  mhl::debug::stacktrace::StacktraceInfo s(kSize, std::move(addresses), std::move(symbols),
                        std::move(file_names), std::move(line_numbers));
  EXPECT_EQ(s.GetSize(), kSize);
}

/**
 * @brief サイズ100設定テスト
 *
 */
TEST(Debug_Stacktrace_StacktraceInfo, GetSize100) {
  constexpr uint32_t kSize = 100;
  std::vector<mhl::debug::stacktrace::StacktraceInfo::AddressType> addresses;
  std::vector<mhl::debug::stacktrace::StacktraceInfo::SymbolString> symbols;
  std::vector<mhl::debug::stacktrace::StacktraceInfo::FileName> file_names;
  std::vector<mhl::debug::stacktrace::StacktraceInfo::LineNumber> line_numbers;
  mhl::debug::stacktrace::StacktraceInfo s(kSize, std::move(addresses), std::move(symbols),
                        std::move(file_names), std::move(line_numbers));
  EXPECT_EQ(s.GetSize(), kSize);
}

/**
 * @brief アドレスサイズ0テスト
 *
 */
TEST(Debug_Stacktrace_StacktraceInfo, GetAddressZero) {
  constexpr size_t kSize = 0;
  std::vector<mhl::debug::stacktrace::StacktraceInfo::AddressType> addresses;
  std::vector<mhl::debug::stacktrace::StacktraceInfo::SymbolString> symbols;
  std::vector<mhl::debug::stacktrace::StacktraceInfo::FileName> file_names;
  std::vector<mhl::debug::stacktrace::StacktraceInfo::LineNumber> line_numbers;
  addresses.clear();
  mhl::debug::stacktrace::StacktraceInfo s(kSize, std::move(addresses), std::move(symbols),
                        std::move(file_names), std::move(line_numbers));
  EXPECT_EQ(s.GetAddresses().size(), kSize);
}

/**
 * @brief アドレスサイズ1テスト
 *
 */
TEST(Debug_Stacktrace_StacktraceInfo, GetAddress1) {
  constexpr uint32_t kSize = 1;
  std::vector<mhl::debug::stacktrace::StacktraceInfo::AddressType> addresses;
  std::vector<mhl::debug::stacktrace::StacktraceInfo::SymbolString> symbols;
  std::vector<mhl::debug::stacktrace::StacktraceInfo::FileName> file_names;
  std::vector<mhl::debug::stacktrace::StacktraceInfo::LineNumber> line_numbers;
  addresses.emplace_back(nullptr);
  mhl::debug::stacktrace::StacktraceInfo s(kSize, std::move(addresses), std::move(symbols),
                        std::move(file_names), std::move(line_numbers));
  EXPECT_EQ(s.GetAddresses().size(), kSize);
  EXPECT_EQ(s.GetAddresses().at(0), nullptr);
}

/**
 * @brief アドレスサイズ2テスト
 *
 */
TEST(Debug_Stacktrace_StacktraceInfo, GetAddress2) {
  constexpr uint32_t kSize = 2;
  std::vector<mhl::debug::stacktrace::StacktraceInfo::AddressType> addresses;
  std::vector<mhl::debug::stacktrace::StacktraceInfo::SymbolString> symbols;
  std::vector<mhl::debug::stacktrace::StacktraceInfo::FileName> file_names;
  std::vector<mhl::debug::stacktrace::StacktraceInfo::LineNumber> line_numbers;
  addresses.emplace_back(static_cast<void*>(0));
  addresses.emplace_back(nullptr);
  mhl::debug::stacktrace::StacktraceInfo s(kSize, std::move(addresses), std::move(symbols),
                        std::move(file_names), std::move(line_numbers));
  EXPECT_EQ(s.GetAddresses().size(), kSize);
  EXPECT_EQ(s.GetAddresses().at(0), static_cast<void*>(0));
  EXPECT_EQ(s.GetAddresses().at(1), nullptr);
}

/**
 * @brief シンボルサイズ0テスト
 *
 */
TEST(Debug_Stacktrace_StacktraceInfo, GetSymbolZero) {
  constexpr uint32_t kSize = 0;
  std::vector<mhl::debug::stacktrace::StacktraceInfo::AddressType> addresses;
  std::vector<mhl::debug::stacktrace::StacktraceInfo::SymbolString> symbols;
  std::vector<mhl::debug::stacktrace::StacktraceInfo::FileName> file_names;
  std::vector<mhl::debug::stacktrace::StacktraceInfo::LineNumber> line_numbers;
  mhl::debug::stacktrace::StacktraceInfo s(kSize, std::move(addresses), std::move(symbols),
                        std::move(file_names), std::move(line_numbers));
  EXPECT_EQ(s.GetSymbols().size(), kSize);
}

/**
 * @brief シンボルサイズ1テスト
 *
 */
TEST(Debug_Stacktrace_StacktraceInfo, GetSymbol1) {
  constexpr uint32_t kSize = 1;
  std::vector<mhl::debug::stacktrace::StacktraceInfo::AddressType> addresses;
  std::vector<mhl::debug::stacktrace::StacktraceInfo::SymbolString> symbols;
  std::vector<mhl::debug::stacktrace::StacktraceInfo::FileName> file_names;
  std::vector<mhl::debug::stacktrace::StacktraceInfo::LineNumber> line_numbers;
  symbols.emplace_back("ABC");
  mhl::debug::stacktrace::StacktraceInfo s(kSize, std::move(addresses), std::move(symbols),
                        std::move(file_names), std::move(line_numbers));
  EXPECT_EQ(s.GetSymbols().size(), kSize);
  EXPECT_EQ(s.GetSymbols().at(0), "ABC");
}

/**
 * @brief シンボルサイズ2テスト
 *
 */
TEST(Debug_Stacktrace_StacktraceInfo, GetSymbol2) {
  constexpr uint32_t kSize = 2;
  std::vector<mhl::debug::stacktrace::StacktraceInfo::AddressType> addresses;
  std::vector<mhl::debug::stacktrace::StacktraceInfo::SymbolString> symbols;
  std::vector<mhl::debug::stacktrace::StacktraceInfo::FileName> file_names;
  std::vector<mhl::debug::stacktrace::StacktraceInfo::LineNumber> line_numbers;
  symbols.emplace_back("あいうえお");
  symbols.emplace_back("かきくけこ");
  mhl::debug::stacktrace::StacktraceInfo s(kSize, std::move(addresses), std::move(symbols),
                        std::move(file_names), std::move(line_numbers));
  EXPECT_EQ(s.GetSymbols().size(), kSize);
  EXPECT_EQ(s.GetSymbols().at(0), "あいうえお");
  EXPECT_EQ(s.GetSymbols().at(1), "かきくけこ");
}

TEST(Debug_Stacktrace_StacktraceInfo, GetFileNameZero) {
  constexpr uint32_t kSize = 0;
  std::vector<mhl::debug::stacktrace::StacktraceInfo::AddressType> addresses;
  std::vector<mhl::debug::stacktrace::StacktraceInfo::SymbolString> symbols;
  std::vector<mhl::debug::stacktrace::StacktraceInfo::FileName> file_names;
  std::vector<mhl::debug::stacktrace::StacktraceInfo::LineNumber> line_numbers;
  mhl::debug::stacktrace::StacktraceInfo s(kSize, std::move(addresses), std::move(symbols),
                        std::move(file_names), std::move(line_numbers));
  EXPECT_EQ(s.GetFileNames().size(), kSize);
}

TEST(Debug_Stacktrace_StacktraceInfo, GetFileName1) {
  constexpr uint32_t kSize = 1;
  std::vector<mhl::debug::stacktrace::StacktraceInfo::AddressType> addresses;
  std::vector<mhl::debug::stacktrace::StacktraceInfo::SymbolString> symbols;
  std::vector<mhl::debug::stacktrace::StacktraceInfo::FileName> file_names;
  std::vector<mhl::debug::stacktrace::StacktraceInfo::LineNumber> line_numbers;
  file_names.emplace_back("ABC");
  mhl::debug::stacktrace::StacktraceInfo s(kSize, std::move(addresses), std::move(symbols),
                        std::move(file_names), std::move(line_numbers));
  EXPECT_EQ(s.GetFileNames().size(), kSize);
  EXPECT_EQ(s.GetFileNames().at(0), "ABC");
}

TEST(Debug_Stacktrace_StacktraceInfo, GetFileName2) {
  constexpr uint32_t kSize = 2;
  std::vector<mhl::debug::stacktrace::StacktraceInfo::AddressType> addresses;
  std::vector<mhl::debug::stacktrace::StacktraceInfo::SymbolString> symbols;
  std::vector<mhl::debug::stacktrace::StacktraceInfo::FileName> file_names;
  std::vector<mhl::debug::stacktrace::StacktraceInfo::LineNumber> line_numbers;
  file_names.emplace_back("あいうえお");
  file_names.emplace_back("かきくけこ");
  mhl::debug::stacktrace::StacktraceInfo s(kSize, std::move(addresses), std::move(symbols),
                        std::move(file_names), std::move(line_numbers));
  EXPECT_EQ(s.GetFileNames().size(), kSize);
  EXPECT_EQ(s.GetFileNames().at(0), "あいうえお");
  EXPECT_EQ(s.GetFileNames().at(1), "かきくけこ");
}

TEST(Debug_Stacktrace_StacktraceInfo, GetLineNumberZero) {
  constexpr uint32_t kSize = 0;
  std::vector<mhl::debug::stacktrace::StacktraceInfo::AddressType> addresses;
  std::vector<mhl::debug::stacktrace::StacktraceInfo::SymbolString> symbols;
  std::vector<mhl::debug::stacktrace::StacktraceInfo::FileName> file_names;
  std::vector<mhl::debug::stacktrace::StacktraceInfo::LineNumber> line_numbers;
  mhl::debug::stacktrace::StacktraceInfo s(kSize, std::move(addresses), std::move(symbols),
                        std::move(file_names), std::move(line_numbers));
  EXPECT_EQ(s.GetLineNumbers().size(), kSize);
}

TEST(Debug_Stacktrace_StacktraceInfo, GetLineNumber1) {
  constexpr uint32_t kSize = 1;
  std::vector<mhl::debug::stacktrace::StacktraceInfo::AddressType> addresses;
  std::vector<mhl::debug::stacktrace::StacktraceInfo::SymbolString> symbols;
  std::vector<mhl::debug::stacktrace::StacktraceInfo::FileName> file_names;
  std::vector<mhl::debug::stacktrace::StacktraceInfo::LineNumber> line_numbers;
  line_numbers.emplace_back(3);
  mhl::debug::stacktrace::StacktraceInfo s(kSize, std::move(addresses), std::move(symbols),
                        std::move(file_names), std::move(line_numbers));
  EXPECT_EQ(s.GetLineNumbers().size(), kSize);
  EXPECT_EQ(s.GetLineNumbers().at(0), 3);
}

TEST(Debug_Stacktrace_StacktraceInfo, GetLineNumber2) {
  constexpr uint32_t kSize = 2;
  std::vector<mhl::debug::stacktrace::StacktraceInfo::AddressType> addresses;
  std::vector<mhl::debug::stacktrace::StacktraceInfo::SymbolString> symbols;
  std::vector<mhl::debug::stacktrace::StacktraceInfo::FileName> file_names;
  std::vector<mhl::debug::stacktrace::StacktraceInfo::LineNumber> line_numbers;
  line_numbers.emplace_back(3);
  line_numbers.emplace_back(999);
  mhl::debug::stacktrace::StacktraceInfo s(kSize, std::move(addresses), std::move(symbols),
                        std::move(file_names), std::move(line_numbers));
  EXPECT_EQ(s.GetLineNumbers().size(), kSize);
  EXPECT_EQ(s.GetLineNumbers().at(0), 3);
  EXPECT_EQ(s.GetLineNumbers().at(1), 999);
}

}  // namespace stacktrace_info
}  // namespace stacktrace
}  // namespace debug
}  // namespace mhl
