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
            arr[rear]=value;
            return true;
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
        int getFront(){
            if(front==-1){
                return -1;
            }
            return arr[front];
        }
        int getRear(){
            if(front==-1){
                return -1;
            }
            return arr[rear];
        }
        bool isFull(){
            if((front==0 && rear==size-1) || (rear== (front-1)%size)){
                return true;
            }
            return false;
        }
        bool isEmpty(){
            if(front==-1){
                return true;
            }
            return false;
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

    Deque d(3);
    d.pushBack(23);
    d.pushFront(24);
    cout<<d.getFront()<<endl;
    cout<<d.getRear()<<endl;

    d.popBack();
    cout<<d.getFront()<<endl;
    cout<<d.getRear()<<endl;
    d.popFront();
    cout<<d.getFront()<<endl;
    cout<<d.getRear()<<endl;

    if(d.isEmpty()){
        cout<<"Queue is Empty"<<endl;
    }else{
        cout<<"Queue is not Empty"<<endl;
    }

    d.pushBack(20);
    d.pushFront(30);
    d.pushBack(40);

    cout<<d.getFront()<<endl;
    cout<<d.getRear()<<endl;
    if(d.isFull()){
        cout<<"Queue is Full"<<endl;
    }else{
        cout<<"Queue is not Full"<<endl;
    }

    
    return 0;
}