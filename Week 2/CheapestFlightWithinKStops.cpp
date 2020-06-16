// CHEAPEST FLIGHT WITHIN K STOPS

/*  PROBLEM:
    There are n cities connected by m flights. Each flight starts from city u and arrives at v with a price w.

    Now given all the cities and flights, together with starting city src and the destination dst, your task 
    is to find the cheapest price from src to dst with up to k stops. If there is no such route, output -1.

    Constraints:
    1. The number of nodes n will be in range [1, 100], with nodes labeled from 0 to n - 1.
    2. The size of flights will be in range [0, n * (n - 1) / 2].
    3. The format of each flight will be (src, dst, price).
    4. The price of each flight will be in the range [1, 10000].
    5. k is in the range of [0, n - 1].
    6. There will not be any duplicated flights or self cycles.
*/

/*  EXAMPLES:

    Input: 
    n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
    src = 0, dst = 2, k = 1
    Output: 200

    Input: 
    n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
    src = 0, dst = 2, k = 0
    Output: 500
*/

/*  APPROACH: Dijkstra's Algorithm - O(n^2logn)
    1. Initialize a mapping which stores the flight information as: 
        a. <source city, <destination city, price>>
    2. Initialize a min priority queue with with each object being an integer array holding values:
        a. Current total price
        b. Current source city
        c. Maximum allowed hops to destination
       The priority queue compares each object with the total price so far.
    3. Add the original source city to the priority queue and set the price to 0 and the number of hops allowed to k + 1.
    4. While there are cities remaining to be traversed,
        a. Indentify and remove the minimum object from the priority queue.
        b. Get the current total price, the current source city, and the number of hops to the destination allowed from the minimum object.
    5. Check if the current source is equal to the destination and the number of stops made is less than k.
        a. If the destination has been reached and the conditions are satisfied, return the distance value.
        b. If the destination has not been reached, find all the connected flights that fly from the current source. 
           Calculate the new price, identify the current source, find the new distance, and add these values to the priority queue.
    6. If there are no cities remaining to be traversed or no flights that satisfy the conditions, return -1.
*/

// SOLUTION:
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        // mapping -> <source city, <destination city, price>>
        vector<vector<pair<int, int>>> price_map(n);
        for(vector<int>& f : flights) {
            price_map[f[0]].push_back({f[1], f[2]});
        }
        // priority queue -> <current total price , <current source city, maximum allowed distance to destination>>
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        // Add source city to the priority queue with price 0, and allowed distance as k + 1
        // Number of stops = k -> Number of nodes = k + 1 (including destination)
        pq.push({0, src, K + 1});
        while(!pq.empty()) {
            // Remove min object from the priority queue
            vector<int> top = pq.top();
            pq.pop();
            // Get current total price (distance), current source city, and distance to destination allowed from min object
            int price = top[0];
            int current_src = top[1];
            int hops_allowed = top[2];
            // If the current source is the destination, and the number of hops is less than k, return the distance
            if(dst == current_src) {
                return price;
            }
            // If the destination has not been reached, check if more hops are allowed
            if(hops_allowed > 0) {
                // Find all the connected flights that fly from the current source
                for(pair<int, int>& v : price_map[current_src])
                    // Calculate the new price, new source, and new hops allowed and push it into the priority queue
                    pq.push({price + v.second, v.first, hops_allowed - 1});
            }
        }
        // If no cities are left and there are no routes that satisfy the conditions, return -1
        return -1;
    }
};