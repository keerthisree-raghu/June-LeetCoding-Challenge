// PERMUTATION SEQUENCE

/*  PROBLEM:
    The set [1,2,3,...,n] contains a total of n! unique permutations.
    By listing and labelling all of the permutations in order, we get the following sequence for n = 3:
    1. "123"
    2. "132"
    3. "213"
    4. "231"
    5. "312"
    6. "321"
    Given n and k, return the kth permutation sequence.

    Note:
    Given n will be between 1 and 9 inclusive.
    Given k will be between 1 and n! inclusive.
*/

/*  EXAMPLES:

    Input: n = 3, k = 3
    Output: "213"

    Input: n = 4, k = 9
    Output: "2314"
*/

/*  APPROACH: Iterative Math
    1. Calculate the factorials of each number from 1 to 9 and store it in an array.
    2. Store all of the available characters within the given range in a character array by adding '0' to each number.
    3. Create an empty result string.
    4. Calculate the k value considering the possibility of k > (n-1)! and therefore taking modulus with factorial[n] to prevent this.
    5. Iteratively determine which elements must be in the sequence
        a. Find the position of the character to add.
        b. Append the character to the resultant string.
        c. Remove the element which has already been considered.
        d. Find the new k value for the next iteration.
    6. When the value of n = 0, return the resultant string. 
*/

// SOLUTION:
#include <bits/stdc++.h>

using namespace std;
 
class Solution {
public:
    string getPermutation(int n, int k) {
        // Calculate the factorials between 1 and 9
        int factorials[10] = {1};
        for(int i = 1; i < 10; i++) {
            factorials[i] = i * factorials[i-1];
        } 
        
        // Store the available characters
        vector<char> nums;
        for(int i = 0; i < n; i++) {
            // Array index starts at 0, Element value starts from 1
            nums.push_back('0' + i + 1);
        }
        
        string res = "";
        // Calculate k value
        int k_val = (k-1) % factorials[n];
        while(n) {
            // Find the position of the character to add
            int pos = k_val / factorials[n-1];
            // Append the character to the resultant string
            res += nums[pos];
            // Remove the elements that have already been considered
            nums.erase(nums.begin() + pos);
            // Find the new k value
            k_val %= factorials[n-1];
            // Exit when n = 0
            n--;
        }
        return res;
    }
};