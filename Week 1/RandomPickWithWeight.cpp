// RANDOM PICK WITH WEIGHT

/*  PROBLEM:
    Given an array w of positive integers, where w[i] describes the weight of index i, 
    write a function pickIndex which randomly picks an index in proportion to its weight.

    Note:
    1 <= w.length <= 10000
    1 <= w[i] <= 10^5
    pickIndex will be called at most 10000 times.
*/

/*  EXAMPLE:

    Input: 
    ["Solution","pickIndex"]
    [[[1]],[]]
    Output: [null,0]

    Input: 
    ["Solution","pickIndex","pickIndex","pickIndex","pickIndex","pickIndex"]
    [[[1,3]],[],[],[],[],[]]
    Output: [null,0,1,1,1,0]

    The input is two lists: the subroutines called and their arguments. 
    Solution's constructor has one argument, the array w. pickIndex has no arguments. 
    Arguments are always wrapped with a list, even if there aren't any.
*/

/*  APPROACH - Binary Search

    Explanation:
    Consider an array of weights: [3, 7, 1, 4].
    Element 0 occurs 3 times.
    Element 1 occurs 7 times.
    Element 2 occurs 1 time.
    Element 3 occurs 4 times.
    [0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 2, 3, 3, 3, 3]

    The total sum of weights is 3 + 7 + 1 + 4 = 15.
    
    So the probability of
    Element 0 is 3 / 15
    Element 1 is 7 / 15
    Element 2 is 1 / 15
    Element 3 is 4 / 15

    We need to generate the probability mass function of each index. 
    Suppose we have an array of 15 equal elements.

    Element 0 occupies index values from 0->2 (3 elements)
    Element 1 occupies index values from 3->9 (7 elements)
    Element 2 occupies index values from 10->10 (1 element)
    Element 3 occupies index values from 11->14 (4 elements)

    To get an index, we generate a random number and take its modulo to 15.
    If the random number is 6, 6 % 15 = 9. 
    Therefore, it is in the range [3-9] so it is mapped back to Element 1. 

    Algorithm:
    1. Store the lower and upper range of each weight according to its occurrence.
    2. Generate a random index value and perform modulus with the total number of elements.
    3. Search through the vector storing ranges using binary search to find the index value.
*/

// SOLUTION:
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Initialize a variable to store the number of elements in the new vector
    int n = 0;
    // Vector to store the range of each element according to its frequency of occurrence
    vector<pair<int, int>> range;
    
    Solution(vector<int>& w) {
        for(int weight: w) {
            // Store the starting and ending range of each weight value
            range.push_back({n, n + weight - 1});
            n += weight;
        }
    }
    
    int pickIndex() {
        // Generate a random index value and perform modulus with the total number of elements in the vector
        int index = rand() % n;
        // Perform binary search to find the index value
        int left = 0, right = range.size() - 1;
        while(left <= right) {
            int mid = (left + right) / 2;
            // Check if the index value falls within a particular range
            if(range[mid].first <= index && range[mid].second >= index) {
                return mid;
            }
            if(range[mid].first > index) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return left;
    }
};
