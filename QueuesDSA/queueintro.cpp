#include <iostream>
#include<queue>
using namespace std;

class Queue{
    int *arr;
    int size, qfront, rear;
    public:
        Queue(int size){
            this->size = size;
            qfront=0;
            rear=0;
            arr = new int[size];
        }

        void push(int element){
            if(rear == size){
                cout<<"Queue Overflow"<<endl;
            }else{
                arr[rear] = element;
                rear++;
            }
        }

        int pop(){
            if(qfront==rear){
                return -1;
            }else{
                int curr = arr[qfront];
                arr[qfront] = -1;
                qfront++;

                if(qfront==rear){
                    qfront=0;
                    rear=0;
                }
                return curr;
            }
        }
        int front(){
            if(qfront == rear){
                return -1;
            }
            return arr[qfront];
        }
        bool empty(){
            if(qfront==rear){
                return true;
            }else{
                return false;
            }
        }
};

int main()
{
    /*
    queue<int> q;

    q.push(10);
    cout<<"Font of queue is: "<<q.front()<<endl;
    q.push(20);
    cout<<"Font of queue is: "<<q.front()<<endl;
    q.push(30);
    cout<<"Font of queue is: "<<q.front()<<endl;

    cout<<"Size of Queue: "<<q.size()<<endl;

    q.pop();
    // q.pop();
    // q.pop();

    cout<<"Font of queue is: "<<q.front()<<endl;

    cout<<"Size of Queue"<<q.size()<<endl;

    if(q.empty()){
        cout<<"Queue is empty"<<endl;
    }else{
        cout<<"Queue is not empty"<<endl;
    }
    */

    Queue q(5);

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    cout<<"Queue Front is : "<<q.front()<<endl;
    q.pop();
    cout<<"Queue Front is : "<<q.front()<<endl;
    // q.push(100);
    if(q.empty()){
        cout<<"Queue is empty"<<endl;
    }else{
        cout<<"Queue is not empty"<<endl;
    }
    q.pop();
    q.pop();
    q.pop();
    cout<<"Queue Front is : "<<q.front()<<endl;
    q.pop();

    q.push(200);
    cout<<"Queue Front is : "<<q.front()<<endl;
    return 0;
}