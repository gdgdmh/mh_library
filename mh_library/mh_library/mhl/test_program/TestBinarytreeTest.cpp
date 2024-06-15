#include "TestBinarytreeTest.hpp"

#include <algorithm>
#include <vector>

/**
 * コンストラクタ
 */
test_program::TestBinaryTest::TestBinaryTest(
    std::shared_ptr<mhl::output::console::IConsoleOutputables> output_console) :
    UnitTestBase(output_console)
{
}

/**
 * デストラクタ
 */
test_program::TestBinaryTest::~TestBinaryTest()
{
}

void test_program::TestBinaryTest::ExecuteUnitTest()
{
    TestIntTest();
    TestBinaryClassTest();
}

void test_program::TestBinaryTest::TestIntTest()
{
    std::vector<int> v;
    for (int i = 0; i < 10; ++i)
    {
        v.push_back(i);
    }
    {
        // ソート済み配列が必須
        std::sort(v.begin(), v.end());
        // 5を探す
        // 仕様として探せなくてもend以外で返ってくる可能性はある
        {
            {
                auto lower_it =
                    std::lower_bound(v.begin(), v.end(), 5);
                if (lower_it != v.end() && (*lower_it) == 5)
                {
                    std::string s = mhl::string::format::Formatter::Format(
                        "low 5 find -> %d", (*lower_it));
                    output_console_->PrintLine(s);
                }
                else
                {
                    output_console_->PrintLine("low 5 find -> not found");
                }
            }
        }
    }
    // 無い数字を探す(endのイテレータが返ってくる)
    {
        auto it = std::lower_bound(v.begin(), v.end(), 11);
        if (it != v.end())
        {
            std::string s2 =
                mhl::string::format::Formatter::Format("low none -> %d", (*it));
            output_console_->PrintLine(s2);
        }
    }
    // 7を探す
    {
        auto it = std::lower_bound(v.begin(), v.end(), 7);
        if (it != v.end())
        {
            std::string s =
                mhl::string::format::Formatter::Format("low 7 find -> %d", (*it));
            output_console_->PrintLine(s);
        }
    }
    // 9を探す
    {
        auto it = std::lower_bound(v.begin(), v.end(), 9);
        if (it != v.end())
        {
            std::string s =
                mhl::string::format::Formatter::Format("low 9 find -> %d", (*it));
            output_console_->PrintLine(s);
        }
    }

    // upper_bound
    {
        // 7
        {
            auto it = std::upper_bound(v.begin(), v.end(), 7);
            if (it != v.end())
            {
                std::string s =
                    mhl::string::format::Formatter::Format("up 7 find -> %d", (*it));
                output_console_->PrintLine(s);
            }
        }
        // 0
        {
            auto it = std::upper_bound(v.begin(), v.end(), 0);
            if (it != v.end())
            {
                std::string s =
                    mhl::string::format::Formatter::Format("up 0 find -> %d", (*it));
                output_console_->PrintLine(s);
            }
        }
        // -1
        // 仕様として探せなくてもend以外で返ってくる可能性はある
        // このケースのときに発生する
        {
            auto it = std::upper_bound(v.begin(), v.end(), -1);
            if (it != v.end())
            {
                std::string s =
                    mhl::string::format::Formatter::Format("up -1 find -> %d", (*it));
                output_console_->PrintLine(s);
            }
        }
    }
}

void test_program::TestBinaryTest::TestBinaryClassTest()
{
    std::vector<TestBinaryClass> v;
    for (int i = 0; i < 10000; ++i)
    {
        TestBinaryClass t(i, mhl::string::format::Formatter::Format("%d", i));
        v.push_back(t);
    }
    // lower_bound
    {
        TestBinaryClass t(500, "AAA");
        auto it = std::lower_bound(v.begin(), v.end(), t,
                                   [](const TestBinaryClass &a, const TestBinaryClass &b)
                                   {
                                       return a.GetId() < b.GetId();
                                   });
        if (it != v.end())
        {
            std::string s = mhl::string::format::Formatter::Format(
                "lower 500 find -> id %d val %s",
                it->GetId(), it->GetValue().c_str());
            output_console_->PrintLine(s);
        }
    }
}
