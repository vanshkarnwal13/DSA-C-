#include<iostream>
#include<vector>
using namespace std;

//using complete binary tree
class priority_queue{
    vector<int> pq;
    public:
    priority_queue(){
        
    }
    bool isEmpty(){
        return pq.size()==0;
    }
    int getSize(){
        return pq.size();
    }
    int getMin(){
        if(isEmpty()){
            return 0;
        }
        return pq[0];
    }
    void insert(int element){
        pq.push_back(element);
        int childIndex=pq.size()-1;
        while(childIndex>0){
            int parentIndex=(childIndex-1)/2;
            if(pq[childIndex]<pq[parentIndex]){
                int temp=pq[childIndex];
                pq[childIndex]=pq[parentIndex];
                pq[parentIndex]=temp;
            }
            else{
                break;
            }
            childIndex=parentIndex;
        }
    }
    int removeMin(){
        if(isEmpty()){
            return 0;
        }
        int ans=pq[0];
        pq[0]=pq[pq.size()-1];
        pq.pop_back();
        int parentIndex=0;
        int leftChildIndex=2*parentIndex+1;
        int rightChildIndex=2*parentIndex+2;
        while(leftChildIndex<pq.size()){
            int minIndex=parentIndex;
            if(pq[minIndex]>pq[leftChildIndex]){
                minIndex=leftChildIndex;
            }
            if(rightChildIndex<pq.size() && pq[minIndex]>pq[rightChildIndex]){
                minIndex=rightChildIndex;
            }
            if(minIndex==parentIndex){
                break;
            }
            int temp=pq[minIndex];
            pq[minIndex]=pq[parentIndex];
            pq[parentIndex]=temp;
            parentIndex=minIndex;
            leftChildIndex=2*parentIndex+1;
            rightChildIndex=2*parentIndex+2;
        }
        return ans;
    }
};
int main(){
    priority_queue pq;
    cout<<"1. insert"<<" "<<"2. removeMin"<<" "<<"3. getMin"<<" "<<"4. getSize"<<" "<<"5. isEmpty"<<" "<<"-1. exit"<<endl;

    int choice;
    cout<<"enter choice:"<<endl;
    cin>>choice;
    while(choice!=-1){
        switch(choice){
            case 1:
                int element;
                cout<<"enter element:"<<endl;
                cin>>element;
                pq.insert(element);
                break;
            case 2:
                cout<<pq.removeMin()<<endl;
                break;
            case 3:
                cout<<pq.getMin()<<endl;
                break;
            case 4:
                cout<<pq.getSize()<<endl;
                break;
            case 5:
                if(pq.isEmpty()){
                    cout<<"true"<<endl;
                }
                else{
                    cout<<"false"<<endl;
                }
                break;
            default:
                return 0;
        }
        cin>>choice;
    }
}

   