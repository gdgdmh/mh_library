#ifndef MHL_TEST_PROGRAM_TEST_COMPONENT_TEST_HPP_
#define MHL_TEST_PROGRAM_TEST_COMPONENT_TEST_HPP_

#include <stdint.h>

#include <memory>

#include "../test/unittest_base.hpp"

namespace test_program {

/**
 * @brief コンポーネントのベース
 *
 */
class TestComponentBase {
 public:
  TestComponentBase(uint64_t id) : id_(id) {}

 public:
  virtual void Initialize() {}
  virtual void Task() {}
  void SetName(const std::string& name) { name_ = name; }
  void SetTag(const std::string& tag) { tag_ = tag; }

 public:
  const uint64_t getId() const { return id_; }
  const std::string& getName() const { return name_; }
  const std::string& getTag() const { return tag_; }

 private:
  uint64_t id_;
  std::string name_;  // オブジェクトの名前
  std::string tag_;   // オブジェクトのタグ
};

class TestAttackComponent : public TestComponentBase {
 public:
  TestAttackComponent(uint64_t id) : TestComponentBase(id) {}
  virtual ~TestAttackComponent() {}

 public:
  void Initialize() override {}
  void Task() override {}
};

class TestComponentManager {
 public:
  TestComponentManager() {}
  virtual ~TestComponentManager() { components_.clear(); }

 public:
  uint64_t Add(std::shared_ptr<TestComponentBase> component) {
    if (!component) {
      return 0;
    }
    components_.emplace_back(component);
    return component->getId();
  }

  std::shared_ptr<TestComponentBase> Get(uint64_t id) {
    for (auto& component : components_) {
      if ((component) && (component->getId() == id)) {
        return component;
      }
    }
    return nullptr;
  }

 private:
  std::vector<std::shared_ptr<TestComponentBase> > components_;
};

/**
 * @brief コンポーネントテスト用のプレイヤー
 *
 */
class TestPlayer {};

/**
 * @brief コンポーネントの仕組みのテスト
 *
 */
class TestComponentTest : public mhl::UnitTestBase {
 public:
  /**
   * @brief Construct a new Test Component Test object
   *
   * @param output_console コンソール出力クラス
   */
  TestComponentTest(std::shared_ptr<mhl::output::console::IConsoleOutputables>
                        output_console);

  /**
   * @brief Destroy the Test Component Test object
   *
   */
  virtual ~TestComponentTest();

  void ExecuteUnitTest();
};

}  // namespace test_program

#endif  // MHL_TEST_PROGRAM_TEST_COMPONENT_TEST_HPP_
