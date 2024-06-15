#include "a_pch.h"
#include "mhl/state/State.hpp"

namespace mhl
{
    namespace state
    {

        enum class TestState : int32_t
        {
            None,
            First,
            Second,
            Third,
            Max
        };

        /**
         * @brief コンストラクタステータスデフォルト値チェック
         *
         */
        TEST(State, ConstructorDefaultState)
        {
            State<TestState> s;
            EXPECT_EQ(s.GetState(), TestState::None);
        }

        /**
         * @brief コンストラクタリクエストステータスデフォルト値チェック
         *
         */
        TEST(State, ConstructorDefaultRequestState)
        {
            State<TestState> s;
            EXPECT_EQ(s.GetRequestState(), TestState::None);
        }

        /**
         * @brief ステータス変更リクエスト None設定
         * 
         */
        TEST(State, RequestChangeSetNone)
        {
            State<TestState> s;
            s.RequestChange(TestState::None);
            EXPECT_EQ(s.GetState(), TestState::None);
            EXPECT_EQ(s.GetRequestState(), TestState::None);
        }

        /**
         * @brief ステータス変更リクエスト First設定
         * 
         */
        TEST(State, RequestChangeSetFirst)
        {
            State<TestState> s;
            s.RequestChange(TestState::First);
            EXPECT_EQ(s.GetState(), TestState::None);
            EXPECT_EQ(s.GetRequestState(), TestState::First);
        }

        /**
         * @brief 即時ステータス変更リクエスト First設定
         * 
         */
        TEST(State, DoImmidateRequestChangeSetFirst)
        {
            State<TestState> s;
            s.DoImmediateChangeRequest(TestState::First);
            EXPECT_EQ(s.GetState(), TestState::First);
            EXPECT_EQ(s.GetRequestState(), TestState::First);
        }

        /**
         * @brief 変更リクエスト適用 First設定
         * 
         */
        TEST(State, ApplyChangeFirst)
        {
            State<TestState> s;
            s.RequestChange(TestState::First);

            bool result = s.ApplyChangeRequest();
            EXPECT_EQ(s.GetState(), TestState::First);
            EXPECT_EQ(s.GetRequestState(), TestState::First);
            EXPECT_EQ(result, true);
        }

        /**
         * @brief 変更リクエスト適用 変更なし
         * 
         */
        TEST(State, ApplyChangeNoChange)
        {
            State<TestState> s;
            s.DoImmediateChangeRequest(TestState::First);
            bool result = s.ApplyChangeRequest();
            EXPECT_EQ(s.GetState(), TestState::First);
            EXPECT_EQ(s.GetRequestState(), TestState::First);
            EXPECT_EQ(result, false);
        }

    } // namespace bit
} // namespace mhl
