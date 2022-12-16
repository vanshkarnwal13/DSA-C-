#include<iostream>
using namespace std;
class node{
public:
    int data;
    node *next;
    node(int data){
        this->data = data;
        next = NULL;

    }
};
class stack{
    node *head;
    int size;
    public:
    stack(){
        head = NULL;
        size = 0;
    }
    int getsize(){
        return size;
    }
    bool isempty(){
        return size == 0;
    }
    void push(int element){
        node *newnode = new node(element);
        newnode->next = head;
        head = newnode;
        size++;
    }
    int pop(){
        if(isempty()){
            cout<<"Stack is empty"<<endl;
            return 0;
        }
        int ans = head->data;
        node *temp = head;
        head = head->next;
        delete temp;
        size--;
        return ans;
    }
    int top(){
        if(isempty()){
            cout<<"Stack is empty"<<endl;
            return 0;
        }
        return head->data;
    }

};
int main(){
    stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    cout<<s.top()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.top()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.top()<<endl;
    cout<<s.getsize()<<endl;   

}