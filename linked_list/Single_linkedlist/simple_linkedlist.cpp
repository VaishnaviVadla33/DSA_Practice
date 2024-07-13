#include <iostream>
using namespace std;

class Node{
    private:
    int data;
    Node *next;

    public:
    Node(int data){
        this->data = data;
        this->next=nullptr;
        }
    int getdata(){
        return data;
    }

    Node* getnext(){
        return next;
    }
    
    void setnext(Node* nextNode){  //nextNode is a pointer to a Node
        this->next=nextNode;
    }
};

int main(){
    //creating nodes in linked list
    Node* head=new Node(1);
    head->setnext(new Node(2));
    head->getnext()->setnext(new Node(3));
    /*After executing the three lines:

        1.Node* head = new Node(1); creates the first node with value 1 and assigns its address to head.
        2.head->setNext(new Node(2)); creates the second node with value 2 and links it to the first node.
        3.head->getNext()->setNext(new Node(3)); creates the third node with value 3 and links it to the second node.
        The linked list is now:
        head -> [1 | next] -> [2 | next] -> [3 | next=nullptr]
        Each Node object is dynamically allocated, and the nodes are linked together using their next pointers.*/

    //traversal in ll
    Node* current=head;
    while(current!=nullptr){
        // cout<<current->data<<" "; data and next are private mem so we cant access directly
        cout << current->getdata() << " ";  // use getData() to access private member data
        current = current->getnext(); //current=current->next;
    }

    //deleting allocated memory
    current=head;
    Node* temp;
    while(current!=nullptr){
        temp=current;
        current=current->getnext();
        delete temp;
    }
    return 0;
}


/*
1.---------------------------------------------------------------------------------------
_______________________
|Node* current = head;|
|_____________________|
current is being declared as a pointer to Node and initialized to point to the same Node as head.
If you had:

_________________
|current = head;|
|_______________|
This would be valid only if current had already been declared earlier in the code. 
If current was not declared before, this would result in a compilation error.


2.-----------------------------------------------------------------------------------------------------------
The difference between Node* nextNode and Node *nextNode lies solely in the placement of the asterisk (*) 
in relation to the type and the variable name. They both functionally represent the same thing—a pointer to a Node object
—but they follow different stylistic conventions in how the pointer type is written.
*/