#ifndef MHL_TEST_PROGRAM_ROUTE_SEARCH_SET_FIELD_BLOCK_ALWAYS_HPP_
#define MHL_TEST_PROGRAM_ROUTE_SEARCH_SET_FIELD_BLOCK_ALWAYS_HPP_

#include <stdint.h>

#include <memory>
#include <mhl/test_program/route_search/Field.hpp>
#include <mhl/test_program/route_search/IFieldBlockSettable.hpp>

namespace test_program
{

    namespace route_search
    {

        /**
         * @brief ボンバーマンのいつものと同じブロック配置をする
         *
         */
        class SetFieldBlockAlways : public IFieldBlockSettable
        {
        public:
            /**
             * @brief Set the Field Block Always object
             *
             */
            SetFieldBlockAlways();

            /**
             * @brief Destroy the IFieldBlockChangeable object
             *
             */
            ~SetFieldBlockAlways() override;

            /**
             * @brief フィールドのブロック
             *
             * @param field
             */
            void SetBlock(Field &field) override;
        };

    } // namespace route_search

} // namespace test_program

#endif  // MHL_TEST_PROGRAM_ROUTE_SEARCH_SET_FIELD_BLOCK_ALWAYS_HPP_
