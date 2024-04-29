#include <iostream>
// #include<stack>
using namespace std;

class Stack
{
    // properties
    int *arr;
    int top;
    int size;

    Stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int element){

    }

    void pop(){

    }

    int peek(){

    }

    bool isEmpty(){
        
    }
};

int main()
{

    /*
    // creation of stack
    stack<int> s;

    // push in stack
    s.push(2);
    s.push(3);

    //pop in stack
    s.pop();

    if (s.empty()){
        cout<<"The stack is Empty!"<<endl;
    }else{
        cout<<"The stack is not Empty!"<<endl;
    }
    cout<<"Top element of stack: "<<s.top()<<endl ;

    cout<<"Size of the stack: "<< s.size()<<endl;

    */

    return 0;
}