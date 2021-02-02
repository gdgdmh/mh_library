#include "output_console.hpp"

#include <iostream>

/**
 * コンストラクタ
 */
mhl::output::console::OutputConsole::OutputConsole() {}

/**
 * デストラクタ
 */
mhl::output::console::OutputConsole::~OutputConsole() {}

/**
 * 文字列を出力する
 */
void mhl::output::console::OutputConsole::Print(std::string string) {
  std::cout << string;
}

/**
 * 改行付き文字列を出力する
 */
void mhl::output::console::OutputConsole::PrintLine(std::string string) {
  std::cout << string << std::endl;
}
