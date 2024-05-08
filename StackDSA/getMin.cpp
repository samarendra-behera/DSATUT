#include <iostream>
#include <stack>
using namespace std;

class specialStack
{
    stack<int> st;
    int mini = INT_MAX;

    void push(int element)
    {
        if (st.empty())
        {
            mini = element;
            st.push(element);
        }
        else
        {
            if (mini < element)
            {
                st.push(element);
            }
            else
            {
                int val = 2 * element - mini;
                st.push(val);
                mini = element;
            }
        }
    }
    int pop()
    {
        if (st.top() == -1)
        {
            return -1;
        }
        else
        {
            int curr = st.top();
            st.pop();
            if (mini < curr)
            {
                return curr;
            }
            else
            {
                int prevMin = mini;
                int val = 2 * mini - curr;
                mini = val;
                return prevMin;
            }
        }
    }
    int top()
    {
        if (st.empty())
        {
            return -1;
        }
        else
        {
            int curr = st.top();
            if (curr > mini)
            {
                return curr;
            }
            else
            {
                return mini;
            }
        }
    }
    bool isEmpty()
    {
        return st.empty();
    }
    int getMin()
    {
        if (st.empty())
        {
            return -1;
        }
        else
        {
            return mini;
        }
    }
};

int main()
{
    stack<int> s;

    return 0;
}