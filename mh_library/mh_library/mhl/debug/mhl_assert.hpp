#ifndef MHL_DEBUG_MHL_ASSERT_HPP_
#define MHL_DEBUG_MHL_ASSERT_HPP_

#include <cassert>

namespace mhl {

namespace debug {

#ifndef MHL_ASSERT
// 一時しのぎのassert
#define MHL_ASSERT(expr, msg) _ASSERT_EXPR(expr, msg)
#endif  // MHL_ASSERT

}  // namespace debug

}  // namespace mhl

#endif  // MHL_DEBUG_MHL_ASSERT_HPP_
