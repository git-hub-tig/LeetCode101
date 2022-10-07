
// 5. Longest Palindromic Substring
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "bits/stdc++.h"
#include "doctest.h"
using namespace std;

class Solution
{
  public:
    string
    longestPalindrome (string s)
    {
        int len = s.size ();
        if (len < 2)
        {
            return s;
        }

        vector<vector<bool> > dp (len, vector<bool> (len, false));
        int maxLen = 1;
        pair<int, int> palStr (0, 0);

        for (int i = 0; i < len - 1; i++)
        {
            dp[i][i] = true;
            if (s[i] == s[i + 1]) // wqs recursion base
            {
                dp[i][i + 1] = true;
                maxLen = 2;
                palStr.first = i;
                palStr.second = i + 1;
            }
        }
        dp[len - 1][len - 1] = true;

        for (int l = 2; l < len; l++)
        {
            for (int i = 0; i < len - l; i++)
            {
                dp[i][i + l] = ((s[i] == s[i + l]) && dp[i + 1][i + l - 1]); // wqs dp recursively condition
                if (dp[i][i + l] && l + 1 > maxLen) // wqs update
                {
                    maxLen = l + 1;
                    palStr.first = i;
                    palStr.second = i + l;
                }
            }
        }

        return string(begin(s)+palStr.first, begin(s)+palStr.first+maxLen);
        // return s.substr (palStr.first, maxLen);
    }
};

TEST_CASE ("name")
{
    CHECK (Solution().longestPalindrome ("1") == "1");
    CHECK (Solution().longestPalindrome ("") == "");
    CHECK (Solution().longestPalindrome ("abc123321") == "123321");
}
