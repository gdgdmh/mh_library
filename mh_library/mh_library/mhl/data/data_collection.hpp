#ifndef MHL_DATA_DATA_COLLECTION_HPP_
#define MHL_DATA_DATA_COLLECTION_HPP_

#include <vector>

namespace mhl {

// データコレクション
template <typename T>
class DataCollection {
 public:
  /**
   * @brief デフォルトコンストラクタ
   *
   */
  DataCollection() {}

  /**
   * @brief デストラクタ
   *
   */
  virtual ~DataCollection() {}

  /**
   * @brief データの追加
   *
   * @param add_data 追加するデータ
   */
  void Add(const T& add_data) { data_.emplace_back(add_data); }

  /**
   * @brief データの削除
   *
   * @param remove_data 削除対象のデータ
   */
  void Remove(const T& remove_data) {
    auto it = std::find(data_.begin(), data_.end(), remove_data);
    if (it == data_.end()) {
      return;
    }
    data_.erase(it);
    /*
    auto it = remove_data.begin();
    auto it_end = remove_data.end();
    for (; it != it_end; ++it) {
      if ((*it) == remove_data) {
        data_.erase(it);
        return;
      }
    }
    */
  }

  void Get(size_t index) const { return data_[index]; }

  size_t Size() const { return data_.size(); }

 private:
  std::vector<T> data_;  // データ配列
};

}  // namespace mhl

#endif  // MHL_DATA_DATA_COLLECTION_HPP_
