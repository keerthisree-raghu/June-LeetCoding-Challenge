// SEARCH INSERT POSITION

/*  PROBLEM:
    Given a sorted array and a target value, return the index if the target is found. 
    If not, return the index where it would be if it were inserted in order.
    You may assume no duplicates in the array.
*/

/*  EXAMPLES:

    Input: [1,3,5,6], 5
    Output: 2

    Input: [1,3,5,6], 2
    Output: 1

    Input: [1,3,5,6], 7
    Output: 4

    Input: [1,3,5,6], 0
    Output: 0
*/

/*  APPROACH: Binary Search - O(logn)
    1. Initialize two pointer variables to point to the extreme ends of the array.
    2. Iterate until the condition (left <= right) breaks.
    3. Calculate the mid value such that overflow is avoided.
    4. If the target is found in the array, return the index value.
    5. If the target is greater than the mid value, the searching proceeds in the right half of the array.
    6. If the target is less than the mid value, the searching proceeds in the left half of the array.
    7. If the code exits the loop
        a. This means that left >= right + 1.
        b. But, the target index is between [left, right + 1], so left <= right.
        c. From a and b, left = right + 1.
        So the index to be returned is at [left, left]->left or [right + 1, right + 1]->right + 1.
*/

// SOLUTION:
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while(left <= right) {
            // Calculate mid value
            // Conventional (left + right) / 2 may cause overflow
            int mid = left + (right - left) / 2;
            
            // Return index value if the target is found in the array
            if(nums[mid] == target) {
                return mid;
            }
            // The target is in the right half of the array
            else if(nums[mid] < target) {
                left = mid + 1;
            }
            // The target is in the left half of the array
            else {
                right = mid - 1;
            }
        }
        // [1] When the code reaches this point, left >= right + 1
        // [2] Since the target index is between [left, right + 1], so left <= right + 1
        // [3] From [1] and [2], left = right + 1, so we can return left as the index value
        return left; 
    }
};