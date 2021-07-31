#ifndef MHL_DEBUG_SERVICE_LOCATOR_LOG_DEBUG_LOG_HPP_
#define MHL_DEBUG_SERVICE_LOCATOR_LOG_DEBUG_LOG_HPP_

namespace mhl {
namespace debug {
namespace service_locator {
namespace log {

/**
 * @brief ログ機能
 *
 */
class DebugLog {
 public:
  /**
   * @brief コンストラクタ
   *
   */
  DebugLog();

  /**
   * @brief デストラクタ
   *
   */
  virtual ~DebugLog();

  /**
   * @brief ログ出力
   *
   * @param format フォーマット文字列
   * @param ... 可変引数パラメータ
   */
  void Log(const char* format, ...);
};
}  // namespace log
}  // namespace service_locator
}  // namespace debug
}  // namespace mhl

#endif  // MHL_DEBUG_SERVICE_LOCATOR_LOG_DEBUG_LOG_HPP_
