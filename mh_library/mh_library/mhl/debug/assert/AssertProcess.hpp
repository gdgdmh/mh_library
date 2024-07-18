#ifndef MHL_DEBUG_ASSERT_MHL_ASSERT_PROCESS_HPP_
#define MHL_DEBUG_ASSERT_MHL_ASSERT_PROCESS_HPP_

#include <cassert>
#include <mhl/debug/assert/IAssertProcessor.hpp>

namespace mhl
{

    namespace debug
    {

        namespace assert
        {
            /**
             * @brief アサーション処理クラス
             *
             * アサーションのハンドリング処理を行う
             */
            class AssertProcess : public IAssertProcessor
            {
            public:
                /**
                 * @brief コンストラクタ
                 *
                 */
                AssertProcess() = default;

                /**
                 * @brief デストラクタ
                 *
                 */
                ~AssertProcess() override = default;

                /**
                 * @brief アサーション処理
                 *
                 */
                void Assert() override
                {
                    assert(0);
                }
            };

        } // namespace assert

    } // namespace debug

} // namespace mhl

#endif  // MHL_DEBUG_ASSERT_MHL_ASSERT_PROCESS_HPP_
