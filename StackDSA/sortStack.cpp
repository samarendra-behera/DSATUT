#include<iostream>
#include<stack>
using namespace std;

void printStack(stack<int> s) {
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

void sortedInsert(stack<int>&s, int x){
    if(s.empty() || !s.empty() && s.top() < x){
        s.push(x);
        return;
    }

    int top = s.top();
    s.pop();
    sortedInsert(s, x);
    s.push(top);
}

void sortStack(stack<int>&s){
    if(s.empty()){
        return;
    }

    int top = s.top();
    s.pop();
    sortStack(s);
    sortedInsert(s, top);
}

int main(){

    stack<int> s;
    s.push(10);
    s.push(6);
    s.push(8);
    s.push(12);
    s.push(3);
    s.push(5);

    cout<<"Before Sorting Stack: "<<endl;
    printStack(s);

    sortStack(s);

    cout<<"After Sorting Stack: "<<endl;
    printStack(s);

    return 0;
}