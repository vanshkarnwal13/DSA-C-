#include<iostream>
#include<vector>
using namespace std;
template<typename T>
class Tree {
    public:
    T data;
    vector<Tree<T>*> children;
    Tree(T data) {
        this->data = data;
    }

}
int main(){
    Tree<int>* root = new Tree<int>(1);
    Tree<int>* node1 = new Tree<int>(2);
    Tree<int>* node2 = new Tree<int>(3);
    root->children.push_back(node1);
    root->children.push_back(node2);
    cout<<root->data<<endl;
    cout<<root->children[0]->data<<endl;
    cout<<root->children[1]->data<<endl;
    return 0; 

}