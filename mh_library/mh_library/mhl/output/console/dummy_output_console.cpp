#include "dummy_output_console.hpp"

#include <iostream>

/**
 * コンストラクタ
 */
mhl::output::console::DummyOutputConsole::DummyOutputConsole() {}

/**
 * デストラクタ
 */
mhl::output::console::DummyOutputConsole::~DummyOutputConsole() {}

/**
 * 文字列を出力する(ダミーなので出力はしない)
 */
void mhl::output::console::DummyOutputConsole::Print(std::string string) {}

/**
 * 改行付き文字列を出力する(ダミーなので出力はしない)
 */
void mhl::output::console::DummyOutputConsole::PrintLine(std::string string) {}
