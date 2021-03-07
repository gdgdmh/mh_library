#ifndef MHL_DEBUG_STACKTRACE_STACKTRACE_INFO_HPP_
#define MHL_DEBUG_STACKTRACE_STACKTRACE_INFO_HPP_

#include <stdint.h>

#include <string>
#include <vector>

namespace mhl {

/**
 * @brief スタックトレース情報
 *
 */
class StacktraceInfo {
 public:
  // アドレス型
  using AddressType = void*;
  // シンボル文字列
  using SymbolString = std::string;

 public:
  /**
   * @brief デフォルトコンストラクタ
   *
   */
  StacktraceInfo();

  /**
   * @brief コンストラクタ
   *
   * @param size トレース数
   * @param addresses アドレスリスト
   * @param symbols シンボルリスト
   */
  StacktraceInfo(uint32_t size, const std::vector<AddressType>&& addresses,
                 const std::vector<SymbolString>&& symbols);
  /**
   * @brief デストラクタ
   *
   */
  virtual ~StacktraceInfo();

 public:
  /**
   * @brief トレース数取得
   *
   * @return uint32_t トレース数
   */
  uint32_t GetSize() const { return size_; }

  /**
   * @brief アドレスリスト取得
   *
   * @return const std::vector<AddressType>& アドレスリスト
   */
  const std::vector<AddressType>& GetAddresses() const { return addresses_; }

  /**
   * @brief シンボルリスト取得
   *
   * @return const std::vector<SymbolString>& シンボルリスト
   */
  const std::vector<SymbolString>& GetSymbols() const { return symbols_; }

 private:
  uint32_t size_;                       // トレース数
  std::vector<AddressType> addresses_;  // アドレスリスト
  std::vector<SymbolString> symbols_;   // シンボルリスト
};

}  // namespace mhl

#endif  // MHL_DEBUG_STACKTRACE_STACKTRACE_INFO_HPP_
