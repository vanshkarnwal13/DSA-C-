#include<iostream>
#include<vector>

using namespace std;
int main(){
    vector<int> v;
    //vector<int> *vp = new vector<int>;
    for(int i=0;i<5;i++){
        v.push_back(i);
    }
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<v.size();i++){
        cout<<v.at(i)<<" ";
    }
    cout<<endl;
    v.pop_back();
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}