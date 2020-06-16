// TWO CITY SCHEDULING

/*  PROBLEM:
    There are 2N people a company is planning to interview. The cost of flying the 
    i-th person to city A is costs[i][0], and the cost of flying the i-th person 
    to city B is costs[i][1].

    Return the minimum cost to fly every person to a city such that exactly N people 
    arrive in each city.

    Note:
    1 <= costs.length <= 100
    It is guaranteed that costs.length is even.
    1 <= costs[i][0], costs[i][1] <= 1000
*/

/*  EXAMPLE:

    Input: [[10,20],[30,200],[400,50],[30,20]]
    Output: 110
    Explanation: 
    The first person goes to city A for a cost of 10.
    The second person goes to city A for a cost of 30.
    The third person goes to city B for a cost of 50.
    The fourth person goes to city B for a cost of 20.

    The total minimum cost is 10 + 30 + 50 + 20 = 110 to have half the people interviewing in each city.
*/

/*  APPROACH - O(nlogn)
    1. Calculate the cost of sending every person to City A and store it in a variable.
    2. Calculate the difference between sending a person to City B instead of City A, and store it in an array.
    3. Sort the values in the array. The smaller the difference value, the greater the profit earned by sending them to City B.
    4. Choose the first N people from the array (the ones having lowest difference value) and send them to City B.
    5. Add the difference of the cost of sending people to City B instead of City A to the original total cost.
*/

// SOLUTION:
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        // A vector stores the difference between sending a person to City B instead of City A
        vector<int> refund;
        // Total number of people = 2N
        int N = costs.size() / 2;
        // minCost tracks the minimum total cost of sending people to each city
        int minCost = 0;
        
        for(vector<int> cost: costs) {
            // Accumulate the cost of sending each person to City A
            minCost += cost[0];
            // Store the value of the difference between sending a person to City B instead of City A as the refund
            refund.push_back(cost[1] - cost[0]);
        }
        
        // Sort the refund vector in ascending order
        sort(refund.begin(), refund.end());
        
        // Add the refund value for n people with the minimum cost acquired
        for(int i = 0; i < N; i++) {
            minCost += refund[i];
        }
        
        // Return the minimum possible cost for sending each person to their respective cities
        return minCost;
    }
};
