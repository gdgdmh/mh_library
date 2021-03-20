#ifndef MHL_TEST_CODE_TEST_DATA_DATA_COLLECTION_HPP_
#define MHL_TEST_CODE_TEST_DATA_DATA_COLLECTION_HPP_

#include <memory>

#include "../../test/unittest_base.hpp"

namespace test_code {

// DataCollectionのテスト
class TestDataCollection : public mhl::UnitTestBase {
 public:
  /**
   * コンストラクタ
   */
  TestDataCollection(
      std::shared_ptr<mhl::output::console::IConsoleOutputable> output_console);

  /**
   * デストラクタ
   */
  virtual ~TestDataCollection();

  /**
   * @brief ユニットテスト実行
   */
  void ExecuteUnitTest();

  void TestIntAdd1Data();
  void TestIntAdd2Data();
  void TestIntAdd10Data();
  void TestIntAdd100Data();

  void TestIntRemove1Data1Remove();
  void TestIntRemove2DataFrontRemove();
  void TestIntRemove2DataBackRemove();
  void TestIntRemove5DataFrontRemove();
  void TestIntRemove5DataCenterRemove();
  void TestIntRemove5DataBackRemove();

  void TestIntGet1Data();
  void TestIntGet2DataFront();
  void TestIntGet2DataBack();
  void TestIntGet5DataFrontRemove();
  void TestIntGet5DataCenterRemove();
  void TestIntGet5DataBackRemove();

  void TestIntSize1Data();
  void TestIntSize5Data();
  void TestIntSize10Data();
  void TestIntSize100Data();

  // void TestConstructorDefault();
};

}  // namespace test_code

#endif  // MHL_TEST_CODE_TEST_DATA_DATA_COLLECTION_HPP_
