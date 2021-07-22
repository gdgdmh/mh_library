#ifndef MHL_DEBUG_DEBUG_HPP_
#define MHL_DEBUG_DEBUG_HPP_

namespace mhl {

namespace debug {

/**
 * @brief デバッグ機能
 *
 */
class Debug {
 public:
  /**
   * @brief コンストラクタ
   *
   */
  Debug();

  /**
   * @brief デストラクタ
   *
   */
  virtual ~Debug();

  /**
   * @brief デバッグ出力(コンソール)
   *
   * @param format
   * @param ...
   */
  static void Log(const char* format, ...);
};

}  // namespace debug

}  // namespace mhl

#endif  // MHL_DEBUG_STACKTRACE_STACKTRACE_INFO_HPP_
