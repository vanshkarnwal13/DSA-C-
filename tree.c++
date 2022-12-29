#include<iostream>
#include<queue>
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

};
Tree<int>* takeInputLevelWise(){
    int rootData;
    cout<<"Enter root data"<<endl;
    cin>>rootData;
    Tree<int>* root = new Tree<int>(rootData);
    queue<Tree<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size()!=0) {
        Tree<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout<<"Enter number of children of "<<front->data<<endl;
        int numChild;
        cin>>numChild;
        for(int i=0;i<numChild;i++) {
            int childData;
            cout<<"Enter "<<i<<"th child of "<<front->data<<endl;
            cin>>childData;
            Tree<int>* child = new Tree<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}
Tree<int>* takeInput() {
    int rootData;
    cout<<"Enter data"<<endl;
    cin>>rootData;
    Tree<int>* root = new Tree<int>(rootData);
    int n;
    cout<<"Enter number of children of "<<rootData<<endl;
    cin>>n;
    for(int i=0;i<n;i++) {
        Tree<int>* child = takeInput();
        root->children.push_back(child);
    }
    return root;
}
void printTree(Tree<int>* root) {
    if(root == NULL) {
        return;
    }
    cout<<root->data<<":";
    for(int i=0;i<root->children.size();i++) {
        cout<<root->children[i]->data<<",";
    }
    cout<<endl;
    for(int i=0;i<root->children.size();i++) {
        printTree(root->children[i]);
    }
}
int main(){
    // Tree<int>* root = new Tree<int>(1);
    // Tree<int>* node1 = new Tree<int>(2);
    // Tree<int>* node2 = new Tree<int>(3);
    // root->children.push_back(node1);
    // root->children.push_back(node2);
    // cout<<root->data<<endl;
    // cout<<root->children[0]->data<<endl;
    // cout<<root->children[1]->data<<endl;
    Tree<int>* root = takeInputLevelWise();
    printTree(root);

    return 0; 

}
