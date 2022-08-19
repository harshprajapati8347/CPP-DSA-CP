#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

class LinkedList
{
private:
    Node *head;

public:
    LinkedList()
    {
        head = NULL;
    }
    // Add new element at start of the list
    void push_front(int newElement)
    {
        // 1. allocate node
        Node *newNode = new Node();

        // 2. assign data element
        newNode->data = newElement;

        // 3. assign null to the next of new node
        newNode->next = NULL;

        // 4. Check the Linked List is empty or not,
        //    if empty make the new node as head
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            // 5. Else, make the new node as head
            newNode->next = head;
            head = newNode;
        }
    }
    // display the content of the list
    void PrintList()
    {
        Node *temp = head;
        if (temp != NULL)
        {
            cout << "The list contains: ";
            while (temp != NULL)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
        else
        {
            cout << "The list is empty" << endl;
        }
    }
};

int main()
{
    LinkedList MyList;
    MyList.push_front(10);
    MyList.push_front(20);
    MyList.push_front(30);
    MyList.PrintList();
    return 0;
}