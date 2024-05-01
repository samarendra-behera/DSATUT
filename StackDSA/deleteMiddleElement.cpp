#include<iostream>
#include<stack>
using namespace std;

void deleteMiddle(stack<int>&inputStack, int count, int size){
    if(count == size / 2){
        inputStack.pop();
        return;
    }else{
        ++count;
        int topElement = inputStack.top();
        inputStack.pop();
        deleteMiddle(inputStack, count, size);
        inputStack.push(topElement);
    }
}

int main(){
    stack<int> s;
    s.push(1);
    // s.push(2);
    // s.push(3);
    // s.push(4);
    // s.push(5);

    int count = 0;
    int size = s.size();

    deleteMiddle(s, count, size);

    cout<<s.top()<<endl;
    return 0;
}