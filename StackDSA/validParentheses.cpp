#include <iostream>
#include <stack>
using namespace std;

bool isValidPara(string str)
{
    stack<char> s;

    // if opening bracket then push to stack
    // if closing bracket then stack top check and pop
    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        if (ch == '(' || ch == '[' || ch == '{')
        {
            s.push(ch);
        }
        else
        {
            if (!s.empty())
            {
                char top = s.top();
                if (top == '(' && ch == ')' || top == '[' && ch == ']' || top == '{' && ch == '}')
                {
                    s.pop();
                }
                else
                {
                    return false;
                }
            }else{
                return false;
            }
        }
    }
    if (s.empty()){
        return true;
    }
    return false;
}

int main()
{
    string str = "[{()}]";

    if(isValidPara(str)){
        cout<<str<<" is Valid"<<endl;
    }else{
        cout<<str<<" is Invalid"<<endl;
    }

    return 0;
}