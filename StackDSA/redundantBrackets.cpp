#include<iostream>
#include<stack>
using namespace std;

bool strRedundantCheck(string& str){
    stack<char> st;
    cout<<str<<endl;

    for (int i=0; i<str.length(); i++){
        char ch = str[i];
        if(ch == '(' || ch=='+'|| ch=='-'|| ch=='*' || ch=='/'){
            st.push(ch);
        }else{
            if(ch==')'){
                bool isRedundant = true;
                while (st.top() != '(')
                {
                    char top = st.top();
                    if(top == '+' || top == '-' || top == '*' || top == '/'){
                        isRedundant = false;
                    }
                    st.pop();
                }
                
                if(isRedundant == true){
                    return true;
                }
                st.pop();
            }
        }
    }
    return false;
}

int main(){

    string str = "(((a+b)+c))";

    cout<<"hii "<<endl;
    bool result = strRedundantCheck(str);
    if(result){
        cout<<"This string is Redundant!"<<endl;
    }else{
        cout<<"This string is not Redundant!"<<endl;
    }
    return 0;
}