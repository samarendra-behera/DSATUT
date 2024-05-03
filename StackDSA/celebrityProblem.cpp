#include<iostream>
#include<vector>
#include<stack>
using namespace std;



int main(){
    stack<int> st;
    vector<vector<int>> matrix;
    matrix = {
        {1 , 1 , 0},
        {0 , 1 , 0},
        {1 , 1 , 1}
    };

    int numPerson = matrix.size();

    for(int i=0; i<numPerson; i++){
        st.push(i);
    }

    while (st.size() > 1)
    {
        int a = st.top();
        st.pop();
        int b = st.top();
        st.pop();

        if(matrix[a][b] == 1 && matrix[b][a] == 0){
            st.push(b);
        }else{
            st.push(a);
        }
    }

    // single element in stack is potential celebrity
    // so varify it
    int potential_cel = st.top();
    bool rowCheck = true;
    bool colCheck = true;

    for (int i = 0; i<numPerson; i++){
        if(i == potential_cel){
            continue;
        }
        if (matrix[potential_cel][i] != 0){
            rowCheck=false;
            break;
        }
        if(matrix[i][potential_cel] != 1){
            colCheck = false;
            break;
        }
    }
    int celebrity = -1;
    if (rowCheck && colCheck){
        celebrity = potential_cel;
    }

    cout<<"Celebrity is : "<< celebrity<<endl;
    
    return 0;
}