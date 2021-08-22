#ifndef MHL_SYSTEM_FILE_TEXT_TEXTFILE_WRITE_MODE_HPP_
#define MHL_SYSTEM_FILE_TEXT_TEXTFILE_WRITE_MODE_HPP_

#include <stdint.h>

namespace mhl {
namespace system {
namespace file {
namespace text {

enum class Mode : uint8_t {
  kNone,  // なし(基本的に使わない)
  kAdd,  // 追加書き込みで開く(既存のファイル内容は消さない)
  kNewWrite,  // 新規書き込みで開く(既存の内容は消される)
};

}  // namespace text
}  // namespace file
}  // namespace system
}  // namespace mhl

#endif  // MHL_SYSTEM_FILE_TEXT_TEXTFILE_WRITE_MODE_HPP_
