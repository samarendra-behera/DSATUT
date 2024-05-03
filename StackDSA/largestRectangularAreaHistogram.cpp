#include<iostream>
#include<stack>
#include<vector>
using namespace std;

vector<int> nextSmall(vector<int>arr, int size){
    stack<int> st;
    st.push(-1);
    vector<int> ans(size);

    for(int i=size-1; i>=0; i--){
        int curr = arr[i];
        while(st.top() != -1 && curr <= arr[st.top()]){
            st.pop();
        }
        ans[i] = st.top();
        st.push(i);
    }

    return ans;
}

vector<int> prevSmall(vector<int>arr, int size){
    stack<int> st;
    st.push(-1);
    vector<int> ans(size) ;

    for(int i=0; i<size; i++){
        int curr = arr[i];
        while(st.top() != -1 && curr<=arr[st.top()]){
            st.pop();
        }
        ans[i] = st.top();
        st.push(i);
    }
    return ans;
}

int main(){
    vector<int> arr = {2, 4, 3, 6, 4};
    int size = arr.size();

    vector<int> next(size);
    vector<int> prev(size);
    next = nextSmall(arr, size);
    prev = prevSmall(arr, size);

    cout<<"Next Smalls"<<endl;
    for(int i=0; i<size; i++){
        cout<<next[i]<<" ";
    }
    cout<<endl;
    cout<<"Prev Smalls"<<endl;
    for(int i=0; i<size; i++){
        cout<<prev[i]<<" ";
    }
    cout<<endl;

    int largArea = INT_MIN;
    for(int i=0;i<size;i++){
        int height = arr[i];
        if(next[i] == -1){
            next[i] = size;
        }
        int width = next[i] - prev[i] -1;

        int a = height * width;
        cout<<a<<" ";
        largArea = max(largArea, a); 
    }
    cout<<endl;
    
    cout<< "Large Area is : "<<largArea<<endl;

    return 0;
}