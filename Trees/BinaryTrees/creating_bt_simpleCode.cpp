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
};

int main(){
    BinaryTree tree;
    tree.root=new treeNode(25);
    return 0;
}
