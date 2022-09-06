#include<iostream>
using namespace std;

// Node structure for LL
class node{
    public:
    int data;
    node *next;
    node(int d){
        data=d;
        next=NULL;
    }
};

class queue{
    node* front;
    node* back;
    public:
    queue(){
        front=NULL;
        back=NULL;
    }

    void push(int x){
        node* n = new node(x); // new node init
        if(front == NULL){
            back = n;
            front =n;
            return;
        }
        back->next = n;
        back = n;
    }

    int pop(){
        if(front == NULL){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        int x = front->data;
        node* temp = front;
        front = front->next;
        delete temp;
        return x;
    }

    int topPeek(){
        if(front == NULL){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        return front->data;
    }

    bool isEmpty(){
        if(front == NULL){
            return true;
        }
        return false;
    }
};

int main()
{
    queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.pop();
    cout << q.topPeek()<< endl;
    q.pop();
    q.pop();
    cout << q.isEmpty() << endl;
    return 0;
}