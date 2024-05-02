#include<iostream>
#include<stack>
using namespace std;

int main(){
    int const n = 4;
    int arr[n] = {2, 1, 4, 3};

    stack<int> st;
    st.push(-1);

    for (int i = n-1; i>=0; i--){
        int curr = arr[i];
        while(curr <= st.top()){
            st.pop();
        }
        // stack top is small to curr
        arr[i] = st.top();
        st.push(curr);
    }

    for (int i = 0; i<n; i++){
        cout<<arr[i]<<endl;
    }
    return 0;
}