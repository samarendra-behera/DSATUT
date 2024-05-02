#include<iostream>
#include<stack>
using namespace std;

int findMinimumCost(string str){
    if(str.length() % 2 != 0){
        return -1;
    }
    stack<char> st;
    for (int i = 0; i<str.length(); i++){
        char ch = str[i];
        if(ch=='{'){
            st.push(ch);
        }else{
            if(!st.empty() && st.top() == '{'){
                st.pop();
            }else{
                st.push(ch);
            }
        }
    }

    int a=0, b=0;
    while (!st.empty())
    {
        char top = st.top();
        if(top == '{'){
            b++;
        }else{
            a++;
        }
        st.pop();
    }
    
    int result = (a + 1) / 2 + (b + 1) / 2;
    return result;
}

int main(){
    string str = "}}}}}{{{{{";

    int result = findMinimumCost(str);
    cout<<"Result is : "<< result <<endl;
    return 0;
}