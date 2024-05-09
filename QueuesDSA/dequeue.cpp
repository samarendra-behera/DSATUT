#include<iostream>
#include<queue>
using namespace std;

class Deque{
    int *arr;
    int size, front, rear;

    public:
        Deque(int s){
            this->size = s;
            front=rear = -1;
            arr = new int[size];
        }
        bool pushFront(int value){
            // check full condition
            if((front==0 && rear==size-1) || (rear == (front-1) % size)){
                return false;
            }else if(front==-1){
                front=rear=0;
            }else if(front == 0){
                front=size-1;
            }else{
                front--;
            }
            arr[front] = value;
            return true;
        }
        bool pushBack(int value){
            if((front==0 && rear==size-1) || (rear==(front-1)%size)){
                return false;
            }else if(front==-1){
                rear=front=0;
            }else if(rear==size-1){
                rear=0;
            }else{
                rear++;
            }
        }
        int popFront(){
            if(front==-1){
                return false;
            }
            int prev = arr[front];
            arr[front] = -1;
            if(front==rear){
                front=rear=-1;
            }else if(front==0){
                front=size-1;
            }else{
                front++;
            }
            return prev;
        }
        int popBack(){
            if(front==-1){
                return false;
            }
            int prev = arr[rear];
            arr[rear] = -1;

            if(front==rear){
                front=rear=-1;
            }else if(rear==0 ){
                rear=size-1;
            }else{
                rear--;
            }
            return prev;
        }
};

int main(){
    /*
    deque<int> d;

    d.push_front(12);
    d.push_back(13);

    cout<<d.front()<<endl;
    cout<<d.back()<<endl;

    d.pop_back();

    cout<<d.front()<<endl;
    cout<<d.back()<<endl;

    d.pop_front();

    if(d.empty()){
        cout<<"Dubble Endded Queue is Empty"<<endl;
    }else{
        cout<<"Dubble Endded Queue is not Empty"<<endl;
    }
    */
    
    return 0;
}