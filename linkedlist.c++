#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data=data;
        next=NULL;
    }

};
Node * input(){
    int data;
    cin>>data;
    Node *head=NULL;
    Node *tail=NULL;
    while(data!=-1){
        Node *newNode=new Node(data);
        if(head==NULL){
            head=newNode;
            tail=newNode;
        }
        else{
            tail->next=newNode;
            tail=newNode;
        }
        cin>>data;
    }
    return head;
}
void print(Node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }

}
Node* insert(Node* head,int i,int data){
    Node *newNode=new Node(data);
    int count=0;
    Node *temp=head;
    if(i==0){
        newNode->next=head;
        head=newNode;
        return head;
    }
    while(temp!=NULL && count<i-1){
        temp=temp->next;
        count++;
    }
    if(temp!=NULL){
        Node *a=temp->next;
        temp->next=newNode;
        newNode->next=a;
    }
    return head;

}

Node* Delete(Node* head,int i){
    int count=0;
    Node *temp=head;
    if(i==0){
        head=head->next;
        return head;
    }
    while(temp!=NULL && count<i-1){
        temp=temp->next;
        count++;
    }
    if(temp!=NULL){
        Node *a=temp->next;
        temp->next=a->next;
        delete a;
    }
    return head;

}
int main(){
    Node* head =input();
    print(head);
    int i,data;
    cin>>i>>data;
    head=insert(head,i,data);
    print(head);
    cin>>i;
    head=Delete(head,i);
    print(head);
    
    return 0;




    // //static
    // Node n1(1);
    // Node *head=&n1;
    // Node n2(2);
    // n1.next=&n2;
    // print(head);
    // //cout<<n1.data<<" "<<n2.data<<endl;

    // //dynamic
    // Node *n3=new Node(10);
    // Node *heaf=n3;
    // Node *n4=new Node(20);
    // n3->next=n4;
     
 

}