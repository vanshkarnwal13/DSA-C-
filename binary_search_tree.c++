#include<iostream>
using namespace std;
class BinaryTreeNode{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;
    BinaryTreeNode(T data){
        this->data = data;
        left = NULL;
        right = NULL;
    }
    ~BinaryTreeNode(){
        delete left;
        delete right;
    }
};
class BST{
    BinaryTreeNode<int> *root;
    public:
    BST(){
        root = NULL;
    }
    ~BST(){
        delete root;
    }
    private:
    BinaryTreeNode<int> *insert(BinaryTreeNode<int> *node, int data){
        if(node == NULL){
            BinaryTreeNode<int> *newNode = new BinaryTreeNode<int>(data);
            return newNode;
        }
        if(data < node->data){
            node->left = insert(node->left, data);
        }
        else{
            node->right = insert(node->right, data);
        }
        return node;
    }
    void printTree(BinaryTreeNode<int> *node){
        if(node == NULL){
            return;
        }
        cout << node->data << ": ";
        if(node->left != NULL){
            cout << "L" << node->left->data << ", ";
        }
        if(node->right != NULL){
            cout << "R" << node->right->data;
        }
        cout << endl;
        printTree(node->left);
        printTree(node->right);
    }
    bool hasData(BinaryTreeNode<int> *node, int data){
        if(node == NULL){
            return false;
        }
        if(node->data == data){
            return true;
        }
        else if(data < node->data){
            return hasData(node->left, data);
        }
        else{
            return hasData(node->right, data);
        }
    }
    BinaryTreeNode<int> *deleteData(BinaryTreeNode<int> *node, int data){
        if(node == NULL){
            return NULL;
        }
        if(data < node->data){
            node->left = deleteData(node->left, data);
            return node;
        }
        else if(data > node->data){
            node->right = deleteData(node->right, data);
            return node;
        }
        else{
            if(node->left == NULL && node->right == NULL){
                delete node;
                return NULL;
            }
            else if(node->left == NULL){
                BinaryTreeNode<int> *temp = node->right;
                node->right = NULL;
                delete node;
                return temp;
            }
            else if(node->right == NULL){
                BinaryTreeNode<int> *temp = node->left;
                node->left = NULL;
                delete node;
                return temp;
            }
            else{
                BinaryTreeNode<int> *minNode = node->right;
                while(minNode->left != NULL){
                    minNode = minNode->left;
                }
                int rightMin = minNode->data;
                node->data = rightMin;
                node->right = deleteData(node->right, rightMin);
                return node;
            }
        }
    }
    public:
    void insert(int data){
        this->root = insert(root, data);
    }
    bool hasData(int data){
        return hasData(root, data);
    }
    void printTree(){
        printTree(root);
    }
    void delete(int data){
        deleteData(root, data);
    }

};

int main(){
    BST *tree = new BST();
    cout<<"1. Insert\n2. Search\n3. Delete\n4. Print\n";
    int choice, input;
    while(true){
        cin >> choice;
        switch(choice){
            case 1:
                cin >> input;
                tree->insert(input);
                break;
            case 2:
                cin >> input;
                cout << (tree->hasData(input) ? "true" : "false") << endl;
                break;
            case 3:
                cin >> input;
                tree->delete(input);
                break;
            case 4:
                tree->printTree();
                break;
            default:
                return 0;
        }
    }
}