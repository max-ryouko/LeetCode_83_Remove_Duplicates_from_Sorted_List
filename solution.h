/*
 * SOLUTION.H
 *

    Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.



    Example 1:

        Input: head = [1,1,2]
        Output: [1,2]

    Example 2:

        Input: head = [1,1,2,3,3]
        Output: [1,2,3]



    Constraints:

        The number of nodes in the list is in the range [0, 300].
        -100 <= Node.val <= 100
        The list is guaranteed to be sorted in ascending order.

 */

#ifndef SOLUTION_H
#define SOLUTION_H

// Definition for singly-linked list.
 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {

        // IF LIST IS EMPTY ~ O(1) time complx
        if (head == nullptr) return head;

        // CREATE ITERATOR POINTER AND TEMP "LAST" NODE ~ O(n) time complx
        ListNode *currNode = head->next,    // goto next node
                 *lastNode = head;          // make beginning node

        // ITERATE THROUGH LIST AND FIND DUPLICATES, UNLINK AND DELETE DUPLICATE
        while (currNode != nullptr)
        {
            if (lastNode->val == currNode->val)
            {
                ListNode *temp = currNode;
                lastNode->next = currNode->next;    // DE--LINK
                currNode = currNode->next;          // INCREMENT
                delete temp;                        // DELETE DUPLICATE

            } else {
                currNode = currNode->next;          // INCREMENT
                lastNode = lastNode->next;          // INCREMENT
            }
        }
        return head;
    }
};


#endif  // SOLUTION_H
