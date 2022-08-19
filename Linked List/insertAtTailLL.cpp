#include <iostream>
using namespace std;

// node structure
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

    // Add new element at the end of the list
    void push_back(int newElement)
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

            // 5. Else, traverse to the last node
            Node *temp = head;
            while (temp->next != NULL)
                temp = temp->next;

            // 6. Change the next of last node to new node
            temp->next = newNode;
        }
    }

    // delete node

    void deletion(Node *&head, int val)
    {
        Node *temp = head;
        while (temp->next->data != val)
        {
            temp = temp->next;
        }
        Node *todelelte = temp->next;
        temp->next = temp->next->next;
        delete todelelte;
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
            cout << "The list is empty.\n";
        }
    }
};

// test the code
int main()
{
    LinkedList MyList;

    // Add three elements at the end of the list.
    MyList.push_back(10);
    MyList.push_back(20);
    MyList.push_back(30);
    MyList.PrintList();
    MyList.deletion(MyList.head, 20);
    MyList.PrintList();

    return 0;
}