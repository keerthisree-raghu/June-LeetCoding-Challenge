// COUNT COMPLETE TREE NODES

/*  PROBLEM:
    Given a non-empty array of integers, every element appears three times 
    except for one, which appears exactly once. Find that single one.

    Note:
    Your algorithm should have a linear runtime complexity.
*/

/*  EXAMPLE:

    Input: 
        1
       / \
      2   3
     / \  /
    4  5 6

    Output: 6
*/

/*  APPROACH: Recursion
    1. If the tree is empty, return 0 as the number of nodes.
    2. Recursively traverse through each branch of the complete binary tree and calculate the number of nodes in each branch. 
    3. Add 1 to the number of nodes found in the left and right branches to account for the root node and return this value as the total number of nodes in the complete binary tree.
*/

// SOLUTION:
#include <bits/stdc++.h>

using namespace std;

// Tree definition
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
public:
    int countNodes(TreeNode* root) {
        // Recursively calculate the number of nodes in each branch
        return (root == NULL) ? 0 : (1 + countNodes(root->left) + countNodes(root->right));
    }
};