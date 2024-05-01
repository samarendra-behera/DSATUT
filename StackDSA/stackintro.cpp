#include <iostream>
// #include<stack>
using namespace std;

class Stack
{
    // properties
    public:
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
        if(size - top > 1){
            top++;
            arr[top] = element;
        }else{
            cout<<"Stack Overflow"<<endl;
        }

    }

    void pop(){
        if(top >= 0){
            top--;
        }else{
            cout<<"Stack Underflow"<<endl;
        }
    }

    int peek(){
        if(top >=0 && size > top){
            return arr[top];
        }else{
            cout<<"Stack is Empty"<<endl;
            return -1;
        };
    }

    bool isEmpty(){
        if(top==-1){
            return true;
        }else{
            return false;
        }
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


    // Create a Custom Class Stack
    Stack st(5);

    st.push(3);
    st.push(4);
    st.push(9);
    st.push(5);
    st.push(8);

    cout<<"Top element of stack: "<<st.peek()<<endl;
    st.pop();
    cout<<"Top element of stack: "<<st.peek()<<endl;
    st.pop();
    cout<<"Top element of stack: "<<st.peek()<<endl;
    st.pop();
    cout<<"Top element of stack: "<<st.peek()<<endl;
    return 0;
}