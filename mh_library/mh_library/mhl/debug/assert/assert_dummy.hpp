#ifndef MHL_DEBUG_ASSERT_MHL_ASSERT_DUMMY_HPP_
#define MHL_DEBUG_ASSERT_MHL_ASSERT_DUMMY_HPP_

#include <cassert>

#include "iassert_processor.hpp"

namespace mhl {

namespace debug {

namespace assert {

/**
 * @brief アサーションダミークラス
 * 確認用に呼ばれたどうかの確認に使用する
 *
 */
class AssertDummy : public IAssertProcessor {
 public:
  AssertDummy() : is_called_(false) {}

  /**
   * @brief デストラクタ
   *
   */
  virtual ~AssertDummy() {}

  /**
   * @brief アサーション処理
   *
   */
  virtual void Assert() override { is_called_ = true; }

  /**
   * @brief アサーションが呼ばれたかチェック
   *
   * @return true アサーションが呼ばれた
   * @return false アサーションが呼ばれてない
   */
  virtual bool IsCalled() const { return is_called_; }

  virtual void Reset() { is_called_ = false; }

 private:
  bool is_called_;  // アサーションが呼ばれたか判定するフラグ
};

}  // namespace assert

}  // namespace debug

}  // namespace mhl

#endif  // MHL_DEBUG_ASSERT_MHL_ASSERT_DUMMY_HPP_
