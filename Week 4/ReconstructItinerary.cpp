// RECONSTRUCT ITINERARY

/*  PROBLEM:
    Given a list of airline tickets represented by pairs of departure and arrival airports [from, to], reconstruct the 
    itinerary in order. All of the tickets belong to a man who departs from JFK. Thus, the itinerary must begin with JFK.

    Note:
    1. If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string. For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
    2. All airports are represented by three capital letters (IATA code).
    3. You may assume all tickets form at least one valid itinerary.
    4. One must use all the tickets once and only once.
*/

/*  EXAMPLES:
 
    Input: [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
    Output: ["JFK", "MUC", "LHR", "SFO", "SJC"]

    Input: [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
    Output: ["JFK","ATL","JFK","SFO","ATL","SFO"]
    Explanation: Another possible reconstruction is ["JFK","SFO","ATL","JFK","ATL","SFO"].
                But it is larger in lexical order.
*/

/*  APPROACH: Depth-First-Search
    1. Declare a global map variable which contains a string and priority queue as the key-value pair to store the information about the airports.
    2. Declare a global string vector variable to store the resultant itinerary.
    Find Itinerary Function:
    1. Using a min-heap, store the names of the airports in lexicographical order.
    2. Begin the DFS process from "JFK" since that is the starting point.
    DFS Helper Function:
    1. Pop the airports from the priority queue one-by-one.
    2. When each new airport is popped, perform DFS.
    3. When the priority queue is empty, add the airport names to the resultant vector and return it.
*/

// SOLUTION:
#include <bits/stdc++.h>

using namespace std;
 
class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // Store the airport names in lexicographical order
        for(auto ticket : tickets) {
            airports[ticket[0]].push(ticket[1]);
        }
        // Begin the DFS from "JFK"
        DFS("JFK");
        return itinerary;
    }
private:
    // Min-heap to store airports in lexicographical order
    map<string, priority_queue<string, vector<string>, greater<string>>> airports;
    // String vector to store the final itinerary
    vector<string> itinerary;
    // DFS Helper Function
    void DFS(string source) {
        // Pop the airports from the priority queue
        while(!airports[source].empty()) {
            string top = airports[source].top();
            airports[source].pop();
            // Peform DFS from each new airport
            DFS(top);
        }
        // At this point, the priority queue is empty
        // Add all of the airports to the resultant vector
        itinerary.insert(itinerary.begin(), source);
    }
};