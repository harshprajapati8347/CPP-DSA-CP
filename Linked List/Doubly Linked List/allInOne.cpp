#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node *prev;
    node(int val)
    {
        data = val;
        prev = NULL;
        next = NULL;
    }
    ~node()
    {
        int val = this->data;
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "Node with value " << val << " deleted" << endl;
    }
};

//! Getting the length of the linked list
int getLength(node *head)
{
    int count = 0;
    node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

//! Inseart at Head
void insertAtHead(node *&head, int val)
{
    if (head == NULL)
    {
        head = new node(val);
        return;
    }
    node *temp = new node(val);
    temp->next = head;
    head->prev = temp;
    head = temp;
}

//! Insert at Tail
void insertAtTail(node *&head, int val)
{
    node *newNode = new node(val);
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

//! Inseart at position
void inseartAtPosition(node *&head, int val, int pos)
{
    if (pos == 1)
    {
        insertAtHead(head, val);
        return;
    }
    if (pos > getLength(head))
    {
        insertAtTail(head, val);
        return;
    }
    node *newNode = new node(val);
    node *temp = head;
    int count = 1;
    while (count != pos - 1)
    {
        temp = temp->next;
        count++;
    }
    newNode->next = temp->next;
    temp->next->prev = newNode;
    temp->next = newNode;
    newNode->prev = temp;
}

//! Deletion  at any position
void deleteAtPosition(node *&head, int pos)
{
    // At Head
    if (pos == 1)
    {
        node *temp = head;
        head = head->next;
        head->prev = NULL;
        delete temp;
        return;
    }
    // At Tail
    if (pos > getLength(head))
    {
        node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->prev->next = NULL;
        delete temp;
        return;
    }
    // At any position
    node *temp = head;
    int count = 1;
    while (count != pos - 1)
    {
        temp = temp->next;
        count++;
    }
    node *toDelete = temp->next;
    temp->next = temp->next->next;
    temp->next->prev = temp;
    delete toDelete;
}

//! Traversing the linked list
void printList(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    node *node1 = new node(1);
    node *head = node1;
    printList(head);
    insertAtHead(head, 2);
    printList(head);
    insertAtTail(head, 3);
    printList(head);
    inseartAtPosition(head, 4, 2);
    printList(head);
    deleteAtPosition(head, 2);
    printList(head);

    return 0;
}