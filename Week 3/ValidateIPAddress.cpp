// VALIDATE IP ADDRESS

/*  PROBLEM:
    Write a function to check whether an input string is a valid IPv4 address or IPv6 address or neither.

    Note: 
    You may assume there is no extra space or special characters in the input string.
*/

/*  EXAMPLE:

    Input: "172.16.254.1"
    Output: "IPv4"
    Explanation: This is a valid IPv4 address, return "IPv4".

    Input: "2001:0db8:85a3:0:0:8A2E:0370:7334"
    Output: "IPv6"
    Explanation: This is a valid IPv6 address, return "IPv6". 

    Input: "256.256.256.256"
    Output: "Neither"
    Explanation: This is neither a IPv4 address nor a IPv6 address.
*/

/*  APPROACH: Regular Expression - O(1) 
    IPv4: "(([0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])\\.){3}([0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])"
    IPv6: "((([0-9a-fA-F]){1,4})\\:){7}([0-9a-fA-F]){1,4}"
*/

// SOLUTION:
#include <bits/stdc++.h>

using namespace std;
 
class Solution {
public:
    string validIPAddress(string IP) {
        regex ipv4("(([0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])\\.){3}([0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])");
        regex ipv6("((([0-9a-fA-F]){1,4})\\:){7}([0-9a-fA-F]){1,4}"); 
        if(regex_match(IP, ipv4))
            return "IPv4";
        else if(regex_match(IP, ipv6)) 
            return "IPv6";
        return "Neither"; 
    }
};