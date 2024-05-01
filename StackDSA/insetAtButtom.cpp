#include<iostream>
#include<stack>
using namespace std;

void insertButtom(stack<int>&s, int element){
    if(s.empty()){
        s.push(element);
        return;
    }
    int top = s.top();
    s.pop();
    insertButtom(s, element);
    s.push(top);
}

int main(){

    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);

    cout<< "Before Insert Size of Stack : "<< s.size()<<endl;
    int element = 10;
    insertButtom(s, element);

    cout<< "After Insert Size of Stack : "<< s.size()<<endl;
    return 0;
}