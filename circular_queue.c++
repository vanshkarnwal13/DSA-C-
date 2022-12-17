#include<iostream>
using namespace std;
class circularqueue{
    int *data;
    int front;
    int rear;
    int size;
    int capacity;
    public:
    circularqueue(int s)
    {
        data = new int[s];
        front = -1;
        rear = -1;
        size = 0;
        capacity = s;
    }
    void enqueue(int x)
    {
        if((rear+1)%capacity == front)
        {
            cout<<"Queue is full"<<endl;
            return;
        }
        else if(front == -1 && rear == -1)
        {
            front = rear = 0;
            size++;
        }
        else
        {
            rear = (rear+1)%capacity;
            size++;
        }
        data[rear] = x;
    }
    void dequeue()
    {
        if(front == -1 && rear == -1)
        {
            cout<<"Queue is empty"<<endl;
            return;
        }
        else if(front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front+1)%capacity;
            size--;
        }
    }
    int getFront()
    {
        if(front == -1 && rear == -1)
        {
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        return data[front];
    }
    int getRear()
    {
        if(front == -1 && rear == -1)
        {
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        return data[rear];
    }
    bool isEmpty()
    {
        if(front == -1 && rear == -1)
        {
            return true;
        }
        return false;
    }
    bool isFull()
    {
        if((rear+1)%capacity == front)
        {
            return true;
        }
        return false;
    }
    int getsize()
    {
        return size;
    }
};
int main()
{
    circularqueue q(5);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);
    cout<<q.getFront()<<endl;
    cout<<q.getRear()<<endl;
    q.dequeue();
    q.dequeue();
    cout<<q.getFront()<<endl;
    cout<<q.getRear()<<endl;
    cout<<q.isEmpty()<<endl;
    cout<<q.isFull()<<endl;
    cout<<q.getsize()<<endl;
    q.enqueue(10);
    q.enqueue(11);
    cout<<q.getFront()<<endl;
    cout<<q.getRear()<<endl;
    q.enqueue(12);
    q.enqueue(13);
    cout<<q.getFront()<<endl;
    cout<<q.getRear()<<endl;

    return 0;
}

