// SUM ROOT TO LEAF NUMBERS

/*  PROBLEM:
    Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.
    An example is the root-to-leaf path 1->2->3 which represents the number 123.
    Find the total sum of all root-to-leaf numbers.

    Note:
    A leaf is a node with no children.
*/

/*  EXAMPLES:

    Input: [1,2,3]
        1
       / \
      2   3
    Output: 25
    Explanation:
    The root-to-leaf path 1->2 represents the number 12.
    The root-to-leaf path 1->3 represents the number 13.
    Therefore, sum = 12 + 13 = 25.


    Input: [4,9,0,5,1]
        4
       / \
      9   0
     / \
    5   1
    Output: 1026
    Explanation:
    The root-to-leaf path 4->9->5 represents the number 495.
    The root-to-leaf path 4->9->1 represents the number 491.
    The root-to-leaf path 4->0 represents the number 40.
    Therefore, sum = 495 + 491 + 40 = 1026.
*/

/*  APPROACH: Depth-First-Search
    1. Traverse through each branch of the tree and iteratively construct the number that it forms until the branch ends.
    2. If the branch ends, add the value to the cumulative sum, stored in a global variable.
    3. If the tree reaches the last leaf node, stop the process and return the sum value.
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
private:
    int sum = 0;
    // DFS Helper Function
    void DFS(TreeNode *&node, int currentSum) {
        // Tree is empty
        if(!node) {
            return;
        }
        // Construct the number from the node elements of each branch
        currentSum = (currentSum * 10) + node->val;
        // If the branch ends, add the value to the cumulative sum
        if(!node->left && !node->right) {
            sum += currentSum;
        }
        // Traverse the left branch
        if(node->left) {
            DFS(node->left, currentSum);
        }
        // Traverse the right branch
        if(node->right) {
            DFS(node->right, currentSum);
        }
    }
public:
    int sumNumbers(TreeNode* root) {
        // Begin the DFS traversal at the root node with an initial sum value of 0
        DFS(root, 0);
        return sum;
    }
};