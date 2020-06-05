// DELETE NODE IN LINKED LIST

/*  PROBLEM:
    Write a function to delete a node (except the tail) in a singly linked list, given only access to that node.
    
    Note:
    The linked list will have at least two elements.
    All of the nodes' values will be unique.
    The given node will not be the tail and it will always be a valid node of the linked list.
    Do not return anything from your function.
*/ 

/*  EXAMPLES:

    Input: head = [4,5,1,9], node = 5
    Output: [4,1,9]
    Explanation: You are given the second node with value 5, the linked list should become 4 -> 1 -> 9 after calling your function.

    Input: head = [4,5,1,9], node = 1
    Output: [4,5,9]
    Explanation: You are given the third node with value 1, the linked list should become 4 -> 5 -> 9 after calling your function.
*/

/*  APPROACH - O(1)
    Conventionally, we would modify the pointer of the node before the node to be deleted.
    However, since we do not have access to the node before the given node, we cannot modify
    pointer of the previous node. 
    
    Instead, we can follow this procedure:
    1. Replace the value of the node to be deleted with the value of the node next to it.
    2. Set the pointer of the node to be deleted to the node next to its adjacent node.

    Now, the node next to the original node to be deleted can be deleted instead, causing the
    same effect of deleting the given node.
*/

// SOLUTION:
#include <bits/stdc++.h>

using namespace std;

// Linked list definition
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        // Copy the value of the current node to the next node.
        node->val = node->next->val;
    
        // Set a pointer from the current node to the node pointed to by the next node
        node->next = node->next->next;
    }
};
