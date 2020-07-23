﻿#include "TestSceneStack.hpp"

#include "../scene/SceneStack.hpp"

test::TestScene::TestScene()
    : under_update_(false),
      under_draw_(false),
      call_initialize_(0),
      call_release_(0),
      call_load_(0),
      call_update_(0),
      call_draw_(0),
      call_event_pop_(0),
      call_event_push_(0),
      call_event_swap_(0) {}

test::TestScene::~TestScene() {}

/**
 * @brief シーンの初期化
 *
 */
void test::TestScene::Initialize() { ++call_initialize_; }

/**
 * @brief シーンの開放処理
 *
 */
void test::TestScene::Release() { ++call_release_; }

/**
 * @brief シーンのロード
 * 時間のかかる処理はここで行う
 */
void test::TestScene::Load() { ++call_load_; }

/**
 * @brief シーンの更新処理
 *
 */
void test::TestScene::Update() { ++call_update_; }

/**
 * @brief シーンの描画処理
 *
 */
void test::TestScene::Draw() { ++call_draw_; }

/**
 * @brief シーンがトップより下に積まれているときにシーンの更新を行うか設定する
 *
 * @param under_update trueなら更新処理を行う
 */
void test::TestScene::SetUnderUpdate(bool under_update) {
  under_update_ = under_update;
}

/**
 * @brief シーンがトップより下に積まれているときにシーンの更新を行うか
 *
 * @return true シーンの更新を行う
 * @return false シーンの更新をしない
 */
bool test::TestScene::IsUnderUpdate() { return under_update_; }

/**
 * @brief シーンがトップより下に積まれているときにシーンの描画を行うか設定する
 *
 * @param under_draw trueなら描画処理を行う
 */
void test::TestScene::SetUnderDraw(bool under_draw) {
  under_draw_ = under_draw;
}

/**
 * @brief シーンがトップより下に積まれているときにシーンの描画を行うか
 *
 * @return true シーンの描画を行う
 * @return false シーンの描画をしない
 */
bool test::TestScene::IsUnderDraw() { return under_draw_; }

/**
 * @brief このシーンがポップ処理をされる前に呼び出される
 *
 */
void test::TestScene::EventPop() { ++call_event_swap_; }

/**
 * @brief このシーンの上にプッシュ処理をされる前に呼び出される
 * ただし、このシーンが現在のシーンであるときのみ
 * @param next このシーンの上にプッシュされるシーン
 */
void test::TestScene::EventPush(std::shared_ptr<ISceneable> next) {
  ++call_event_push_;
}

/**
 * @brief シーンのスワップ処理をされる前に呼び出される
 * ただし、このシーンが現在のシーンであるときのみ
 * @param next このシーンの代わりにスワップされるシーン
 */
void test::TestScene::EventSwap(std::shared_ptr<ISceneable> next) {
  ++call_event_swap_;
}

/**
 * @brief Initializeコールの取得
 *
 * @return int コールされた回数
 */
int test::TestScene::GetInitializeCall() { return call_initialize_; }

/**
 * @brief Releaseコールの取得
 *
 * @return int コールされた回数
 */
int test::TestScene::GetReleaseCall() { return call_release_; }

/**
 * @brief Loadコールの取得
 *
 * @return int コールされた回数
 */
int test::TestScene::GetLoadCall() { return call_load_; }

/**
 * @brief Updateコールの取得
 *
 * @return int コールされた回数
 */
int test::TestScene::GetUpdateCall() { return call_update_; }

/**
 * @brief Drawコールの取得
 *
 * @return int コールされた回数
 */
int test::TestScene::GetDrawCall() { return call_draw_; }

/**
 * @brief EventPopコールの取得
 *
 * @return int コールされた回数
 */
int test::TestScene::GetEventPopCall() { return call_event_pop_; }

/**
 * @brief EventPushコールの取得
 *
 * @return int コールされた回数
 */
int test::TestScene::GetEventPushCall() { return call_event_push_; }

/**
 * @brief EventSwapコールの取得
 *
 * @return int コールされた回数
 */
int test::TestScene::GetEventSwapCall() { return call_event_swap_; }

/**
 * @brief Construct a new Test Scene Stack object
 *
 * @param output_console 出力クラス
 */
test::TestSceneStack::TestSceneStack(
    std::shared_ptr<mhl::IOutputConsole> output_console)
    : mhl::UnitTestBase(output_console) {}

/**
 * @brief Destroy the Test Scene Stack object
 *
 */
test::TestSceneStack::~TestSceneStack() {}

/**
 * @brief ユニットテスト実行
 *
 */
void test::TestSceneStack::ExecuteUnitTest() {
  TestInitializeCall();
  TestReleaseCall();
  TestLoadCall();
  TestUpdateCall();
  TestDrawCall();
  TestEventPushCall();
  TestEventPopCall();
  TestEventSwapCall();
}

/**
 * @brief Initializeコールのテスト
 *
 */
void test::TestSceneStack::TestInitializeCall() {
  mhl::SceneStack stack;
  std::shared_ptr<test::TestScene> test(new test::TestScene());
  AssertEquals(test->GetInitializeCall() == 0, "");
  AssertEquals(test->GetReleaseCall() == 0, "");
  AssertEquals(test->GetLoadCall() == 0, "");
  AssertEquals(test->GetUpdateCall() == 0, "");
  AssertEquals(test->GetDrawCall() == 0, "");
  AssertEquals(test->GetEventPushCall() == 0, "");
  AssertEquals(test->GetEventPopCall() == 0, "");
  AssertEquals(test->GetEventSwapCall() == 0, "");
  stack.Push(test);
  AssertEquals(test->GetInitializeCall() == 1, "");
  AssertEquals(test->GetReleaseCall() == 0, "");
  AssertEquals(test->GetLoadCall() == 0, "");
  AssertEquals(test->GetUpdateCall() == 0, "");
  AssertEquals(test->GetDrawCall() == 0, "");
  AssertEquals(test->GetEventPushCall() == 0, "");
  AssertEquals(test->GetEventPopCall() == 0, "");
  AssertEquals(test->GetEventSwapCall() == 0, "");
}

/**
 * @brief Releaseコールのテスト
 *
 */
void test::TestSceneStack::TestReleaseCall() {}

/**
 * @brief Loadコールのテスト
 *
 */
void test::TestSceneStack::TestLoadCall() {}

/**
 * @brief Updateコールのテスト
 *
 */
void test::TestSceneStack::TestUpdateCall() {}

/**
 * @brief Drawコールのテスト
 *
 */
void test::TestSceneStack::TestDrawCall() {}

/**
 * @brief EventPushコールのテスト
 *
 */
void test::TestSceneStack::TestEventPushCall() {}

/**
 * @brief EventPopコールのテスト
 *
 */
void test::TestSceneStack::TestEventPopCall() {}

/**
 * @brief EventSwapコールのテスト
 *
 */
void test::TestSceneStack::TestEventSwapCall() {}
