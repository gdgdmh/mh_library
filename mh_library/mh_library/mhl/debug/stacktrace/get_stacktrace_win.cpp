// windows環境
#ifdef _MSC_VER

#include "get_stacktrace_win.hpp"

#include <imagehlp.h>

#pragma comment(lib, "imagehlp.lib")

/**
 * @brief コンストラクタ
 *
 */
mhl::GetStacktraceWin::GetStacktraceWin() {}

/**
 * @brief デストラクタ
 *
 */
mhl::GetStacktraceWin::~GetStacktraceWin() {}

/**
 * @brief スタックトレース情報を取得する
 *
 * @param info スタックトレース情報
 */
void mhl::GetStacktraceWin::GetStacktrace(mhl::StacktraceInfo& info) {
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

  std::vector<mhl::StacktraceInfo::AddressType> addresses;
  std::vector<mhl::StacktraceInfo::SymbolString> symbols;

  symbol->MaxNameLen = kMaxNameSize;
  symbol->SizeOfStruct = sizeof(SYMBOL_INFO);
  addresses.reserve(static_cast<size_t>(trace_size));
  symbols.reserve(static_cast<size_t>(trace_size));

  for (uint16_t i = 0; i < trace_size; ++i) {
    // トレースアドレスからシンボル情報を取得
    SymFromAddr(current_process, (DWORD64)(traces[i]), 0, symbol);
    // アドレスを追加
    addresses.emplace_back(traces[i]);
    // シンボル名を追加
    symbols.emplace_back(std::string(symbol->Name));
  }
  free(symbol);
  symbol = nullptr;

  mhl::StacktraceInfo stacktraceInfo(trace_size, std::move(addresses),
                                     std::move(symbols));
  info = stacktraceInfo;
}

#endif  // _MSC_VER
