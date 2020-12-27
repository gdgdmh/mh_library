#include "test_data_collection.hpp"

#include "../../data/data_collection.hpp"

/**
 * コンストラクタ
 */
test_code::TestDataCollection::TestDataCollection(
    std::shared_ptr<mhl::IOutputConsole> output_console)
    : UnitTestBase(output_console) {}

/**
 * デストラクタ
 */
test_code::TestDataCollection::~TestDataCollection() {}

void test_code::TestDataCollection::ExecuteUnitTest() {
  TestIntAdd1Data();
  TestIntAdd2Data();
  TestIntAdd10Data();
  TestIntAdd100Data();
  TestIntRemove1Data1Remove();
  TestIntRemove2DataFrontRemove();
  TestIntRemove2DataBackRemove();
  TestIntRemove5DataFrontRemove();
  TestIntRemove5DataCenterRemove();
  TestIntRemove5DataBackRemove();
  TestIntGet1Data();
  TestIntGet2DataFront();
  TestIntGet2DataBack();
  TestIntGet5DataFrontRemove();
  TestIntGet5DataCenterRemove();
  TestIntGet5DataBackRemove();
  TestIntSize1Data();
  TestIntSize5Data();
  TestIntSize10Data();
  TestIntSize100Data();
}

// void test_code::TestDataCollection::TestConstructorDefault() {
// mhl::BitControlUint32 b;
// AssertEquals(b.Get() == 0, "");
//}

void test_code::TestDataCollection::TestIntAdd1Data() {
  const int kValue = 9732;
  const int kSize = 1;
  mhl::DataCollection<int> d;
  d.Add(kValue);
  AssertEquals(d.Size() == kSize, "");
}
void test_code::TestDataCollection::TestIntAdd2Data() {}
void test_code::TestDataCollection::TestIntAdd10Data() {}
void test_code::TestDataCollection::TestIntAdd100Data() {}
void test_code::TestDataCollection::TestIntRemove1Data1Remove() {}
void test_code::TestDataCollection::TestIntRemove2DataFrontRemove() {}
void test_code::TestDataCollection::TestIntRemove2DataBackRemove() {}
void test_code::TestDataCollection::TestIntRemove5DataFrontRemove() {}
void test_code::TestDataCollection::TestIntRemove5DataCenterRemove() {}
void test_code::TestDataCollection::TestIntRemove5DataBackRemove() {}
void test_code::TestDataCollection::TestIntGet1Data() {}
void test_code::TestDataCollection::TestIntGet2DataFront() {}
void test_code::TestDataCollection::TestIntGet2DataBack() {}
void test_code::TestDataCollection::TestIntGet5DataFrontRemove() {}
void test_code::TestDataCollection::TestIntGet5DataCenterRemove() {}
void test_code::TestDataCollection::TestIntGet5DataBackRemove() {}
void test_code::TestDataCollection::TestIntSize1Data() {}
void test_code::TestDataCollection::TestIntSize5Data() {}
void test_code::TestDataCollection::TestIntSize10Data() {}
void test_code::TestDataCollection::TestIntSize100Data() {}
