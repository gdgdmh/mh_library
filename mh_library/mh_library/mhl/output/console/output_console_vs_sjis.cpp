#include "output_console_vs_sjis.hpp"

#ifdef _MSC_VER
#include <windows.h>
#endif  // _MSC_VER

/**
 * コンストラクタ
 */
mhl::output::console::OutputConsoleVsSjis::OutputConsoleVsSjis() {}

/**
 * デストラクタ
 */
mhl::output::console::OutputConsoleVsSjis::~OutputConsoleVsSjis() {}

/**
 * 文字列を出力する
 */
void mhl::output::console::OutputConsoleVsSjis::Print(std::string string) {
#ifdef _MSC_VER
  OutputDebugStringA(string.c_str());
#endif  // _MSC_VER
}

/**
 * 改行付き文字列を出力する
 */
void mhl::output::console::OutputConsoleVsSjis::PrintLine(std::string string) {
#ifdef _MSC_VER
  OutputDebugStringA(string.c_str());
#endif  // _MSC_VER
}
