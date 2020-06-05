// REVERSE STRING

/*  PROBLEM:
    Write a function that reverses a string. The input string is given as an array of characters char[].
    Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
    You may assume all the characters consist of printable ascii characters.
*/

/*  EXAMPLES:

    Input: ["h","e","l","l","o"]
    Output: ["o","l","l","e","h"]

    Input: ["H","a","n","n","a","h"]
    Output: ["h","a","n","n","a","H"]
*/

/*  APPROACH - O(1) Space Complexity
    1. Calculate the length of the array and store it in a variable.
    2. Initialize two pointers to point to the extreme ends of the array,
    3. Traverse the array and swap the elements at the left and right position, using a temporary variable.
    4. When the left and right pointer becomes equal or breaks the condition (left < right), stop.
*/

// SOLUTION:
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        // Store the size of the vector in a variable
        int len = s.size();
        // Initialize a left and right pointer to point to the extreme ends of the vector
        int left = 0, right = len - 1;
        // Declare a temporary variable to store the characters to be swapped in each iteration
        char temp;
        
        // End the loop when the condition (left < right) breaks
        while(left < right) {
            // Swap the letters in the left and right positions
            temp = s[left];
            s[left] = s[right];
            s[right] = temp;
            // Increment the left pointer and decrement the right pointer
            left++;
            right--;
        }
    }
};