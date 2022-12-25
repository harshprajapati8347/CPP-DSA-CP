// 148. Sort List
// Given the head of a linked list, return the list after sorting it in ascending order.
// Input: head = [-1,5,3,4,0]
// Output: [-1,0,3,4,5]
// TC: O(nlogn)
// SC: O(1)

//! Algorithm:
// 1. Find the middle of the linked list using slow and fast pointer.
// 2. Split the linked list into two halves.
// 3. Recursively sort the two halves.
// 4. Merge the two sorted halves.

#include<iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode* sortList(ListNode* head)
    {
        if (head == NULL || head->next == NULL)  // Base case  
            return head;
        
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *prev = NULL;
        
        while (fast != NULL && fast->next != NULL)  // Find the middle of the linked list
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        prev->next = NULL; // Split the linked list into two halves
        
        // Recursively sort the two halves
        ListNode *left = sortList(head);
        ListNode *right = sortList(slow); 
        
        return merge(left, right); // Merge the two sorted halves
    }
    
    ListNode* merge(ListNode *left, ListNode *right)
    {
        ListNode *result = NULL; // Base case
        
        if (left == NULL)
            return right;
        else if (right == NULL)
            return left;
        
        if (left->val <= right->val) // Pick either left or right and recur
        {
            result = left;
            result->next = merge(left->next, right);
        }
        else
        {
            result = right;
            result->next = merge(left, right->next);
        }        
        return result;
    }
};


int main()
{
    Solution s;
    ListNode *head = new ListNode();
    head->val = 4;
    head->next = new ListNode();
    head->next->val = 2;
    head->next->next = new ListNode();
    head->next->next->val = 1;
    head->next->next->next = new ListNode();
    head->next->next->next->val = 3;
    head->next->next->next->next = NULL;

    ListNode *result = s.sortList(head);
    while (result != NULL)
    {
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl;
    return 0;
}