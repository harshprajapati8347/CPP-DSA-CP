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

//! Deletion in a Linked List
// Algorithm:
// 1. Create a pointer to the head
// 2. Traverse to the position
// 3. Make the position's next point to the position's next's next
// 4. Delete the pointer
// 6. If the position is the last node, make the position's next point to NULL
// 7. If the position is the first node, make the head point to the head's next
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

//! Reverse by K
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