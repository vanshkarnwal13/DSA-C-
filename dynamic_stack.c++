#include<iostream>
using namespace std;

class stack{
    int *data;
    int nextindex;
    int capacity;
    public:

    stack(){
        data = new int[4];
        nextindex=0;
        capacity=4;
    }
    int size(){
        return nextindex;
    }
    bool empty(){
        return nextindex=0;
    }

void push(int element){
    if(nextindex==capacity){
        int *newdata=new int[2*capacity];
        for(int i=0;i<capacity;i++){
            newdata[i]=data[i];
        }
        capacity=2*capacity;
        delete [] data;
        data=newdata;

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
    stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);
    cout<<s.top()<<endl;
    cout<<s.size()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.top()<<endl;
    cout<<s.empty()<<endl;

}