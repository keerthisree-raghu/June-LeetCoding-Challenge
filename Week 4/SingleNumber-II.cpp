// SINGLE NUMBER II

/*  PROBLEM:
    Given a non-empty array of integers, every element appears three times 
    except for one, which appears exactly once. Find that single one.

    Note:
    Your algorithm should have a linear runtime complexity.
*/

/*  EXAMPLES:

    Input: [2,2,3,2]
    Output: 3

    Input: [0,1,0,1,0,1,99]
    Output: 99
*/

/*  APPROACH: Iterative Mapping - O(n)
    1. Initialize a map to store the value of the element and the number of occurrences of the element in the array as a key-value pair. 
    2. Iterate through the array of elements and store the count of each element in the array. 
    3. Find the element which has count = 1 from the array and return the value of that element. 
*/

// SOLUTION:
#include <bits/stdc++.h>

using namespace std;
 
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> m;
        // Iterate through the vector to store the count of each element in a map
        for(int i = 0; i < nums.size(); i++) {
            if(m.find(nums[i]) != m.end()) {
                m[nums[i]]++;
            }
            else {
                m[nums[i]] = 1;
            }
        }
        // Find the element which occurs only once
        for(int i = 0; i < nums.size(); i++) {
            if(m[nums[i]] == 1) {
                // Return the value of the element
                return nums[i];
            }
        }
        return -1;
    }
};