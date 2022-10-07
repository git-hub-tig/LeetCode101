#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "bits/stdc++.h"
#include "doctest.h"
using namespace std;
// 205. Isomorphic Strings
// 同构的定义是，可以通过把一个字符串的某些相同的字符转换成
// 另一些相同的字符，使得两个字符串相同，且两种不同的字符不能够被转换成同一种字符。
class Solution
{
  public:
    bool
    isIsomorphic (string s, string t)
    {
        int slen = size (s);
        int tlen = t.size ();

        if (slen != tlen)
        {
            return false;
        }

        unordered_set<char> hash; // wqs not ordered, decrease the time complexity
        unordered_map<char, char> dic;
        for (int i = 0; i < slen; i++)
        {
            // assert(slen == tlen);

            if (dic.find (s[i]) == dic.end ()) // wqs first appeared
            {
                if (hash.find (t[i]) != hash.end ())
                {
                    return false;
                }

                dic[s[i]] = t[i]; // wqs core data structure, s -> t the map
                hash.insert (t[i]); // wqs, store the t element, 
                // continue; 
            }

            // assert(dic.find(s[i]) != dic.end());
            else if (dic[s[i]] != t[i]) // wqs, have appeared
            {
                return false;
            }
        }

        return true;
    }
};

TEST_CASE ("name")
{
    // TEST_CASE("name"){
    CHECK (Solution ().isIsomorphic ("aba", "bdb") == true);
}