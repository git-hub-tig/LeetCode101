#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "bits/stdc++.h"
#include "doctest.h"
using namespace std;
// 647. Palindromic Substrings

class Solution
{
  public:
    int
    countSubstrings (string s)
    {
        int len = s.size ();
        if (len <= 1)
        {
            return len;
        }

        int count = 0;
        vector<vector<bool> > dp (len, vector<bool> (len, false));
        for (int i = 0; i <= len - 2; i++) // wqs, will index i and i+1
        {
            dp[i][i] = true; // wqs init, recursion base condition
            count++;

            if (s[i] == s[i + 1])
            {
                dp[i][i + 1] = true; // wqs init, recursion base condition
                count++;
            }
            else
            {
                dp[i][i + 1] = false;
            }
        }

        dp[len - 1][len - 1] = true;
        count++;

        for (int l = 2; l < len; l++) // wqs l is the length of the palindrome
        {
            for (int i = 0; i < len - l; i++)
            {
                if (s[i] == s[i + l] && dp[i + 1][i + l - 1])
                {
                    dp[i][i + l] = true;
                    count++;
                    continue;
                }

                dp[i][i + l] = false; // wqs, dp is a matrix, of len*len
            }
        }

        return count;
    }
};

TEST_CASE ("name")
{
    CHECK (Solution ().countSubstrings ("abc") == 3);  // 4 + 1 =5
    CHECK (Solution ().countSubstrings ("aaa") == 6);  // 4 + 1 =5
    CHECK (Solution ().countSubstrings ("a121") == 5); // 4 + 1 =5
    CHECK (Solution ().countSubstrings ("a1211221")
           == 13); // 8(length 1)+2(length 2) + 1(length 3)+2(len 4)
}