#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "bits/stdc++.h"
#include "doctest.h"
using namespace std;

// 3. Longest Substring Without Repeating Characters

class Solution
{
  public:
    int
    lengthOfLongestSubstring2 (string s)
    {
        int len = size (s);
        if (len <= 1)
        // if (s.empty () || len == 1)
        {
            return len;
        }

        unordered_map<char, int> char2Pos;
        char2Pos[s[0]] = 0;
        int left_index = 0;
        int maxSub = 1;
        for (int right_index = 1; right_index < len; right_index++)
        {
            char ch = s[right_index];
            // if (find (begin (char2Pos), end (char2Pos), ch) != char2Pos.end
            // ())
            if (char2Pos.find (ch) != char2Pos.end ())
            {
                int loc = char2Pos[ch];

                for (int x = left_index; x <= loc; x++)
                {
                    char2Pos.erase (s[x]);
                }

                left_index = loc + 1;
            }

            char2Pos[ch] = right_index;
            maxSub = max (maxSub, right_index - left_index + 1);
        }
        return maxSub;
    }

    int
    lengthOfLongestSubstring (string s)
    {
        int len = size (s);
        if (len <= 1)
        // if (s.empty () || len == 1)
        {
            return len;
        }

        map<char, int> char2Pos;
        char2Pos[s[0]] = 0;
        int left_index = 0;
        int maxSub = 1;
        for (int right_index = 1; right_index < len; right_index++)
        {
            char ch = s[right_index];
            auto iter = char2Pos.find (ch);
            // auto iter = find (begin (char2Pos), end (char2Pos), ch); //
            // pair<const char, int>') and 'int' operands fail
            if (iter != char2Pos.end ())
            // if (char2Pos.find (ch) != char2Pos.end ())
            {
                // auto ret = remove(begin(char2Pos), iter, [](){return
                // true;});

                // not include
                // while (__f != __l)
                //     __f = erase(__f);
                // return iterator(__l.__ptr_);
                char2Pos.erase (begin (char2Pos), iter);
                left_index = (*iter).second + 1;
            }
            else
            {
                char2Pos[ch] = right_index;
            }

            // char2Pos[ch] = right_index; // wqs this need, cause the .erase()
            // keep the last element
            maxSub = max (maxSub, right_index - left_index + 1);
        }
        return maxSub;
    }
};

TEST_CASE ("testing")
{
    CHECK (Solution ().lengthOfLongestSubstring ("abcddefgh") == 5);
}

TEST_CASE ("testing2")
{
    CHECK (Solution ().lengthOfLongestSubstring ("") == 0);
}

// TEST_CASE("testing"){
//     CHECK (Solution().lengthOfLongestSubstring ("abcddefgh") == 5);
// }