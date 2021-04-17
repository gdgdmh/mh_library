#include "stacktrace_info.hpp"

/**
 * @brief デフォルトコンストラクタ
 *
 */
mhl::StacktraceInfo::StacktraceInfo()
    : size_(0), addresses_(), symbols_(), file_names_(), line_numbers_() {}

/**
 * @brief コンストラクタ
 *
 * @param size トレース数
 * @param addresses アドレスリスト
 * @param symbols シンボルリスト
 * @param file_names ファイル名
 * @param line_numbers 行番号
 */
mhl::StacktraceInfo::StacktraceInfo(
    uint32_t size, const std::vector<AddressType>&& addresses,
    const std::vector<SymbolString>&& symbols,
    const std::vector<FileName>&& file_names,
    const std::vector<LineNumber>&& line_numbers) {
  size_ = size;
  for (const auto& address : addresses) {
    addresses_.emplace_back(address);
  }
  for (const auto& symbol : symbols) {
    symbols_.emplace_back(symbol);
  }
  for (const auto& file_name : file_names) {
    file_names_.emplace_back(file_name);
  }
  for (const auto& line_number : line_numbers) {
    line_numbers_.emplace_back(line_number);
  }
}
/**
 * @brief デストラクタ
 *
 */
mhl::StacktraceInfo::~StacktraceInfo() {}
