// LONGEST DUPLICATE SUBSTRING

/*  PROBLEM:
    Given a string S, consider all duplicated substrings: (contiguous) substrings of S that occur 2 or more times. (The occurrences may overlap.)
    Return any duplicated substring that has the longest possible length.  (If S does not have a duplicated substring, the answer is "".)

    Note:
    2 <= S.length <= 10^5
    S consists of lowercase English letters.
*/

/*  EXAMPLES:

    Input: "banana"
    Output: "ana"

    Input: "abcd"
    Output: "" 
*/

/*  APPROACH: Rabin Karp Algorithm - O(n + m)
    Longest Duplicate Substring:
    1. Pre-compute the required powers of 26 modulus a prime number for the purpose of calculating with single precision arithmetic.
    2. During each iteration, check if the substring with length mid is found in the original string using the rabin_karp() helper function.
    3. Perform binary search to check if there is a longer substring which is duplicated in the original string.
    
    Rabin-Karp Helper Function:
    1. Compute the hash value for the first "length" characters.
    2. Store the hash value in a vector.
    3. Using a sliding window, matain the hash values of previous substrings to be able to reuse them in subsequent iterations.
    4. Compare the hash value of the substring to match with the hash value of the window in the original string.
        a. If the hash values match, do a character-by-character comparison to check if the substrings match.
        b. If a match does not exist in that window, add the hash value to the map.
    5. Return the longest substring that matches, or an empty string if no substring matches.
*/

// SOLUTION:
#include <bits/stdc++.h>

using namespace std;
 
class Solution {
public:
    string longestDupSubstring(string S) {
        string res = "";
        int len = S.length();
        power = vector<int>(len, 1);
		// For the hash calculation, pre-compute pow(26, k) where 0 < k < S.length() modulus prime
        for (int i = 1 ; i < len; i++) {
            power[i] = (power[i - 1] * 26) % prime;
        }
        // Use binary search to find the largest possible length of a duplicate substring
        int left = 0, right = len;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            string curr = rabin_karp(mid, S);
            if (curr.length() == 0) {
                right = mid - 1;
            } 
            else {
                if (curr.length() > res.length()) {
                    res = curr;
                }
                else {
                    left = mid + 1;
                }
            }
        }
        return res;
    }

private:
    int prime = 19260817;
    string res;
    vector<int> power;
    
    string rabin_karp(int reqLen, string &str) {
        // If the required length is 0, return the empty string
        if (reqLen == 0) {
            return "";
        }
        unordered_map<int, vector<int>> hash = unordered_map<int, vector<int>>();
        long long current = 0;
		// Compute the hash value of the first "length" characters
        for (int i = 0 ; i < reqLen; i++) {
            current = ((current * 26) % prime + (str[i] - 'a')) % prime;
        }
        // Store the result in a hashmap that maps from the hash value to starting index
        hash[current] = vector<int>(1, 0);
        for (int i = reqLen ; i < str.length(); i++) {
		    // Use a sliding window to maintain the hash value of the current substring
            current = ((current - (long long) power[reqLen - 1] * (str[i - reqLen] - 'a')) % prime + prime) % prime;
            current = (current * 26 + (str[i] - 'a')) % prime;
            // If the hash value does not exist already, add it to the map
            if (hash.find(current) == hash.end()) {
                hash[current] = vector<int>(1, i - reqLen + 1);
            } 
            else {
			    // Compare each character to check for a match
                for (auto itr : hash[current]) {
                    if (strcmp((str.substr(itr, reqLen)).data(), str.substr(i - reqLen + 1, reqLen).data()) == 0) {
                        return str.substr(itr, reqLen);
                    }
                }
                // If no match is found, add the hash value to the map
                hash[current].push_back(i - reqLen + 1);
            }
        }
        return "";
    }
};