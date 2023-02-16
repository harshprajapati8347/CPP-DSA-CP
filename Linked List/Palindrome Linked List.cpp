// 234. Palindrome Linked List
// Given the head of a singly linked list, return true if it is a palindrome or false otherwise.
// Input: head = [1,2,2,1]
// Output: true

//! Algorithm:
// 1. Find the middle node of the linked list.
// 2. Reverse the second half of the linked list.
// 3. Compare the first half and the second half of the linked list.
// 4. Restore the linked list.
// 5. Return the result.

#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *reverse(ListNode *head)
    {
        ListNode *prev = NULL;
        ListNode *curr = head;
        while (curr != NULL)
        {
            ListNode *next = curr->next; // store the next node
            curr->next = prev;          // reverse the current node
            prev = curr;               // move the prev pointer
            curr = next;          // move the curr pointer
        }
        return prev;
    }
    bool isPalindrome(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        // find the middle node
        while (fast != NULL && fast->next != NULL) 
        {
            slow = slow->next;
            fast = fast->next->next;
        } 
        // slow is the middle node
        if (fast != NULL) // for odd number of nodes
        {
            slow = slow->next; // skip the middle node
        }
        slow = reverse(slow); // reverse the second half
        fast = head; // reset the fast pointer to head
        while (slow != NULL) // compare the first half and the second half
        {
            if (slow->val != fast->val)
            {
                return false;
            }
            slow = slow->next;
            fast = fast->next;
        }
        return true;
    }
};

int main()
{
    Solution s;
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);
    cout << s.isPalindrome(head);

    return 0;
}