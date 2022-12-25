// 234. Palindrome Linked List
// Given the head of a singly linked list, return true if it is a palindrome or false otherwise.
// Input: head = [1,2,2,1]
// Output: true

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
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    bool isPalindrome(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast != NULL && fast->next != NULL) // find the middle node
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        if (fast != NULL)
        {
            slow = slow->next;
        }
        slow = reverse(slow);
        fast = head;
        while (slow != NULL)
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