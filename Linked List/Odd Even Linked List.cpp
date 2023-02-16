// 328. Odd Even Linked List
// Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.

// The first node is considered odd, and the second node is even, and so on.

// Note that the relative order inside both the even and odd groups should remain as it was in the input.

// You must solve the problem in O(1) extra space complexity and O(n) time complexity.

// Input: head = [1,2,3,4,5]
// Output: [1,3,5,2,4]

//! Algorithm:
// 1. Create two pointers odd and even
// 2. Create a new pointer evenHead to store the head of even list
// 3. Traverse the list till even->next != NULL
// 4. odd->next = even->next
// 5. odd = odd->next
// 6. even->next = odd->next
// 7. even = even->next
// 8. odd->next = evenHead
// 9. return head


#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL) // if there is only one node or no node
            return head;

        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = even;
        while(even != NULL && even->next != NULL)
        {
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = evenHead;
        return head;
    }};

int main()
{
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    Solution s;
    ListNode* res = s.oddEvenList(head);
    while(res != NULL)
    {
        cout << res->val << " ";
        res = res->next;
    }

    
    return 0;
}