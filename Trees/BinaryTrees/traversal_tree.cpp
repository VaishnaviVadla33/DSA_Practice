//using structures and functions
#include <stdio.h>
#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int val){
    //allocating memory to node1
    Node* node1=new Node();
    //assignning values to root data and its childrens(right and left nodes set to null)
    node1->data=val;
    node1->left=node1->right=nullptr;
    return node1;
}

void inorder(Node* root){
    
    if(root==nullptr){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
    return;
}

void preorder(Node* root){
    
    if(root==nullptr){
        return;
    }

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
    return;
}

void postorder(Node* root){
    
    if(root==nullptr){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
    return;
}

int main(){
    Node* root=newNode(1);
    root->left=newNode(2);
    root->right=newNode(3);
    root->left->left=newNode(4);
    root->left->right=newNode(5);
    cout<<"Inorder traversal is:"<<endl;
    inorder(root);
    cout<<endl;
    cout<<"preorder traversal is:"<<endl;
    preorder(root);
    cout<<endl;
    cout<<"postorder traversal is:"<<endl;
    postorder(root);
    cout<<endl;

}