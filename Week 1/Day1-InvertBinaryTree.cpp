// INVERT BINARY TREE

/*  PROBLEM: 
    Invert a binary tree.
*/ 

/*  EXAMPLE:

    Input:
         4
       /   \
      2     7
     / \   / \
    1   3 6   9

    Output:
          4
        /   \
       7     2
      / \   / \
     9   6 3   1
*/

/*  APPROACH: Recursive Solution - O(n)
    1. Check if the tree is empty. The inverse of an empty tree is an empty tree.
    2. Recursively traverse down the left and right branches of the tree (depth first).
    3. When leaf nodes have been reached, set the respective left and right pointers to null.
    4. Backtrack through each level and swap each sub-tree.
    5. When the root node has been reached, the process is completed.  
*/

// SOLUTION
#include <bits/stdc++.h>

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
    TreeNode* invertTree(TreeNode* root) {
        // Inverse of an empty tree is an empty tree
        if (root == NULL) {
            return NULL;
        }
        
        // Recursively invert each subtree starting from the root
        TreeNode *right = invertTree(root->right);
        TreeNode *left = invertTree(root->left);
        
        // Exchange the pointers to the left and right nodes
        root->left = right;
        root->right = left;
        
        return root;
    }
};