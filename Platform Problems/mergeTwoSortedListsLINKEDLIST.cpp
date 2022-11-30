// You are given the heads of two sorted linked lists list1 and list2.
// Merge the two lists in a one sorted list.The list should be made by splicing together the nodes of the first two lists.
// Return the head of the merged linked list.
// Input : list1 = [ 1, 2, 4 ], list2 = [ 1, 3, 4 ]
// Output : [1, 1, 2, 3, 4, 4]

// Definition for singly-linked list.
// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };
// LEGIT PROGRAM LEETCODE21

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *head = new ListNode();
        ListNode *temp = head;
        while (list1 != NULL && list2 != NULL)
        {
            if (list1->val < list2->val)
            {
                temp->next = list1;
                list1 = list1->next;
            }
            else
            {
                temp->next = list2;
                list2 = list2->next;
            }
            temp = temp->next;
        }
        if (list1 != NULL)
        {
            temp->next = list1;
        }
        if (list2 != NULL)
        {
            temp->next = list2;
        }
        return head->next;
    }
};