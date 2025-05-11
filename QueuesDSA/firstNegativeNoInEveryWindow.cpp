#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
    int k = 2;
    vector<int> arr = {-8, 4, 3, -6, 5};
    int size = arr.size();

    deque<int> d;
    vector<int> ans;

    // process first window for k size
    for (int i = 0; i < k; i++)
    {
        if (arr[i] < 0)
        {
            d.push_back(i);
        }
    }
    // store answer of first k sized window
    if (d.size() > 0)
    {
        ans.push_back(arr[d.front()]);
    }
    else
    {
        ans.push_back(0);
    }

    // process for remaining windows
    for (int i = k; i < size; i++)
    {
        // removal
        if (!d.empty() && i - d.front() >= k)
        {
            d.pop_front();
        }

        // addition
        if (arr[i] < 0)
        {
            d.push_back(i);
        }

        // ans store
        if (d.size() > 0)
        {
            ans.push_back(arr[d.front()]);
        }
        else
        {
            ans.push_back(0);
        }
    }

    // print the answer
    cout << "[ ";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << ",";
    }
    cout << "]";
    return 0;
}