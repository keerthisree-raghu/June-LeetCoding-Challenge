// INSERT DELETE GETRANDOM O(1)

/*  PROBLEM:
    Design a data structure that supports all following operations in average O(1) time.

    insert(val): Inserts an item val to the set if not already present.
    remove(val): Removes an item val from the set if present.
    getRandom: Returns a random element from current set of elements. Each element must have the same probability of being returned.
*/

/*  EXAMPLE:

    // Init an empty set.
    RandomizedSet randomSet = new RandomizedSet();

    // Inserts 1 to the set. Returns true as 1 was inserted successfully.
    randomSet.insert(1);

    // Returns false as 2 does not exist in the set.
    randomSet.remove(2);

    // Inserts 2 to the set, returns true. Set now contains [1,2].
    randomSet.insert(2);

    // getRandom should return either 1 or 2 randomly.
    randomSet.getRandom();

    // Removes 1 from the set, returns true. Set now contains [2].
    randomSet.remove(1);

    // 2 was already in the set, so return false.
    randomSet.insert(2);

    // Since 2 is the only number in the set, getRandom always return 2.
    randomSet.getRandom();
*/

/*  APPROACH: O(1)
    Initialize a vector to store all of the elements.
    Initialize a map to track the key and value of every element.

    Insert
    1. Check the array to see if the value to be inserted exists or not.
    2. If the value does not exist, using the emplace() method, insert the value and its position in the map only if it is unique.
    3. Add the value to the array.

    Delete
    1. Check the array to see if the value to be removed exists or not.
    2. If the value exists, obtain the index of the value from the map and store it in a variable.
    3. Move the element to be removed to the back of the array and remove it from the array.
    4. Change the index value in the map to the correct value and remove the value from the map.

    GetRandom
    1. Calculate the index of the element to return by performing taking a random number and performing modulus with the size of the array.
       (This is to prevent the index from going out of bounds.)
    2. Access the element at the calculated index from the vector.
*/

// SOLUTION:
#include <bits/stdc++.h>

using namespace std;

class RandomizedSet {
private:
    vector<int> arr;
    unordered_map<int, int> map;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        // The iterator finds the value before reaching the end of the map
        if(map.find(val) != map.end()) {
            return false;
        }
        // Insert a value into the map only if it is unique
        map.emplace(val, arr.size());
        // Insert this value into the array
        arr.push_back(val);
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        // The iterator does not find the value before reaching the end of the map
        if(map.find(val) == map.end()) {
            return false;
        }
        // Initialize an index to store the position of the value
        int index = map[val];
        
        // Moving the element to be removed to the back of the array
        arr[index] = arr.back();
        // Removing the last element in the array
        arr.pop_back();
        
        // Change the value in the map to the correct index value
        map[arr[index]] = index;
        // Remove the value from the map
        map.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        // Calculate the index of the random element and return it
        int index = rand() % arr.size();
        return arr[index];
    }
};
