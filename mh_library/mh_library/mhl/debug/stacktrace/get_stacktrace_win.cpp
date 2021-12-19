// windows環境
#ifdef _MSC_VER

#include "get_stacktrace_win.hpp"

#include <imagehlp.h>

#include <mhl/string/format/formatter.hpp>

#pragma comment(lib, "imagehlp.lib")

/**
 * @brief コンストラクタ
 *
 */
mhl::debug::stacktrace::GetStacktraceWin::GetStacktraceWin() {}

/**
 * @brief デストラクタ
 *
 */
mhl::debug::stacktrace::GetStacktraceWin::~GetStacktraceWin() {}

/**
 * @brief スタックトレース情報を取得する
 *
 * @param info スタックトレース情報
 */
void mhl::debug::stacktrace::GetStacktraceWin::GetStacktrace(
    mhl::debug::stacktrace::StacktraceInfo& info) {
  constexpr size_t kMaxSize = 256;     // 最大トレースサイズ
  void* traces[kMaxSize] = {nullptr};  // トレース配列
  // 現在のプロセスを取得
  HANDLE current_process = GetCurrentProcess();
  // シンボルハンドラ取得
  SymInitialize(current_process, nullptr, TRUE);
  // スタックトレース取得
  uint16_t trace_size = CaptureStackBackTrace(0, kMaxSize, traces, nullptr);

  constexpr size_t kMaxNameSize = 255;
  constexpr size_t kSymbolInfoSize =
      sizeof(SYMBOL_INFO) +
      ((kMaxNameSize + 1) * sizeof(char));  // シンボル情報サイズ
  // メモリ確保
  SYMBOL_INFO* symbol = (SYMBOL_INFO*)calloc(kSymbolInfoSize, 1);
  if (symbol == nullptr) {
    // メモリ確保失敗
    return;
  }
  IMAGEHLP_LINE64* line = (IMAGEHLP_LINE64*)malloc(sizeof(IMAGEHLP_LINE64));
  if (line == nullptr) {
    free(symbol);
    symbol = nullptr;
    return;
  }
  line->SizeOfStruct = sizeof(IMAGEHLP_LINE64);

  std::vector<mhl::debug::stacktrace::StacktraceInfo::AddressType> addresses;
  std::vector<mhl::debug::stacktrace::StacktraceInfo::SymbolString> symbols;
  std::vector<mhl::debug::stacktrace::StacktraceInfo::FileName> file_names;
  std::vector<mhl::debug::stacktrace::StacktraceInfo::LineNumber> line_numbers;

  symbol->MaxNameLen = kMaxNameSize;
  symbol->SizeOfStruct = sizeof(SYMBOL_INFO);
  addresses.reserve(static_cast<size_t>(trace_size));
  symbols.reserve(static_cast<size_t>(trace_size));
  file_names.reserve(static_cast<size_t>(trace_size));
  line_numbers.reserve(static_cast<size_t>(trace_size));

  DWORD displacement = 0;
  for (uint16_t i = 0; i < trace_size; ++i) {
    DWORD64 address = (DWORD64)(traces[i]);
    // トレースアドレスからシンボル情報を取得
    SymFromAddr(current_process, address, 0, symbol);
    // 行の情報などを取得
    const char* file_name = "";
    DWORD line_number = 0;
    if (!SymGetLineFromAddr64(current_process, address, &displacement, line)) {
      // 取得失敗
      file_name = "";
      line_number = 0;
    } else {
      file_name = line->FileName;
      line_number = line->LineNumber;
    }

    // アドレスを追加
    addresses.emplace_back(traces[i]);
    // シンボル名を追加
    symbols.emplace_back(std::string(symbol->Name));
    // ファイル名
    file_names.emplace_back(std::string(file_name));
    // 行番号
    line_numbers.emplace_back(line_number);
  }
  free(line);
  line = nullptr;
  free(symbol);
  symbol = nullptr;

  mhl::debug::stacktrace::StacktraceInfo stacktraceInfo(
      trace_size, std::move(addresses), std::move(symbols),
      std::move(file_names), std::move(line_numbers));
  info = stacktraceInfo;
}

/**
 * @brief スタックトレース情報を文字列で返す
 *
 * @param stacktraceInfo 文字列を受け取る変数
 * @param info スタックトレース情報
 */
void mhl::debug::stacktrace::GetStacktraceWin::ToStringStacktrace(
    std::string& stacktraceInfo,
    const mhl::debug::stacktrace::StacktraceInfo& info) {
  // 一応クリアしておく
  stacktraceInfo = "";
  const auto& symbols = info.GetSymbols();
  const auto& file_name = info.GetFileNames();
  const auto& line_number = info.GetLineNumbers();
  size_t size = symbols.size();
  for (size_t i = 0; i < size; ++i) {
    stacktraceInfo += mhl::string::format::Formatter::Format(
        "%s line:%u(%s)", symbols.at(i).c_str(), line_number.at(i),
        file_name.at(i).c_str());
    /*
    stacktraceInfo += symbols.at(i).c_str();
    stacktraceInfo += " file_name:";
    stacktraceInfo += file_name.at(i).c_str();
    stacktraceInfo += " line:";
    stacktraceInfo += mhl::StdStringFormatter::Format("%d", line_number.at(i));
    */
    if (i != (size - 1)) {
      stacktraceInfo += "\n";
    }
  }
}

#endif  // _MSC_VER
