#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "bits/stdc++.h"
#include "doctest.h"
using namespace std;

// 20. Valid Parentheses

class Solution
{
  public:
    bool
    isValid (string s)
    {
        // assert(!s.empty());

        int len = s.size ();
        stack<char> stk;
        for (int i = 0; i < len; i++)
        {
            if (s[i] == '{' || s[i] == '(' || s[i] == '[')
            {
                stk.push (s[i]);
                continue;
            }

            if (stk.empty ()) // wqs anytime should contain the open parentheses
            {
                return false;
            }

            char ch = stk.top ();
            if ((ch == '{' && s[i] == '}') || (ch == '(' && s[i] == ')')
                || (ch == '[' && s[i] == ']'))
            {

                stk.pop (); // wqs delete one open parenthese
            }
            else
            {
                return false;
            }
        }

        if (stk.empty ())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

TEST_CASE ("name"){
    // 给定一个只由左右圆括号、花括号和方括号组成的字符串，求这个字符串是否合法。合法的 定义是每一个类型的左括号都有一个右括号一一对应，且括号内的字符串也满足此要求。
    CHECK(Solution ().isValid ("{[]}()")==true);
}