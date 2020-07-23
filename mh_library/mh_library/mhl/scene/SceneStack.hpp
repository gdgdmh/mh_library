#ifndef MHL_SCENE_SCENESTACK_HPP_
#define MHL_SCENE_SCENESTACK_HPP_

#include <list>
#include <memory>

#include "ISceneable.hpp"

namespace mhl {

/**
 * @brief スタック型シーン管理クラス
 *
 */
class SceneStack {
 public:
  /**
   * @brief Construct a new Scene Stack object
   *
   */
  SceneStack();

  /**
   * @brief Destroy the Scene Stack object
   *
   */
  virtual ~SceneStack();

  /**
   * @brief シーンの更新処理
   *
   */
  void Update();

  /**
   * @brief シーンの描画処理
   *
   */
  void Draw();

  /**
   * @brief シーンをスタックにプッシュする
   *
   * @param scene プッシュするシーン
   */
  void Push(std::shared_ptr<ISceneable> scene);

  /**
   * @brief シーンをスタックからポップする
   *
   */
  void Pop();

  /**
   * @brief シーンをすべてクリアする
   *
   */
  void Clear();

  /**
   * @brief 現在のシーンを指定したシーンを切り替える
   *
   * @param scene 切り替えるシーン
   */
  void Swap(std::shared_ptr<ISceneable> scene);

 private:
  std::list< std::shared_ptr<mhl::ISceneable> > stack_;
};

}  // namespace mhl

#endif  // MHL_SCENE_SCENESTACK_HPP_
