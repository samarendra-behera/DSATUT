#include <iostream>
using namespace std;

class CircularQueue
{
    int *arr;
    int front, size, rear;

public:
    CircularQueue(int size)
    {
        this->size = size;
        arr = new int[size];
        front = rear = -1;
    }

    bool enqueue(int val)
    {
        if ((front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1)))
        {
            return false;
        }
        else
        {
            if (front == -1 && rear == -1)
            {
                front = rear = 0;
            }
            else if (rear == size - 1 && front != 0)
            {
                rear = 0;
            }
            else
            {
                rear++;
            }
        }
        arr[rear] = val;
        return true;
    }
    int dequeue()
    {

        if (front == -1)
        {
            return -1;
        }
        int curr = arr[front];
        arr[front] = -1;
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else if (front == size - 1)
        {
            front = 0;
        }
        else
        {
            front++;
        }
        return curr;
    }
    int Front()
    {
        if (front == -1)
        {
            return -1;
        }
        return arr[front];
    }
    int Rear()
    {
        if (front == -1)
        {
            return -1;
        }
        return arr[rear];
    }

    bool isEmpty()
    {
        if (front == -1)
        {
            return true;
        }
        return false;
    }

    bool isFull()
    {
        if ((front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1)))
        {
            return true;
        }
        return false;
    }
};

int main()
{
    CircularQueue q(3);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    bool b = q.enqueue(4);
    cout << b << endl;
    cout << q.Rear() << endl;
    cout << q.Front() << endl;
    return 0;
}
