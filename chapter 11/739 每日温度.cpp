#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "bits/stdc++.h"
#include "doctest.h"
using namespace std;
// 739. Daily Temperatures

class Solution
{
  public:
    vector<int>
    dailyTemperatures (vector<int> T)
    // dailyTemperatures (vector<int> &T)
    {
        int len = T.size ();
        vector<int> days (len, 0);
        stack<int> temper_index;

        if (T.empty ())
        {
            return days;
        }

        temper_index.push (0);
        for (int i = 1; i < len; i++)
        {
            int val = T[i];
            while (!temper_index.empty () && T[temper_index.top ()] < val) // wqs, look back until the second highest, 
            // wqs the second highest is the warmer of the previous
            {
                days[temper_index.top ()] = i - temper_index.top ();
                temper_index.pop ();
            }

            temper_index.push (i); // wqs go and store the future
        }

        return days;
    }
};

TEST_CASE("name"){
    // Input: [73, 74, 75, 71, 69, 72, 76, 73]
    // Output: [1, 1, 4, 2, 1, 1, 0, 0]
    // error: non-const lvalue reference to type 'vector<int>' cannot bind to an initializer list temporary
    // :wqs remove the & reference in parameter list

    // error: initializer list cannot be used on the right hand side of operator '==': wqs add "vector<int>"
    CHECK (Solution ().dailyTemperatures ({ 73, 74, 75, 71, 69, 72, 76, 73 })
           == vector<int>{ 1, 1, 4, 2, 1, 1, 0, 0 });
}