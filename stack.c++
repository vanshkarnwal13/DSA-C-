#include<iostream>
using namespace std;

class stack{
    int *data;
    int nextindex;
    int capacity;
    public:

    stack(int size){
        data = new int[size];
        nextindex=0;
        capacity=size;
    }
    int size(){
        return nextindex;
    }
    bool empty(){
        return nextindex=0;
    }

void push(int element){
    if(nextindex==capacity){
        cout <<"stack full" <<endl;
        return;
    }
    data[nextindex]=element;
    nextindex++;
}
int pop(){
    if(nextindex==0){
        cout<<"empty stack"<<endl;

    }
    nextindex=nextindex-1;
    return data[nextindex];
    
}
int top(){
    return data[nextindex-1];
}
};
int main(){
    stack s(4);
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    cout<<s.top()<<endl;
    cout<<s.size()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.top()<<endl;
    cout<<s.empty()<<endl;

}