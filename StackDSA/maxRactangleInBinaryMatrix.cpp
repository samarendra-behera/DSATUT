#include<iostream>
#include<stack>
#include<vector>
using namespace std;

vector<int> nextSmallElement(vector<int> &arr, int s){
    stack<int> st;
    st.push(-1);
    vector<int> ans(s);
    for(int i=s-1; i>=0; i--){
        int curr = arr[i];
        while(st.top() != -1 && curr <= arr[st.top()]){
            st.pop();
        }
        ans[i] = st.top();
        st.push(i);
    }

    return ans;
}

vector<int> prevSmallElement(vector<int> &arr, int s){
    stack<int> st;
    st.push(-1);
    vector<int> ans(s);

    for (int i=0; i<s; i++){
        int curr = arr[i];
        while(st.top() != -1 && curr <= arr[st.top()]){
            st.pop();
        }
        ans[i] = st.top();
        st.push(i);
    }

    return ans;
}

int largestRectangularAreaHistogram(vector<int>&arr, int s){

    vector<int> next(s);
    vector<int> prev(s);
    prev = prevSmallElement(arr, s);
    next = nextSmallElement(arr, s);

    int largestArea = INT_MIN;

    for(int i=0; i<s; i++){
        int h = arr[i];
        if(next[i] == -1){
            next[i] = s;
        }
        int w = next[i] - prev[i] -1;

        int newArea = h * w;
        largestArea = max(largestArea, newArea);
    }

    return largestArea;
}

int main(){
    vector<vector<int>> M = {
        {0, 1, 1, 0},
        {0, 1, 1, 1},
        {1, 1, 1, 1},
        {1, 1, 0, 0},
    };

    int r = M.size();
    int c = M[0].size();

    int area = largestRectangularAreaHistogram(M[0], c);

    for(int i=1; i< r; i++){
        for(int j=0; j<c; j++){
            if(M[i][j] != 0){
                M[i][j] = M[i][j] + M[i-1][j];
            }else{
                M[i][j] = 0;
            }
        }
        area = max(area, largestRectangularAreaHistogram(M[i], c));
    }

    cout<<area<<endl;


    return 0;
}