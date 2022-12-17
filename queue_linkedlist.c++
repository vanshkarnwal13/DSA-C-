#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node *next;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }

};
class queue{
    Node *head;
    Node *tail;
    int size;
    public:
    queue(){
        head = NULL;
        tail = NULL;
        size = 0;
    }
    int getsize(){
        return size;
    }
    bool isempty(){
        return size == 0;
    }
    void enqueue(int data){
        Node *newnode = new Node(data);
        if(head == NULL){
            head = newnode;
            tail = newnode;
        }
        else{
            tail->next = newnode;
            tail = newnode;
        }
        size++;
    }
    int dequeue(){
        if(isempty()){
            return 0;
        }
        int ans = head->data;
        Node *temp = head;
        head = head->next;
        delete temp;
        size--;
        return ans;
    }
    int front(){
        if(isempty()){
            return 0;
        }
        return head->data;
    }
};
int main(){
    queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    cout<<q.getsize()<<endl;
    cout<<q.front()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.front()<<endl;
    cout<<q.getsize()<<endl;
    cout<<q.isempty()<<endl;
}

