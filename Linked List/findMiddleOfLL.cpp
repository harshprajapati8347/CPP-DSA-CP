// Given the head of a singly linked list, return the middle node of the linked list.
// If there are two middle nodes, return the second middle node.
// Input : head = [ 1, 2, 3, 4, 5 ]
// Output : [ 3, 4, 5 ]
// Explanation : The middle node of the list is node 3.

#include <iostream>
using namespace std;

struct ListNode
{
    int data;
    ListNode *next;
};

class findMiddle
{
private:
    ListNode *head;

public:
    findMiddle()
    {
        head = NULL;
    }

    void push_back(int newElement)
    {
        ListNode *newNode = new ListNode();
        newNode->data = newElement;
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            ListNode *temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
    }

    void printList()
    {
        ListNode *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

//  TODO: 
    ListNode *middleNode(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};

int main()
{
    findMiddle obj;
    obj.push_back(1);
    obj.push_back(2);
    obj.push_back(3);
    obj.push_back(4);
    obj.push_back(5);
    obj.push_back(6);

    return 0;
}