#include<iostream>
#include<queue>
#include<stack>
using namespace std;

void printQueue(queue<int> q){
    while (!q.empty())
    {
        int curr = q.front();
        cout<<curr<<" ";
        q.pop();
    }
}

void reverseQueue(queue<int> &q){
    if(q.empty()){
        return;
    }

    int curr = q.front();
    q.pop();
    reverseQueue(q);
    q.push(curr);
}

int main(){
    queue<int> q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    printQueue(q);
    cout<<endl;
    reverseQueue(q);
    printQueue(q);
    // approach 1
    /*
    stack<int> st;

    while (!q.empty())
    {
        int curr = q.front();
        st.push(curr);
        q.pop();
    }

    while(!st.empty()){
        int top = st.top();
        q.push(top);
        st.pop();
    }

    
    printQueue(q);
    */

    // approach 2

    return 0;
}