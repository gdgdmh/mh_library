#ifndef MHL_TEST_PROGRAM_TEST_DELEGATE_TEST_HPP_
#define MHL_TEST_PROGRAM_TEST_DELEGATE_TEST_HPP_

#include <memory>

#include "../test/unittest_base.hpp"
#include "../util/string/std_string_formatter.hpp"

namespace test_program {

class TestDog {
 public:
  /**
   * @brief Construct a new Test Dog object
   *
   * @param output_console
   */
  TestDog(std::shared_ptr<mhl::output::console::IOutputConsole> output_console)
      : console(output_console) {}

  /**
   * @brief 吠える
   *
   * @param value 値
   */
  void woof(int value) {
    console->PrintLine(mhl::StdStringFormatter::Format("woof %d", value));
  }

 private:
  std::shared_ptr<mhl::output::console::IOutputConsole>
      console;  // コンソール出力
};

class TestCat {
 public:
  /**
   * @brief Construct a new Test Cat object
   *
   * @param output_console コンソール出力
   */
  TestCat(std::shared_ptr<mhl::output::console::IOutputConsole> output_console)
      : console(output_console) {}
  /**
   * @brief 鳴くクラス
   *
   * @param value 値
   */
  void meow(int value) {
    console->PrintLine(mhl::StdStringFormatter::Format("meow %d", value));
  }

 private:
  std::shared_ptr<mhl::output::console::IOutputConsole>
      console;  // コンソール出力
};

/**
 * @brief delegateのためのベースクラス
 *
 */
class TestTukuroDelegateBase {
 public:
  TestTukuroDelegateBase() {}
  virtual ~TestTukuroDelegateBase() {}

  virtual void operator()(int value) = 0;
};

/**
 * @brief デリゲートクラス
 *
 * @tparam T
 */
template <class T>
class TestTukuroDelegate : public TestTukuroDelegateBase {
 public:
  TestTukuroDelegate() {}
  virtual ~TestTukuroDelegate() {}

  virtual void operator()(int value) { (m_obj.get()->*m_func)(value); }

  typedef void (T::*EventFunc)(int);

  /**
   * @brief delegate登録
   *
   * @param obj delegate登録クラス
   * @param func 呼び出すメソッド
   */
  void set(std::shared_ptr<T> obj, EventFunc func) {
    m_obj = obj;
    m_func = func;
  }

  /**
   * @brief Delegate生成
   *
   * @param obj delegate登録クラス
   * @param func 呼び出すメソッド
   * @return std::shared_ptr<TestTukuroDelegateBase> 生成したdelegate
   */
  static std::shared_ptr<TestTukuroDelegateBase> createDelegator(
      std::shared_ptr<T> obj, void (T::*func)(int)) {
    std::shared_ptr<TestTukuroDelegate> d(new TestTukuroDelegate());
    d->set(obj, func);
    return d;
  }

 protected:
  std::shared_ptr<T> m_obj;  // オブジェクト
  EventFunc m_func;          // 関数ポインタ
};

/**
 * @brief ドアベルクラス
 *
 */
class TestTukuroDoorBell {
 public:
  TestTukuroDoorBell(
      std::shared_ptr<mhl::output::console::IOutputConsole> output_console)
      : console(output_console) {}

  /**
   * @brief ドアオープンイベント
   *
   */
  void onOpenDoor() {
    for (int i = 0; i < events.size(); ++i) {
      std::shared_ptr<TestTukuroDelegateBase> base = events[i];
      (*base)(0);
    }
  }

  /**
   * @brief onOpenDoorハンドラの設定
   *
   * @param delegate
   */
  void setOnOpenDoorHandler(std::shared_ptr<TestTukuroDelegateBase> delegate) {
    events.push_back(delegate);
  }

 private:
  std::shared_ptr<mhl::output::console::IOutputConsole> console;
  std::vector<std::shared_ptr<TestTukuroDelegateBase> > events;
};

/**
 * @brief delegateテスト
 *
 */
class TestDelegateTest : public mhl::UnitTestBase {
 public:
  /**
   * コンストラクタ
   */
  TestDelegateTest(
      std::shared_ptr<mhl::output::console::IOutputConsole> output_console);

  /**
   * デストラクタ
   */
  virtual ~TestDelegateTest();

  void ExecuteUnitTest();

 private:
};

}  // namespace test_program

#endif  // MHL_TEST_PROGRAM_TEST_DELEGATE_TEST_HPP_
