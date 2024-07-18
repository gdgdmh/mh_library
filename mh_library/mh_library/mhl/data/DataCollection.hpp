#ifndef MHL_DATA_DATA_COLLECTION_HPP_
#define MHL_DATA_DATA_COLLECTION_HPP_

#include <vector>

namespace mhl
{

    // データコレクション
    template <typename T>
    class DataCollection
    {
    public:
        /**
         * @brief デフォルトコンストラクタ
         *
         */
        DataCollection()
        {
        }

        /**
         * @brief デストラクタ
         *
         */
        virtual ~DataCollection()
        {
        }

        /**
         * @brief データの追加
         *
         * @param addData 追加するデータ
         */
        void Add(const T &addData)
        {
            data_.emplace_back(addData);
        }

        /**
         * @brief データの削除
         *
         * @param removeData 削除対象のデータ
         */
        void Remove(const T &removeData)
        {
            auto it = std::find(data_.begin(), data_.end(), removeData);
            if (it == data_.end())
            {
                return;
            }
            data_.erase(it);
        }

        void Get(size_t index) const
        {
            return data_[index];
        }

        size_t Size() const
        {
            return data_.size();
        }

    private:
        std::vector<T> data_; // データ配列
    };

} // namespace mhl

#endif  // MHL_DATA_DATA_COLLECTION_HPP_
