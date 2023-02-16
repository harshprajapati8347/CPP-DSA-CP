// Given the head of a singly linked list, reverse the list, and return the reversed list.
// Input : head = [ 1, 2, 3, 4, 5 ] 
// Output : [5, 4, 3, 2, 1]

// 2 Methods -> Iterative & Recursive

#include<iostream>
using namespace std;

//! 1. Iterative
// class Solution
// {
// public:
//     ListNode *reverseList(ListNode *head)
//     {
//         ListNode *prev = NULL;
//         ListNode *curr = head;
//         ListNode *next = NULL;
//         while (curr != NULL)
//         {
//             next = curr->next;
//             curr->next = prev;
//             prev = curr;
//             curr = next;
//         }
//         return prev;
//     }
// };

//! 2. Recursive
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        // Base Case
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *newHead = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return newHead;
    }
};
