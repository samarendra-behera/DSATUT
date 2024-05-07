#include<iostream>
#include<stack>
#include<vector>
using namespace std;

class NStack {
    int *arr;
    int *top;
    int freespot;
    int *next;
    int n,s;
    public:
        NStack(int n, int s){
            this->n = n;
            this->s = s;
            freespot = 0;
            arr = new int[n];
            next = new int[n];
            top = new int[s];

            // top initialise
            for (int i =0; i<s; i++){
                top[i] = -1;
            }

            // next initialise
            for(int i=0; i<n; i++){
                next[i] = i+1;
            }
            next[n-1] = -1;
        }
        bool push(int element, int stack){
            // check for overflow
            if(freespot == -1){
                return false;
            }

            // find index
            int index = freespot;

            // update freespot
            freespot = next[index];

            // insert element into array
            arr[index] = element;

            // update next
            next[index] = top[stack-1];

            // update top
            top[stack-1] = index;

            return true;

        }

        int pop(int stack){

            // check underflow condition
            if(top[stack-1] == -1){
                return -1;
            }

            int index = top[stack-1];

            top[stack-1] = next[index];

            next[index] = freespot;

            freespot = index;

            return arr[index];
        }
        int peek(int stack){
            // check underflow condition
            if(top[stack-1] == -1){
                return -1;
            }

            return arr[top[stack-1]];
        }
};

int main(){
    NStack st(20, 3);

    st.push(10 , 1);
    st.push(20, 2);
    st.push(30, 3);
    st.push(40, 1);
    st.pop(1);
    st.push(100, 2);
    st.push(200, 2);
    st.push(300, 2);
    st.push(400, 2);
    st.pop(2);

    int top1 = st.peek(1);
    cout<<"First Stack Top :"<<top1<<endl;
    int top2 = st.peek(2);
    cout<<"Second Stack Top :"<<top2<<endl;
    return 0;
}