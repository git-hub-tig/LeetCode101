#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "bits/stdc++.h"
using namespace std;

// 409. Longest Palindrome

class Solution
{
  public:
    int
    longestPalindrome (string s)
    {
        int len = s.size ();

        if (s.empty () || len == 1)
        {
            return len;
        }

        unordered_map<char, int> dic;
        for (int i = 0; i < len; i++)
        {
            ++dic[s[i]];
        }

        int palLen = 0, single = 0;
        // unordered_map<char, int>::iterator it;
        for (auto it = dic.begin (); it != dic.end (); ++it)
        {
            int num = it->second;
            if (num % 2 == 0) // wqs repeated even value, like the the left and right value of palindrome
            {
                palLen += num;
            }
            else
            {
                if (num > 1)
                {
                    palLen += (num - 1);
                }

                single += 1;
            }
        }

        if (single > 0)
        {
            palLen += 1;
        }

        return palLen;
    }
};

TEST_CASE ("test_name")
{
    // Input: s = "abccccdd"
    // Output: 7
    // Explanation: One longest palindrome that can be built is "dccaccd", whose length is 7.
    CHECK (Solution ().longestPalindrome ("1") == 1);
    CHECK (Solution ().longestPalindrome ("121") == 3);
    CHECK (Solution ().longestPalindrome ("a1221") == 5);
    CHECK (Solution ().longestPalindrome ("") == 0);
    CHECK (Solution ().longestPalindrome ("abc123321") == 7);
}