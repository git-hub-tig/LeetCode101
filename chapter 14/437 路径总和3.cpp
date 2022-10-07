
// 437. Path Sum III

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "bits/stdc++.h"
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode () : val (0), left (nullptr), right (nullptr) {}
    TreeNode (int x) : val (x), left (nullptr), right (nullptr) {}
    TreeNode (int x, TreeNode *left, TreeNode *right)
        : val (x), left (left), right (right)
    {
    }
};

class Solution
{
  public:
    int
    dfs (TreeNode *root, int targetSum)
    {
        int total = 0;
        if (root == NULL)
        {
            // assert(targetSum != 0);
            return 0;
        }

        if (root->val == targetSum)
        {
            total = 1 + dfs (root->left, 0) + dfs (root->right, 0);
            return total;
        }

        // root->val != targetSum
        int add = targetSum - root->val;
        return dfs (root->left, add) + dfs (root->right, add);
    }

    int
    pathSum (TreeNode *root, int targetSum)
    {
        if (root == NULL)
        {
            return 0;
        }

        int inleft = pathSum (root->left, targetSum);
        int inright = pathSum (root->right, targetSum);
        int incurr = dfs (root, targetSum);

        int total = inleft + inright + incurr;
        return total;
    }
};

TEST_CASE ("testing factorial")
{
    TreeNode root (10);
    // TreeNode root{ 10 };
    // error: taking the address of a temporary object of type 'TreeNode'
    // [-Waddress-of-temporary] root.left = &TreeNode (3);

    //  SIGSEGV - Segmentation violation signal
    // *(root.left) = TreeNode (3);

    { // this is right
        TreeNode *tmp = new TreeNode (3);
        root.left = tmp;
        tmp = new TreeNode (4);
        root.right = tmp;
        tmp = new TreeNode (2); // wqs this will fail cause no initialize
        root.left->left = tmp;
        tmp = new TreeNode (1);
        root.right->left = tmp;
        cout << "fdsf" << endl;
    }

    {
        // TreeNode tmp = TreeNode (3);
        // root.left = &tmp;
        // tmp = TreeNode (4); // careful, nonew, tmp is still the same address
        // of the TreeNode (3) root.right = &tmp; tmp = TreeNode (2); // wqs
        // this will fail cause no initialize root.left->left = &tmp; tmp =
        // TreeNode (9); root.right->left = &tmp;
    }

    CHECK (Solution ().pathSum (&root, 15) == 2);
    // CHECK (factorial (1) == 1);
    // CHECK (factorial (2) == 2);
    // CHECK (factorial (3) == 6);
    // CHECK (factorial (10) == 3628800);
}

// main