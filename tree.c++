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
    ~Tree() {
        for(int i=0;i<children.size();i++) {
            delete children[i];
        }
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
void printTreeLevelWise(Tree<int>* root) {
    queue<Tree<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size()!=0) {
        Tree<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout<<front->data<<":";
        for(int i=0;i<front->children.size();i++) {
            if(i<front->children.size()-1) {
                cout<<front->children[i]->data<<",";
            }
            else {
                cout<<front->children[i]->data;
            }
            pendingNodes.push(front->children[i]);
        }
        cout<<endl;
    }
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
int numNode(Tree<int>* root) {
    if(root == NULL) {
        return 0;
    }
    int ans = 1;
    for(int i=0;i<root->children.size();i++) {
        ans = ans + numNode(root->children[i]);
    }
    return ans;
}
int height(Tree<int>* root) {
    if(root == NULL) {
        return 0;
    }
    int ans = 0;
    for(int i=0;i<root->children.size();i++) {
        int childHeight = height(root->children[i]);
        if(childHeight > ans) {
            ans = childHeight;
        }
    }
    return ans+1;
}
void printAtLevelK(Tree<int>* root, int k) {
    if(root == NULL) {
        return;
    }
    if(k == 0) {
        cout<<root->data<<endl;
        return;
    }
    for(int i=0;i<root->children.size();i++) {
        printAtLevelK(root->children[i], k-1);
    }
}
void preoder(Tree<int>* root) {
    if(root == NULL) {
        return;
    }
    cout<<root->data<<" ";
    for(int i=0;i<root->children.size();i++) {
        preoder(root->children[i]);
    }
}
void postorder(Tree<int>* root) {
    if(root == NULL) {
        return;
    }
    for(int i=0;i<root->children.size();i++) {
        postorder(root->children[i]);
    }
    cout<<root->data<<" ";
}
void deleteTree(Tree<int>* root) {
    for(int i=0;i<root->children.size();i++) {
        deleteTree(root->children[i]);
    }
    delete root;
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
    printTreeLevelWise(root);
    cout<<"Number of nodes in tree is "<<numNode(root)<<endl;


    return 0; 

}
