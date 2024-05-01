#include<iostream>
using namespace std;
class twoStacks
{
    int *arr;
    int top1;
    int top2;
    int size;
    
    public:

    
    
    twoStacks(int size)
    {
        this->size = size;
        top1=-1;
        top2=size;
        arr = new int[size];
    }
 
    //Function to push an integer into the stack1.
    void push1(int x)
    {
        if(top2 - top1 > 1){
            top1++;
            arr[top1] = x;
        }
    }
    
    //Function to push an integer into the stack2.
    void push2(int x)
    {
       if(top2 - top1 > 1){
            top2--;
            arr[top2] = x;
        }
    }
    
    //Function to remove an element from top of the stack1.
    int pop1()
    {
        if(top1 >=0){
            int ans = arr[top1];
            top1--;
            return ans;
        }
        else{
            return -1;
        }
    }
    
    //Function to remove an element from top of the stack2.
    int pop2()
    {
       if(top2 < size){
           int ans = arr[top2];
            top2++;
            return ans;
        }
        else{
            return -1;
        }
    }
};


int main(){

    twoStacks st(10);

    st.push1(2);
    st.push1(3);
    st.push1(4);
    st.push1(5);
    st.push1(6);
    st.push2(7);
    st.push2(8);
    st.push2(9);
    st.push2(10);
    st.push2(11);
    st.pop1();
    st.pop2();
    st.push2(33);
    st.push2(33);


    return 0;
}