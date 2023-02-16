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
    ~node() // destructor
    {
        int val = this->data;
        // memory free code
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "Node with value " << val << " deleted" << endl;
    }
};

//! Insertion at Tail
// Algorithm:
// 1. Create a new node
// 2. Traverse to the last node
// 3. Make the last node's next point to the new node
// 4. Make the new node's next point to NULL
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

//! Insertion at Head
// Algorithm:
// 1. Create a new node
// 2. Make the new node's next point to the head
// 3. Make the head point to the new node
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

//! Insertion at a specific position
// Algorithm:
// 1. Create a new node
// 2. Traverse to the position
// 3. Make the new node's next point to the position's next
// 4. Make the position's next point to the new node
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

//! Deletion at Head
// Algorithm:
// 1. Create a pointer to the head
// 2. Make the head point to the head's next
// 3. Delete the pointer
// 4. Make the pointer point to NULL
void deleteAtHead(node *&head)
{
    node *todelelte = head;
    head = head->next;
    delete todelelte;
};

//! Deletion by Value
// Algorithm:
// 1. Create a pointer to the head
// 2. Traverse to the position
// 3. Make the position's next point to the position's next's next
// 4. Delete the pointer
// 6. If the position is the last node, make the position's next point to NULL
// 7. If the position is the first node, make the head point to the head's next
void deletionByValue(node *&head, int val)
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    if (head->next == NULL) // only one node
    {
        delete head;
        head = NULL;
        return;
    }
    node *temp = head;
    while (temp->next->data != val) // traverse to the position
    {
        temp = temp->next;
    }
    node *todelelte = temp->next;
    temp->next = temp->next->next;
    todelelte->next = NULL;
    delete todelelte;
};

//! Deletion by Position
// Algorithm:
// 1. Create a pointer to the head
// 2. Traverse to the position
// 3. Make the position's next point to the position's next's next
// 4. Delete the pointer
// 6. If the position is the last node, make the position's next point to NULL
// 7. If the position is the first node, make the head point to the head's next
void deletionByPos(node *&head, int pos)
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    if (head->next == NULL) // only one node
    {
        delete head;
        head = NULL;
        return;
    }
    node *temp = head;
    int count = 0;
    while (temp->next != NULL) // to count of nodes
    {
        temp = temp->next;
        count++;
    }
    if (pos > count)
    {
        cout << "Invalid position" << endl;
        return;
    }
    if (pos == 0)
    {
        node *todelelte = head;
        head = head->next;
        todelelte->next = NULL;
        delete todelelte;
        return;
    }
    if (pos == count) // last node
    {
        temp = head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        node *todelelte = temp->next;
        temp->next = NULL;
        todelelte->next = NULL;
        delete todelelte;
        return;
    }
    temp = head;
    while (count > pos)
    {
        temp = temp->next;
        count--;
    }
    node *todelelte = temp->next;
    temp->next = temp->next->next;
    todelelte->next = NULL;
    delete todelelte;
};

//! Searching in a Linked List
// Algorithm:
// 1. Create a pointer to the head
// 2. Traverse to the position
// 3. If the position's data is equal to the value, return true else false
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

//! Iterative Way to reverse a linked list
// Algorithm:
// 1. Create three pointers, prev, curr, next
// 2. Make the curr point to the head
// 3. Make the next point to the curr's next
// 4. Make the curr's next point to prev
// 5. Make the prev point to the curr
// 6. Make the curr point to the next
// 7. Repeat steps 3 to 6 until the curr is NULL
// 8. Make the head point to the prev
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

//! Reverse Recursive Way to reverse a linked list
// Algorithm:
// 1. Base Case: If the head is NULL or the head's next is NULL, return the head
// 2. Create a pointer to the head's next
// 3. Make the head's next's next point to the head
// 4. Make the head's next point to NULL
// 5. Make the head point to the pointer
// 6. Repeat steps 2 to 5 until the head is NULL
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

//! Reverse by K nodes
// Algorithm:
// 1. Create three pointers, prev, curr, next
// 2. Make the curr point to the head
// 3. Make the next point to the curr's next
// 4. Make the curr's next point to prev
// 5. Make the prev point to the curr
// 6. Make the curr point to the next
// 7. Repeat steps 3 to 6 until the curr is NULL or the count is equal to k
// 8. Make the head's next point to the reverseByK(next, k)
// 9. Return the prev
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

//! Traversing the LL & Displaying the LL
// Algorithm:
// 1. Create a pointer to the head
// 2. Traverse to the position
// 3. Print the position's data
// 4. Repeat steps 2 to 3 until the pointer is NULL
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
    insertAtHead(head, 1);
    insertAtHead(head, 2);
    insertAtHead(head, 3);
    insertAtHead(head, 4);
    insertAtHead(head, 5);
    insertAtHead(head, 6);
    display(head);
    deletionByPos(head, 0);
    display(head);
    deletionByValue(head, 1);
    display(head);
    return 0;
}