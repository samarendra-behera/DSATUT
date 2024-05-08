#include<iostream>
using namespace std;

class CircularQueue{
    int *arr;
    int front, size, rear;

    public:
        CircularQueue(int size){
            this->size = size;
            arr = new int[size];
            front=rear=-1;
        }

        bool enqueue(int val){
            if((front==0 && rear==size-1)||(rear == (front-1)%(size-1))){
                return false;
            }else{
                if(front==-1 && rear==-1){
                    front=rear=0;
                }else if (rear==size-1 && front !=0){
                    rear=0;
                }else{
                    rear++;
                }
            }
            arr[rear] = val;
            return true;
        }
        int dequeue(){

        }
};

int main(){
    return 0;
}

