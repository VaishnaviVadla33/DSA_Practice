#include <iostream>
using namespace std;
#include <stdio.h>

// using class
class Node{
    int data;
    Node *next; // created a pointer called next to link to other nodes

    Node(int data){   // created a constructor to create a node 
        this->data=data;
        this->next=nullptr;
    }
};

//using structures
struct Node{
    int data;
    Node *next;

    Node(int data){
        this->data=data;
        this->next=nullptr;
    }
};