// H-Index II

/*  PROBLEM:
    Given an array of citations sorted in ascending order (each citation is a non-negative 
    integer) of a researcher, write a function to compute the researcher's h-index.

    Note:
    If there are several possible values for h, the maximum one is taken as the h-index.
*/

/*  EXAMPLE:

    Input: citations = [0,1,3,5,6]
    Output: 3 
    Explanation: 
    [0,1,3,5,6] means the researcher has 5 papers in total and each of them had 
    received 0, 1, 3, 5, 6 citations respectively. 
    Since the researcher has 3 papers with at least 3 citations each and the remaining 
    two with no more than 3 citations each, her h-index is 3.  
*/

/*  APPROACH: Binary Search - O(logn)
    1. Initialize the high and low pointers to point to the extreme ends of the sorted array.
    2. Calculate the mid-value.
    3. Check if the condition to find the h-index is satisfied by the mid element:
       citations[index] >= length(citations) - index
    4. Store the value of the remaining elements in a variable and continue the process to find the optimum value.
    5. When the first optimal value that satisfies the condition is found, return the value.
*/

// SOLUTION:
#include <bits/stdc++.h>

using namespace std;
 
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int len = citations.size();
        int low = 0;
        int high = len - 1;
        int h_index = 0;
        if(len == 0) 
            return 0;
        while(low <= high) {
            int mid = low + ((high - low) / 2);
            // Condition to find the h-index: 
            // citations[index] >= length(citations) - index
            if(citations[mid] >= len - mid) {
                h_index = len - mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return h_index;
    }
};