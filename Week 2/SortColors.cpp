// SORT COLORS

/*  PROBLEM:
    Given an array with n objects colored red, white or blue, sort them in-place so that objects 
    of the same color are adjacent, with the colors in the order red, white and blue. Here, we 
    will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

    Note: 
    You are not suppose to use the library's sort function for this problem.
*/

/*  EXAMPLE:

    Input: [2,0,2,1,1,0]
    Output: [0,0,1,1,2,2]
*/

/*  APPROACH: Counting Sort - O(n+k)
    1. Initialize a counter array to store the count of each element and an output array to store the sorted elements.
    2. Iterate through the original array and increment the count of each encountered element, while unseen element remain 0.
    3. Change the count array to reflect the actual index of each element in the sorted array by adding the count of the previous element.
    4. Build the output array by iterating through the length of the count array.
        a. Store each element in the output array at the index determined by the index value of the element in the count array.
        b. Decrement the count array.
    5. Copy the output array to the original array.
*/

// SOLUTION:
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int len = nums.size();
        int output[len], count[1000] = {0};
        // Accumulate count of each element
        for(int i = 0; i < len; i++) {
            count[nums[i]]++;
        }
        // Change count[i] such that it contains the actual index of each element in the sorted array
        for(int i = 1; i < 1000; i++) {
            count[i] += count[i-1];
        }
        // Build the output array using the index value from the count array and element value from the nums array
        for(int i = 0; i < len; i++) {
            output[count[nums[i]] - 1] = nums[i];
            count[nums[i]]--;
        }
        // Copy the output array to the original array
        for(int i = 0; i < len; i++) {
            nums[i] = output[i];
        }
    }
};