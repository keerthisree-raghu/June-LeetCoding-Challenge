// SEARCH IN A BINARY SEARCH TREE

/*  PROBLEM:
    Given the root node of a binary search tree (BST) and a value. You need to find 
    the node in the BST that the node's value equals the given value. Return the 
    subtree rooted with that node. If such node doesn't exist, you should return NULL.
*/

/*  EXAMPLES:

    Input:
            4
           / \
          2   7
         / \
        1   3
        
    Value to Search: 2
    Output:
         2     
        / \   
       1   3

    Input:
            4
           / \
          2   7
         / \
        1   3
    Output: []    
*/

/*  APPROACH: Recursive - O(logn)
    1. If the value at the current node being traversed is equal to the given value, then return the reference to that node.
    2. If the value is less than the value of the current node, then it can only be found in the left sub-tree of the BST, so recursively call the function such that it traverses to the left of the current node.
    3. If the value is greater than the value of the current node, then it can only be found in the right sub-tree of the BST, so recursively call the function such that it traverses to the right of the current node.
    4. If the value to be searched is not found, return NULL.
*/

// SOLUTION:
#include <bits/stdc++.h>

using namespace std;

// Definition for a binary tree node.
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
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root) {
            // Check if the value at the current node is equal to the given value
            if(root->val == val) {
            return root;
            }
            // Check left sub-tree
            else if(val < root->val) {
                return searchBST(root->left, val);
            }
            // Check right sub-tree
            else {
                return searchBST(root->right, val);
            }
        }
        return NULL;
    }
};