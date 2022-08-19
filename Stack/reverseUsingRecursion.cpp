#include <iostream>
#include <stack>
using namespace std;

void insertAtBottom(stack<int> &st, int topElm)
{
    if (st.empty())
    {
        st.push(topElm);
        return;
    } // if stack is empty, push topElm to stack
    int bottomElm = st.top();
    st.pop();
    insertAtBottom(st, topElm);
    st.push(bottomElm);
}

void reverse(stack <int> &st){
    if(st.empty()){
        return;
    } // if stack is empty, return
    int topEle = st.top();
    st.pop();
    reverse(st);
    insertAtBottom(st, topEle);
}

int main()
{
    stack <int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    // input: 3 2 1
    // output: 1 2 3 
    reverse(st);
    while(!st.empty()){
        cout << st.top() << endl;
        st.pop();
    } 
    return 0;
}