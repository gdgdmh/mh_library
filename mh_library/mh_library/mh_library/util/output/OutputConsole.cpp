#include "OutputConsole.hpp"

#include <iostream>

/**
 * コンストラクタ
 */
mh_library::OutputConsole::OutputConsole() {
}

/**
 * デストラクタ
 */
mh_library::OutputConsole::~OutputConsole() {
}

/**
 * 文字列を出力する
 */
void mh_library::OutputConsole::Print(std::string string) {
	std::cout << string;
}

/**
 * 改行付き文字列を出力する
 */
void mh_library::OutputConsole::PrintLine(std::string string) {
	std::cout << string << std::endl;
}
