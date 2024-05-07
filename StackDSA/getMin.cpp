#include<iostream>
#include<stack>
using namespace std;

class specialStack{
    stack<int> st;
    int mini = INT_MAX;

    void push(int element){
        if(st.empty()){
            mini = element;
            st.push(element);
        }else{
            if(mini < element){
                st.push(element);
            }else{
                int val = 2 * element - mini;
                st.push(val);
                mini = element;
            }

        }
    }
    int pop(){
        if(st.top()==-1){
            return -1;
        }else{
            int curr = st.top();
            st.pop();
            if(mini<curr){
                return curr;
            }else{
                int prevMin = 2*st.top() - curr;
                mini=prevMin;
                return prevMin;
            }
        }
    }
    int top(){

    }
    bool isEmpty(){

    }
};

int main(){
    stack<int> s;

    return 0;
}