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
  // ファイル名
  using FileName = std::string;
  // 行番号(元はDWORD型だが32bitと確定できないので64bitで取る)
  using LineNumber = uint64_t;

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
   * @param file_names ファイル名
   * @param line_numbers 行番号
   */
  StacktraceInfo(uint32_t size, const std::vector<AddressType>&& addresses,
                 const std::vector<SymbolString>&& symbols,
                 const std::vector<FileName>&& file_names,
                 const std::vector<LineNumber>&& line_numbers);

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

  /**
   * @brief ファイル名リスト取得
   *
   * @return const std::vector<FileName>& ファイル名リスト
   */
  const std::vector<FileName>& GetFileNames() const { return file_names_; }

  /**
   * @brief 行番号取得
   *
   * @return const std::vector<LineNumber>& 行番号リスト
   */
  const std::vector<LineNumber>& GetLineNumbers() const {
    return line_numbers_;
  }

 private:
  uint32_t size_;                         // トレース数
  std::vector<AddressType> addresses_;    // アドレスリスト
  std::vector<SymbolString> symbols_;     // シンボルリスト
  std::vector<FileName> file_names_;      // ファイル名
  std::vector<LineNumber> line_numbers_;  // 行番号
};

}  // namespace mhl

#endif  // MHL_DEBUG_STACKTRACE_STACKTRACE_INFO_HPP_
