// FIND THE DUPLICATE NUMBER

/*  PROBLEM:
    Given an array, nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at 
    least one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.

    Note:
    1. You must not modify the array (assume the array is read-only).
    2. You must use only constant, O(1) extra space.
    3. Your runtime complexity should be less than O(n2).
    4. There is only one duplicate number in the array, but it could be repeated more than once.
*/

/*  EXAMPLES:

    Input: [1,3,4,2,2]
    Output: 2

    Input: [3,1,3,4,2]
    Output: 3
*/

/*  APPROACH 1: Hash Map -> Time Complexity - O(n), Space Complexity - O(n)
    1. Initialize an unordered map to store the count of each element.
    2. Traverse through the array.
        a. If the element is already in the map, return that element since it is a duplicate.
        b. If the element is not found, add it to the map.
*/

// SOLUTION 1:
#include <bits/stdc++.h>

using namespace std;
 
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int, int> m;
        for(int i = 0; i < nums.size(); i++) {
            // If the number is already in the map, it is a duplicate
            if(m.find(nums[i]) != m.end()) {
                return nums[i];
            }
            // If the number is not found, add it to the map
            else {
                m[nums[i]]++;
            }
        }
        return -1;
    }
};

/*  APPROACH 2: Sorting -> Time Complexity - O(nlogn), Space Complexity - O(1)
    1. Sort the elements of the array in-place.
    2. If adjacent elements in the array are equal, then duplicates exist. Return the element.
*/

// SOLUTION 2:
#include <bits/stdc++.h>

using namespace std;
 
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // Sort the array - O(1) 
        sort(nums.begin(), nums.end());
        for(int i = 1; i < nums.size(); i++) {
            // If the adjacent numbers are equal, it is the duplicate number
            if(nums[i] == nums[i-1]) {
                return nums[i];
            }
        }
        return -1;
    }
};

/*  APPROACH 3: Cycle Detection -> Time Complexity - O(n), Space Complexity - O(1)
    1. Initialize two pointers, tortoise and hare. The hare pointer would traverse the array twice as fast as the tortoise pointer.
    2. Until the hare and tortoise pointer meet, make the hare pointer advance two elements at a time and the tortoise pointer advance one element at a time.
    3. Reinitialize the hare pointer to 0.
    4. Slow down the speed of the hare pointer such that it advances only one element at a time.
    5. The point at which the hare and tortoise meet in this second traversal is the entry point of the cycle.
    6. Return the entry point of the cycle as the repeated element.
*/

// SOLUTION 3:
#include <bits/stdc++.h>

using namespace std;
 
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int tortoise = nums[0];
        int hare = nums[nums[0]];
        // Phase 1:
        // The hare moves twice as fast as the tortoise
        // Exit the loop when the tortoise and hare meet
        while(tortoise != hare) {
            tortoise = nums[tortoise];
            hare = nums[nums[hare]];
        }
        // Phase 2:
        // Slow down the hare
        // The intersection point of the tortoise and hare is the entry point of the cycle
        hare = 0;
        while(tortoise != hare) {
            hare = nums[hare];
            tortoise = nums[tortoise];
        }
        // Return the intersection point
        return tortoise;
    }
};