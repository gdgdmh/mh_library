#ifndef MHL_DEBUG_ASSERT_MHL_IASSERT_CHECKER_HPP_
#define MHL_DEBUG_ASSERT_MHL_IASSERT_CHECKER_HPP_

#include <stdint.h>

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
            class IAssertChecker
            {
            public:
                /**
                 * @brief コンストラクタ
                 *
                 */
                IAssertChecker() = default;
                
                /**
                 * @brief デストラクタ
                 *
                 */
                virtual ~IAssertChecker() = default;

                /**
                 * @brief チェック
                 *
                 * @param value trueならチェックOK
                 * @return true チェックOK
                 * @return false チェックNG
                 */
                virtual bool Check(bool value) = 0;
            };

        } // namespace assert

    } // namespace debug

} // namespace mhl

#endif  // MHL_DEBUG_ASSERT_MHL_IASSERT_CHECKER_HPP_
