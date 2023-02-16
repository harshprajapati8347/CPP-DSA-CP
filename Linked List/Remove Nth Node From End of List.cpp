// 19. Remove Nth Node From End of List
// Given the head of a linked list, remove the nth node from the end of the list and return its head.
// Input: head = [1,2,3,4,5], n = 2
// Output: [1,2,3,5]
// Algorithm: Two Pointers
// Time Complexity: O(n)
// Space Complexity: O(1)
// 1. Count the number of nodes in the linked list
// 2. If the node to be deleted is the first node, then head = head->next
// 3. If the node to be deleted is not the first node, then count - n - 1 is the position of the node before the node to be deleted
// 4. temp->next = temp->next->next


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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *temp = head;
        int count = 0;
        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }
        if (count == n)
        {
            head = head->next; // if the node to be deleted is the first node
            return head;
        }
        //! Logic
        temp = head;
        for (int i = 0; i < count - n - 1; i++) // count - n - 1 is the position of the node before the node to be deleted
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        return head;
    }
};

int main()
{
    Solution s;
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    int n = 2;
    ListNode *ans = s.removeNthFromEnd(head, n);
    while (ans != NULL)
    {
        cout << ans->val << " ";
        ans = ans->next;
    }


    return 0;
}
