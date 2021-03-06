﻿#ifndef MHL_DEBUG_STACKTRACE_ISTACKTRACEABLE_HPP_
#define MHL_DEBUG_STACKTRACE_ISTACKTRACEABLE_HPP_

#include "stacktrace_info.hpp"

namespace mhl {
/**
 * @brief スタックトレース情報取得インターフェース
 *
 */
class IStacktraceable {
 public:
  virtual ~IStacktraceable() {}
  /**
   * @brief スタックトレース情報を取得する
   *
   * @param info スタックトレース情報
   */
  virtual void GetStacktrace(mhl::StacktraceInfo& info) = 0;

  /**
   * @brief スタックトレース情報を文字列で返す
   *
   * @param stacktraceInfo 文字列を受け取る変数
   * @param info スタックトレース情報
   */
  virtual void ToStringStacktrace(std::string& stacktraceInfo,
                                  const mhl::StacktraceInfo& info) = 0;
};

}  // namespace mhl

#endif  // MHL_DEBUG_STACKTRACE_ISTACKTRACEABLE_HPP_
