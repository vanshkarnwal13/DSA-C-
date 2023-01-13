#include<iostream>
#include<string>
using namespace std;

template<typename V>
class MapNode{
    public:
    string key;
    V value;
    MapNode* next;
    MapNode(string key, V value){
        this->key=key;
        this->value=value;
        next=NULL;
    }
    ~MapNode(){
        delete next;
    }
};
template<typename V>
class ourmap{
    MapNode<V>** buckets;
    int count;
    int numBuckets;
    public:
    ourmap(){
        count=0;
        numBuckets=5;
        buckets = new MapNode<V>*[numBuckets];
        for(int i=0;i<numBuckets;i++){
            buckets[i]=NULL;
        }
    }
    ~ourmap(){
        for(int i=0;i<numBuckets;i++){
            delete buckets[i];
        }
        delete [] buckets;
    }
    int size(){
        return count;
    }
    V getValue(string key){
        int bucketindex = getbucketindex(key);
        MapNode<V>* head = buckets[bucketindex];
        while(head!=NULL){
            if(head->key==key){
                return head->value;
            }
            head=head->next;
        }
        return 0;

    }
    private:
    int getbucketindex(string key){
        int hashcode=0;
        int currentcoeff =1;
        //"abc"=a*p3+b*p2+c*p1+d*p0
        for(int i=key.length()-1;i>=0;i--){
            hashcode+=key[i]*currentcoeff;
            hashcode=hashcode%numBuckets;
            currentcoeff*=37;
            currentcoeff=currentcoeff%numBuckets;
        }

        return hashcode%numBuckets;
    }

    void rehash(){
        MapNode<V>** temp = buckets;
        buckets = new MapNode<V>*[2*numBuckets];
        for(int i=0;i<2*numBuckets;i++){
            buckets[i]=NULL;
        }
        int oldbucketcount = numBuckets;
        numBuckets*=2;
        count=0;
        for(int i=0;i<oldbucketcount;i++){
            MapNode<V>* head = temp[i];
            while(head!=NULL){
                string key = head->key;
                V value = head->value;
                insert(key,value);
                head=head->next;
            }
        }
        for(int i=0;i<oldbucketcount;i++){
            MapNode<V>* head = temp[i];
            delete head;
        }
        delete [] temp;
    }
    public:
    double getLoadFactor(){
        return (1.0*count)/numBuckets;
    }
    void insert(string key, V value){
        int bucketindex = getbucketindex(key);
        MapNode<V>* head = buckets[bucketindex];
        while(head!=NULL){
            if(head->key==key){
                head->value=value;
                return;
            }
            head=head->next;
        }
        head = buckets[bucketindex];
        MapNode<V>* node = new MapNode<V>(key,value);
        node->next=head;
        buckets[bucketindex]=node;
        count++;

        //rehashing
        double loadfactor = (1.0*count)/numBuckets;
        if(loadfactor>0.7){
            rehash();
        }
    }


    V remove(string key){
        int bucketindex = getbucketindex(key);
        MapNode<V>* head = buckets[bucketindex];
        MapNode<V>* prev = NULL;
        while(head!=NULL){
            if( head->key==key){
                if(prev==NULL){
                    buckets[bucketindex]=head->next;
                }
                else{
                prev->next=head->next;
                }
                V value=head->value;
                head->next=NULL;
                delete head;
                count--;
                return value;
            }
            prev=head;
            head=head->next;
        }
        return 0;
    }
};

int main(){
    ourmap<int> map;
    for(int i=0;i<10;i++){
        char c='0'+i;
        string key="abc";
        key=key+c;
        int value=i+1;
        map.insert(key,value);
        cout<<map.getLoadFactor()<<endl;
    }
    cout<<map.size()<<endl;
    map.remove("abc2");
    map.remove("abc7");
    for(int i=0;i<10;i++){
        char c='0'+i;
        string key="abc";
        key=key+c;
        cout<<key<<":" <<map.getValue(key)<<endl;
    }

    cout<<map.size()<<endl;

    return 0;
}