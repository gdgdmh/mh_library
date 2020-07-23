#include "SceneStack.hpp"

/**
 * @brief Construct a new Scene Stack object
 *
 */
mhl::SceneStack::SceneStack() {}

/**
 * @brief Destroy the Scene Stack object
 *
 */
mhl::SceneStack::~SceneStack() {}

/**
 * @brief シーンの更新処理
 *
 */
void mhl::SceneStack::Update() {
  if (stack_.empty()) {
    return;
  }
  // 現在のシーン
  auto it = stack_.begin();
  (*it)->Update();
  ++it;
  // 現在より下のシーン(フラグがあるもののみ更新)
  for (; it != stack_.end(); ++it) {
    if ((*it)->IsUnderUpdate()) {
      (*it)->Update();
    }
  }
}

/**
 * @brief シーンの描画処理
 *
 */
void mhl::SceneStack::Draw() {}

/**
 * @brief シーンをスタックにプッシュする
 *
 * @param scene プッシュするシーン
 */
void mhl::SceneStack::Push(std::shared_ptr<ISceneable> scene) {
  if (!stack_.empty()) {
    // pushされるときのイベントを通知
    auto it = stack_.begin();
    (*it)->EventPush(scene);
  }
  // pushするシーンの初期化
  scene->Initialize();
  // push
  stack_.push_front(scene);
}

/**
 * @brief シーンをスタックからポップする
 *
 */
void mhl::SceneStack::Pop() {
  if (stack_.empty()) {
    return;
  }
  // popイベントを通知
  auto it = stack_.begin();
  (*it)->EventPop();
  // pop
  stack_.pop_front();
}

/**
 * @brief シーンをすべてクリアする
 *
 */
void mhl::SceneStack::Clear() {
  // popイベント
  for (auto it = stack_.begin(); it != stack_.end(); ++it) {
    (*it)->EventPop();
  }
  // clear
  stack_.clear();
}

/**
 * @brief 現在のシーンを指定したシーンを切り替える
 *
 * @param scene 切り替えるシーン
 */
void mhl::SceneStack::Swap(std::shared_ptr<ISceneable> scene) {
  if (stack_.empty()) {
    return;
  }
  // pushされるときのイベントを通知
  auto it = stack_.begin();
  (*it)->EventSwap(scene);
  // pop
  stack_.pop_front();
  // push
  stack_.push_front(scene);
}