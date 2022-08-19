#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int val) // constructor
    {
        data = val;
        next = NULL;
    }
};

void insertAtTail(node *&head, int val)
{
    node *newNode = new node(val);
    if (head == NULL) // empty linked list
    {
        head = newNode;
        return;
    }
    node *temp = head;
    while (temp->next != NULL) // traverse to the last node
    {
        temp = temp->next;
    }
    temp->next = newNode;
};

void insertAtHead(node *&head, int val)
{
    if (head == NULL)
    {
        head = new node(val);
        return;
    }
    node *newNode = new node(val);
    newNode->next = head;
    head = newNode;
};

void insertAtSpecificPosition(node *&head, int val, int position)
{
    node *newNode = new node(val);
    node *temp = head;
    int count = 0;
    while (temp->next != NULL) // to count of nodes
    {
        temp = temp->next;
        count++;
    }
    if (position > count)
    {
        cout << "Invalid position" << endl;
        return;
    }
    if (position == 0)
    {
        insertAtHead(head, val);
        return;
    }
    if (position == count)
    {
        insertAtTail(head, val);
        return;
    }
    temp = head;
    while (count > position)
    {
        temp = temp->next;
        count--;
    }
    newNode->next = temp->next;
    temp->next = newNode;
};

void deleteAtHead(node *&head)
{
    node *todelelte = head;
    head = head->next;
    delete todelelte;
};

void deletion(node *&head, int val)
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    if (head->next == NULL)
    {
        delete head;
        head = NULL;
        return;
    }
    node *temp = head;
    while (temp->next->data != val)
    {
        temp = temp->next;
    }
    node *todelelte = temp->next;
    temp->next = temp->next->next;
    delete todelelte;
};

bool search(node *head, int val)
{
    while (head != NULL)
    {
        if (head->data == val)
        {
            cout << "Found == ";
            return true;
        }
        head = head->next;
    }
    cout << "Not Found == ";
    return false;
};

// Iterative Way to reverse a linked list

node *reverse(node *&head)
{
    node *prev = NULL;
    node *curr = head;
    node *next = NULL;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;

        prev = curr;
        curr = next;
    }
    head = prev;
    return prev;
};

// Reverse Recursive Way to reverse a linked list

node *reverseRecursive(node *&head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    node *temp = reverseRecursive(head->next);
    head->next->next = head;
    head->next = NULL;
    return temp;
};



node *reverseByK(node *&head, int k)
{
    node *prev = NULL;
    node *curr = head;
    node *next = NULL;
    int count = 0;
    while (curr != NULL && count < k)
    {
        next = curr->next;
        curr->next = prev;

        prev = curr;
        curr = next;
        count++;
    }
    if (next != NULL)
    {
        head->next = reverseByK(next, k);
    }
    return prev;
};

void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    node *head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    display(head);
    insertAtHead(head, 0);
    display(head);
    cout << search(head, 2) << endl;
    deletion(head, 2);
    display(head);
    deleteAtHead(head);
    display(head);
    insertAtSpecificPosition(head, 7, 2);
    display(head);
    // Iterative Way to reverse a linked list
    node *newHead = reverse(head);
    display(newHead);
    // Reverse Recursive Way to reverse a linked list
    newHead = reverseRecursive(head);
    display(newHead);
    // Reverse by K
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    insertAtTail(head, 6);
    display(head);
    newHead = reverseByK(head, 2);
    display(newHead);
    return 0;
}