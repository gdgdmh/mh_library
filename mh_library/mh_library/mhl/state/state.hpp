#ifndef MHL_STATE_STATE_HPP_
#define MHL_STATE_STATE_HPP_

#include <cstdint>

namespace mhl {

/**
 * ステータス管理テンプレートクラス
 * テンプレートに指定するenumはNoneを持っていること
 */
template <typename T>
class State {
 public:
  /**
   * @brief デフォルトコンストラクタ
   *
   */
  State() : state_(T::None), request_state_(T::None) {}

  /**
   * @brief デストラクタ
   *
   */
  virtual ~State() {}

 public:
  /**
   * @brief ステータス変更リクエスト
   * 次にTaskが呼ばれたときに更新される
   *
   * @param state 変更先リクエストするステータス
   */
  void RequestChange(T state) { request_state_ = state; }

  /**
   * @brief ステータスの即時変更リクエスト
   *
   * @param state 即時変更するステータス
   */
  void DoImmediateChangeRequest(T state) {
    state_ = state;
    request_state_ = state;
  }

  /**
   * @brief ステータスの変更リクエストを適用
   *
   * @return true 変更リクエストを適用した
   * @return false 変更リクエストがなかった
   */
  bool ApplyChangeRequest() {
    if (state_ != request_state_) {
      state_ = request_state_;
      return true;
    }
    return false;
  }

  /**
   * @brief ステータスの取得
   *
   * @return T ステータス
   */
  T GetState() const { return state_; }

  /**
   * @brief リクエストステータスの取得
   *
   * @return T リクエストステータス
   */
  T GetRequestState() const { return request_state_; }

 private:
  T state_;          // 現在のステータス
  T request_state_;  // 次に変更するステータス
};

}  // namespace mhl

#endif  // MHL_STATE_STATE_HPP_
