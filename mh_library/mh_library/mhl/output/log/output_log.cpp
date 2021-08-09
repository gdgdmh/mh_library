#include "output_log.hpp"

#include <iostream>

/**
 * @brief コンストラクタ
 *
 * @param file_name ファイル名
 */
mhl::output::log::OutputLog::OutputLog(const std::string file_name)
    : file_path_(""), out_stream_(), is_open_(false), open_error_(false) {}

/**
 * デストラクタ
 */
mhl::output::log::OutputLog::~OutputLog() {}

/**
 * 文字列を出力する
 */
void mhl::output::log::OutputLog::Print(std::string string) {
  // std::cout << string;
}

/**
 * 改行付き文字列を出力する
 */
void mhl::output::log::OutputLog::PrintLine(std::string string) {
  // std::cout << string << std::endl;
}
