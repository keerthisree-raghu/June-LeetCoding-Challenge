// UNIQUE BINARY SEARCH TREES

/*  PROBLEM:
    Given n, how many structurally unique BST's (binary search trees) that store values 1... n?
*/

/*  EXAMPLE:

    Input: 3
    Output: 5
    Explanation:
    Given n = 3, there are a total of 5 unique BST's:

        1         3     3      2      1
         \       /     /      / \      \
          3     2     1      1   3      2
         /     /       \                 \
        2     1         2                 3
*/

/*  APPROACH 1: Dynamic Programming - O(n^2)
    1. Create a vector to store the solutions of each sub-problem.
    2. Initialize dp[0] as 1 to account for the first solution with the root being set as 1.
    3. For each node in the tree, compute the number of unique binary search trees that can be formed using this node as the root node, by applying the formula: 
       dp[i] += dp[j-1] * dp[i-j].
*/

// SOLUTION 1:
#include <bits/stdc++.h>

using namespace std;
 
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1, 0);
        // When 1 is set as root, 
        // left subtree = 0 children, right subtree = dp[n - 1] children
        // Set dp[0] = 1
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                // If k is set as the root node,
                // left subtree = (k - 1) children
                // right subtree = (n - k) children
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }
        return dp[n];
    }
};

/*  APPROACH 2: Mathematical - O(n)
    Use the Nth Catalan Number formula to calculate the number of unique binary search trees:
    C(n) = (2n)! / ((n + 1)! * n!)
    Catalan Numbers from 0:
    1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, …
*/

// SOLUTION 2:
#include <bits/stdc++.h>

using namespace std;
 
class Solution {
public:
    int numTrees(int n) {
        long long count = 1;
        for(int i = n + 1; i <= 2 * n; i++) {
            count = count * i / (i - n);
        }
        return count / (n + 1);
    }
};