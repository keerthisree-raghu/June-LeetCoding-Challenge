// LARGEST DIVISIBLE SUBSET

/*  PROBLEM:
    Given a set of distinct positive integers, find the largest subset 
    such that every pair (Si, Sj) of elements in this subset satisfies:

    Si % Sj = 0 or Sj % Si = 0.

    If there are multiple solutions, returning any subset is fine.
*/

/*  EXAMPLES:

    Input: [1,2,3]
    Output: [1,2] (of course, [1,3] will also be ok)

    Input: [1,2,4,8]
    Output: [1,2,4,8]
*/

/*  APPROACH: Dynamic Programming
    1. Calculate the size of the input array and check if it is empty.
    2. Sort the array in ascending order such that we only have to compare the value of nums[j] % nums[i] and not nums[i] % nums[j].
    3. Create a vector to the build the dp table with the length of the longest subset.
    4. Create a vector to store and track the indices of previous elements in a subset such that when we build a bigger subset, we can include those elements.
    5. Iterate through the input array such that j < i < n and add nums[i] to the subset if and only if:
        a. nums[i] % nums[j] == 0
        b. If nums[i] is added to the subset which ends with nums[j], the length of the new subset is greater than the current subset.
    6. Keep track of the previous indices in each iteration and the maximum index value.
    7. Create a resultant vector to build the longest subset using the maximum index value and previous indices.
*/

// SOLUTION:
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int size = nums.size();
        
        if(size == 0) {
            return {};
        }
        
        // Sort the input vector such that i < j, so that we only have to compare nums[j] % nums[i]
        sort(nums.begin(), nums.end());
        
        // Create a vector to store the length of the longest substring
        // The initial length of any subset is 1
        vector<int> dp(size, 1);
        
        // Create a vector to store the indices of previously included elements in a subset which is being expanded
        vector<int> previous(size, -1);
        
        // Create a variable to keep track of the index of the longest substring
        int max = 0;
        
        // Iterate through the array elements such that j < i < n
        for(int i = 1; i < size; i++) {
            for(int j = 0; j < i; j++) {
                // If nums[i] % nums[j] = 0 and if the length of the subset ending with nums[j] becomes greater than the existing subset after adding nums[i]
                // We can add nums[i] to a subset with the last element being nums[j]
                if(nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    // Keep track of previous indices of i
                    previous[i] = j;
                }
            }
            // Update the maximum index value
            if(dp[i] > dp[max]) {
                max = i;
            }
        }
        // Use a resultant vector to build the final subset
        vector<int> result;
        int index = max;
        while(index >= 0) {
            result.push_back(nums[index]);
            index = previous[index];
        }
        return result;
    }
};