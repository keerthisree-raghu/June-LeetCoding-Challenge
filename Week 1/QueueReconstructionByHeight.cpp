// QUEUE RECONSTRUCTION BY HEIGHT

/*  PROBLEM:
    Suppose you have a random list of people standing in a queue. Each person is described 
    by a pair of integers (h, k), where h is the height of the person and k is the number of 
    people in front of this person who have a height greater than or equal to h. Write an 
    algorithm to reconstruct the queue.

    Note:
    The number of people is less than 1,100.
*/ 

/*  EXAMPLE:

    Input:
    [[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]

    Output:
    [[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]
*/

/*  APPROACH: Insertion Sort - O(n^2)
    1. Initialize an empty vector to insert each person.
    2. Compare each person such that
        a. If they do not have the same height (h) value, they should be sorted in descending order.
        b. If they have the same height (h) value, sort them in ascending order of the number of people in front of them (k).
    3. Insert each person into position k. 
*/

// SOLUTION:
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static bool compare(vector<int>& v1, vector<int>& v2) {
        // Check if the two h values are different
        // Check if the people have been sorted in ascending order of h value
        if(v1[0] != v2[0]) {
            return v1[0] > v2[0];
        }
        // If the h values are the same, compare the k values and sort in descending order
        else {
            return v1[1] < v2[1];
        }
    }
    
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        // Sort the vector of people 
        sort(people.begin(), people.end(), compare);
        // Initialize a resultant vector
        vector<vector<int>> res;
        int n = people.size();
        // Insert each person into position k
        for(int i = 0; i < n; i++) {
            res.insert(res.begin() + people[i][1], people[i]);
        }
        return res;
    }
};