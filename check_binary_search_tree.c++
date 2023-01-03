#include<iostream>
#include<queue>
using namespace std;
template<typename T>
class binarySearchTreeNode{
public:
    T data;
    binarySearchTreeNode<T> *left;
    binarySearchTreeNode<T> *right;
    binarySearchTreeNode(T data){
        this->data = data;
        left = NULL;
        right = NULL;
    }
    ~binarySearchTreeNode(){
        delete left;
        delete right;
    }
};
binarySearchTreeNode<int> *takeInput(){
    int rootData;
    cout << "Enter data: ";
    cin >> rootData;
    if(rootData == -1){
        return NULL;
    }
    binarySearchTreeNode<int> *root = new binarySearchTreeNode<int>(rootData);
    binarySearchTreeNode<int> *leftChild = takeInput();
    binarySearchTreeNode<int> *rightChild = takeInput();
    root->left = leftChild;
    root->right = rightChild;
    return root;
}
binarySearchTreeNode<int> *takeInputLevelWise(){
    int rootData;
    cout << "Enter root data: ";
    cin >> rootData;
    if(rootData == -1){
        return NULL;
    }
    binarySearchTreeNode<int> *root = new binarySearchTreeNode<int>(rootData);
    queue<binarySearchTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size() != 0){
        binarySearchTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        int leftChildData;
        cout << "Enter left child of " << front->data << ": ";
        cin >> leftChildData;
        if(leftChildData != -1){
            binarySearchTreeNode<int> *child = new binarySearchTreeNode<int>(leftChildData);
            front->left = child;
            pendingNodes.push(child);
        }
        int rightChildData;
        cout << "Enter right child of " << front->data << ": ";
        cin >> rightChildData;
        if(rightChildData != -1){
            binarySearchTreeNode<int> *child = new binarySearchTreeNode<int>(rightChildData);
            front->right = child;
            pendingNodes.push(child);
        }
    }
    return root;
}
void printTree(binarySearchTreeNode<int> *root){
    if(root == NULL){
        return;
    }
    cout << root->data << ": ";
    if(root->left != NULL){
        cout << "L" << root->left->data << " ";
    }
    if(root->right != NULL){
        cout << "R" << root->right->data;
    }
    cout << endl;
    printTree(root->left);
    printTree(root->right);
}

// check if a binary tree is BST or not
int maximum(binarySearchTreeNode<int> *root){
    if(root == NULL){
        return INT_MIN;
    }
    return max(root->data, max(maximum(root->left), maximum(root->right)));
}
int minimum(binarySearchTreeNode<int> *root){
    if(root == NULL){
        return INT_MAX;
    }
    return min(root->data, min(minimum(root->left), minimum(root->right)));
}

bool isBST(binarySearchTreeNode<int> *root){
    if(root == NULL){
        return true;
    }
    int leftMax = maximum(root->left);
    int rightMin = minimum(root->right);
    bool output = (root->data > leftMax) && (root->data <= rightMin) && isBST(root->left) && isBST(root->right);
    return output;
}

vector<int>* getRootToNodePath(binarySearchTreeNode<int> *root, int data){
    if(root == NULL){
        return NULL;
    }
    if(root->data == data){
        vector<int> *output = new vector<int>();
        output->push_back(root->data);
        return output;
    }
    vector<int> *leftOutput = getRootToNodePath(root->left, data);
    if(leftOutput != NULL){
        leftOutput->push_back(root->data);
        return leftOutput;
    }
    vector<int> *rightOutput = getRootToNodePath(root->right, data);
    if(rightOutput != NULL){
        rightOutput->push_back(root->data);
        return rightOutput;
    }
    else{
        return NULL;
    }
}
//1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
int main(){
    binarySearchTreeNode<int> *root = takeInputLevelWise();
    printTree(root);
    if(isBST(root)){
        cout << "Yes, it is a BST" << endl;
    }
    else{
        cout << "No, it is not a BST" << endl;
    }
    vector<int> *output = getRootToNodePath(root, 8);
    for(int i = 0; i < output->size(); i++){
        cout << output->at(i) << " ";
    }
    delete output;

    delete root;
}