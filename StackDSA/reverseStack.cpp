#include<iostream>
#include<stack>
using namespace std;

void insertButtom(stack<int>&s, int x){
    if(s.empty()){
        s.push(x);
        return;
    }
    int top = s.top();
    s.pop();
    insertButtom(s, x);
    s.push(top);
}

void reverseStack(stack<int>&s){
    if(s.empty()){
        return ;
    }
    int top = s.top();
    s.pop();
    reverseStack(s);
    insertButtom(s, top);
}

int main(){
    stack<int> s;
    s.push(11111);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(200000);

    cout<<"Before Reverse Stack Top : "<<s.top()<<endl;
    reverseStack(s);
    cout<<"After Reverse Stack Top : "<<s.top()<<endl;
    return 0;
}