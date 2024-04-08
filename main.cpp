/*
 * MAIN.CPP
 *
 *   DRIVER / TEST UNIT
 *
 *     Given the head of a sorted linked list, delete all duplicates such that each element appears only
 *     once. Return the linked list sorted as well.
 *
 */

#include <iostream>
#include <vector>
#include <algorithm>

#include "solution.h"

// PROTOTYPES
void printResults(ListNode *head);
ListNode *makeList(std::vector<int> &arr);
void printList(ListNode *head);

// DRIVER / TEST UNIT
int main(int argc, char **argv)
{
    // DECLARE AND DEFINE TEST PARAMETERS
    std::vector<std::vector<int>> testUnit {
        {1, 1, 2},
        {1, 1, 2, 3, 3},
        {1, 1, 1},
        {1, 2, 2},
        {1, 2, 2, 3},
        {1, 1, 2, 2, 3, 3},
        {1},
        {},
        {1, 1}
    };

    std::for_each(testUnit.begin(), testUnit.end(), [&](std::vector<int> &testArr) {
        printResults(makeList(testArr));
    });

    return 0;
}


// HELPER FUNCTIONS
void printResults(ListNode *head)
{

    // DECLARE AND PREP SOLUTION CLASS TO USE THE SOLUTION'S FUNCTION
    Solution mySol;

    std::cout << "---------------------------------------------------------\n"
              << "                      TEST UNIT\n"
              << " - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n"
              << " Test List   : ";
    printList(head);
    std::cout << " Result List : ";
    printList(mySol.deleteDuplicates(head));
    std::cout << "---------------------------------------------------------\n";
}

ListNode *makeList(std::vector<int> &arr)
{
    ListNode *newList = new ListNode(),
             *currNode = newList;

    std::for_each(arr.begin(), arr.end(), [&](const int number){
        currNode->next = new ListNode(number);
        currNode = currNode->next;
    });
    return newList->next;
}

void printList(ListNode *head)
{
    ListNode *currNode = head;

    while (currNode != nullptr)
    {
        std::cout << "(" << currNode->val << ")->";
        currNode = currNode->next;
    }
    std::cout << "{nullptr}\n";
}
