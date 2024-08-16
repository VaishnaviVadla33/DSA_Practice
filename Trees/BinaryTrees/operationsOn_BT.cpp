#include <iostream>
#include <vector>
using namespace std;

class treeNode{
    public:
    int value;
    treeNode* left;
    treeNode* right;
    treeNode(int val){
        value=val;
        left=nullptr;
        right=nullptr;
    }
};

class BinaryTree{
    public:
    treeNode* root;
    BinaryTree(){
        root=nullptr;
    }

    void insertRoot(treeNode*& root1,int val){
        if(root1==nullptr){
            root1=new treeNode(val);
        }
        else{
            if(val< root1->value){
                insertRoot(root1->left , val);
            }
            else{
                if(val> root1->value){
                    insertRoot(root1->right , val);
                }
            }
        }
    }

    void search(treeNode* root1, int val, int depth=0){
        if (root1 == nullptr) {
            cout << "Element not found" << endl;
            return;
        }
        if(root1->value == val){
            cout<<"Element found at depth:"<<depth<<endl;
            return;
        }
        else{
            if(val< root1->value){
                search(root1->left , val,depth+1);
            }
            else{
                if(val> root1->value){
                    search(root1->right , val, depth+1);
                }
            }
        }
    }

     treeNode* findMin(treeNode* root1) {
        while (root1->left != nullptr) {
            root1 = root1->left;
        }
        return root1;
    }

    treeNode* deleteNode(treeNode* root1, int val) {
        if (root1 == nullptr) return root1;

        if (val < root1->value) {
            root1->left = deleteNode(root1->left, val);
        } else if (val > root1->value) {
            root1->right = deleteNode(root1->right, val);
        } else {
            // Node with only one child or no child
            if (root1->left == nullptr) {
                treeNode* temp = root1->right;
                delete root1;
                return temp;
            } else if (root1->right == nullptr) {
                treeNode* temp = root1->left;
                delete root1;
                return temp;
            }

            // Node with two children
            treeNode* temp = findMin(root1->right);

            // Copy the inorder successor's content to this node
            root1->value = temp->value;

            // Delete the inorder successor
            root1->right = deleteNode(root1->right, temp->value);
        }
        return root1;
    }
};

int main(){
    BinaryTree tree;
    tree.insertRoot(tree.root, 25);
    tree.insertRoot(tree.root, 15);
    tree.insertRoot(tree.root, 35);
    tree.insertRoot(tree.root, 10);
    tree.insertRoot(tree.root, 20);

    tree.search(tree.root, 15);
    tree.search(tree.root, 30);

    return 0;
}
