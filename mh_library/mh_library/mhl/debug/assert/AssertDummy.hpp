#ifndef MHL_DEBUG_ASSERT_MHL_ASSERT_DUMMY_HPP_
#define MHL_DEBUG_ASSERT_MHL_ASSERT_DUMMY_HPP_

#include <cassert>
#include <mhl/debug/assert/IAssertProcessor.hpp>

namespace mhl
{

    namespace debug
    {

        namespace assert
        {

            /**
             * @brief アサーションダミークラス
             * 確認用に呼ばれたどうかの確認に使用する
             *
             */
            class AssertDummy : public IAssertProcessor
            {
            public:
                AssertDummy() :
                    isCalled(false)
                {
                }

                /**
                 * @brief デストラクタ
                 *
                 */
                ~AssertDummy() override = default;

                /**
                 * @brief アサーション処理
                 *
                 */
                void Assert() override
                {
                    isCalled = true;
                }

                /**
                 * @brief アサーションが呼ばれたかチェック
                 *
                 * @return true アサーションが呼ばれた
                 * @return false アサーションが呼ばれてない
                 */
                virtual bool IsCalled() const
                {
                    return isCalled;
                }

                /**
                 * @brief フラグリセット処理
                 */
                virtual void Reset()
                {
                    isCalled = false;
                }

            private:
                bool isCalled; // アサーションが呼ばれたか判定するフラグ
            };

        } // namespace assert

    } // namespace debug

} // namespace mhl

#endif  // MHL_DEBUG_ASSERT_MHL_ASSERT_DUMMY_HPP_
