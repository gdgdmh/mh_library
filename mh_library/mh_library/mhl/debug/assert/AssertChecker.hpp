#ifndef MHL_DEBUG_ASSERT_MHL_ASSERT_CHECKER_HPP_
#define MHL_DEBUG_ASSERT_MHL_ASSERT_CHECKER_HPP_

#include <mhl/debug/assert/IAssertChecker.hpp>

namespace mhl
{

    namespace debug
    {

        namespace assert
        {

            /**
             * @brief アサーションチェックインターフェース
             *
             */
            class AssertChecker : public IAssertChecker
            {
            public:
                AssertChecker()
                {
                }

                /**
                 * @brief デストラクタ
                 *
                 */
                ~AssertChecker() override
                {
                }

                /**
                 * @brief チェック
                 *
                 * @param value trueならチェックOK
                 * @return true チェックOK
                 * @return false チェックNG
                 */
                bool Check(const bool value) override
                {
                    return value;
                }
            };

        } // namespace assert

    } // namespace debug

} // namespace mhl

#endif  // MHL_DEBUG_ASSERT_MHL_ASSERT_CHECKER_HPP_
