#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "bits/stdc++.h"
#include "doctest.h"
using namespace std;

// 128. Longest Consecutive Sequence

class Solution
{
  public:
    int
    longestConsecutive (vector<int> nums)
    {
        int numLen = nums.size ();
        int maxLen = 0;
        unordered_set<int> hash; // wqs for the bad case that have duplicate elements

        if (numLen <= 1)
        {
            return numLen;
        }

        for (int i = 0; i < numLen; i++)
        {
            hash.insert (nums[i]);
        }

        while (!hash.empty ())
        {
            auto it = hash.begin ();
            int curr = *it; // wqs investigate the current value's continuous sequence, that will erase the continuous sequence from the sequence
            int len = 0;

            while (it != hash.end ())
            {
                len++; // wqs the record of the pursue
                int val = *it;
                hash.erase (val); // wqs hash is unique for the set,
                it = hash.find (val + 1);
            }

            it = hash.find (curr - 1);
            while (it != hash.end ())
            {
                len++;
                int val = *it;
                hash.erase (val);
                it = hash.find (val - 1);
            }

            maxLen = max (maxLen, len);
        }

        return maxLen;
    }
};

TEST_CASE ("name")
{
    //  给定一个整数数组，求这个数组中的数字可以组成的最长连续序列有多长。
    CHECK (Solution ().longestConsecutive ({ 100, 4, 200, 1, 3, 2 }) == 4);
}