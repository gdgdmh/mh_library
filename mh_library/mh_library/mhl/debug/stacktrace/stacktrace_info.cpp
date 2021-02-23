#include "stacktrace_info.hpp"

/**
 * @brief コンストラクタ
 *
 * @param size トレース数
 * @param addresses アドレスリスト
 * @param symbols シンボルリスト
 */
mhl::StacktraceInfo::StacktraceInfo(uint32_t size,
                                    const std::vector<AddressType>&& addresses,
                                    const std::vector<SymbolString>&& symbols) {
  size_ = size;
  for (const auto& address : addresses) {
    addresses_.emplace_back(address);
  }
  for (const auto& symbol : symbols) {
    symbols_.emplace_back(symbol);
  }
}
/**
 * @brief デストラクタ
 *
 */
mhl::StacktraceInfo::~StacktraceInfo() {}
