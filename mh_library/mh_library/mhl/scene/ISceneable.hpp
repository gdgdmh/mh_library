#ifndef MHL_SCENE_ISCENEABLE_HPP_
#define MHL_SCENE_ISCENEABLE_HPP_

#include <memory>

namespace mhl {

// シーンインターフェースクラス
class ISceneable {
 public:
  /**
   * @brief Destroy the ISceneable object
   *
   */
  virtual ~ISceneable() {}

  /**
   * @brief シーンの初期化
   *
   */
  virtual void Initialize() {}

  /**
   * @brief シーンの開放処理
   *
   */
  virtual void Release() {}

  /**
   * @brief シーンのロード
   * 時間のかかる処理はここで行う
   */
  virtual void Load() {}

  /**
   * @brief シーンの更新処理
   *
   */
  virtual void Update() {}

  /**
   * @brief シーンの描画処理
   *
   */
  virtual void Draw() {}

  /**
   * @brief シーンがスタックに積まれているときにシーンの更新を行うか
   *
   * @param is_under_update trueなら更新処理を行う
   */
  virtual void SetUnderUpdate(bool is_under_update) {}

  /**
   * @brief シーンがスタックに積まれているときに描画を行うか
   *
   * @param is_under_draw trueなら描画処理を行う
   */
  virtual void SetUnderDraw(bool is_under_draw) {}

  /**
   * @brief このシーンがポップ処理をされる前に呼び出される
   *
   */
  virtual void PopScene() {}

  /**
   * @brief このシーンの上にプッシュ処理をされる前に呼び出される
   * ただし、このシーンが現在のシーンであるときのみ
   * @param next このシーンの上にプッシュされるシーン
   */
  virtual void PushScene(std::shared_ptr<ISceneable> next) {}

  /**
   * @brief シーンのスワップ処理をされる前に呼び出される
   * ただし、このシーンが現在のシーンであるときのみ
   * @param next このシーンの代わりにスワップされるシーン
   */
  virtual void SwapScene(std::shared_ptr<ISceneable> next) {}
};

}  // namespace mhl

#endif  // MHL_SCENE_ISCENEABLE_HPP_
