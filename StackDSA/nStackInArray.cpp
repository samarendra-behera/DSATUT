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

    public:
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

        }
};

int main(){
    return 0;
}