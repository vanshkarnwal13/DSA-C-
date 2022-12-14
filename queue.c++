#include<iostream>
using namespace std;
class Queue
{
    int *data;
    int front;
    int rear;
    int size;
    public:
    Queue(int size)
    {
        data = new int[size];
        front = -1;
        rear = -1;
        this->size = size;
    }
    void enqueue(int x)
    {
        if(rear == size-1)
        {
            cout<<"Queue is full"<<endl;
            return;
        }
        else if(front == -1 && rear == -1)
        {
            front = rear = 0;
        }
        else
        {
            rear++;
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
            front++;
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
        if(rear == size-1)
        {
            return true;
        }
        return false;
    }
    int getSize()
    {
        return size;
    }
};
int main(){
    Queue q(5);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    cout<<q.getFront()<<endl;
    cout<<q.getRear()<<endl;
    q.dequeue();
    cout<<q.getFront()<<endl;
    cout<<q.getRear()<<endl;
    q.dequeue();
    cout<<q.getFront()<<endl;
    cout<<q.getRear()<<endl;
    q.dequeue();
    cout<<q.getFront()<<endl;
    cout<<q.getRear()<<endl;
    q.dequeue();
    cout<<q.getFront()<<endl;
    cout<<q.getRear()<<endl;
    
    return 0;
}
