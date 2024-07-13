#include <iostream>
using namespace std;

#include <iostream>
using namespace std;

class Node{

    public:
    int data;
    Node *next;

    Node(int data){  //constructor to assign data and pointer of next node address to current node
        this->data = data;
        this->next=nullptr;
        }
};

class linkedlist{
    private:
    Node *head;

    public:
    linkedlist(){
        this->head=nullptr; //initializing head having no address as their is node yet
    }

    void insertAtBeginning(int data){
        Node *newNode=new Node(data);  //creating a node whose pointer is newNode //creating node to insert
        newNode->next=head;            //assigning address of head i.e nullpointer to our newnode address/next part
        head=newNode;                  //assigning newNode pointer address to head  [head->newnode]
    }

    //==================================================================================

    void insertAtEnd(int data){
        Node *newNode= new Node(data);
        if(head==nullptr){                //if no nodes present, then first node will be assigned node
            head=newNode;                 //so head pointing to newNode(here both are pointers)
            return;
        }

        Node *temp =head;
        while(temp->next!=nullptr){          //searching till end to add node at end
            temp=temp->next;                 //if no end found, tranverse 
        }
        temp->next=newNode;                  //when last node found, assign its next pointer to our created node
    }

    //==================================================================================

    void insertAtPosition(int data1, int pos){          
        Node* newNode=new Node(data1);
        newNode->data=data1;
        Node* temp=head;
        for(int i=1;i<pos-1;i++){       //pos is pos-1 becuase we want to place the before the position
            temp=temp->next;
            if(temp==nullptr){
                cout<<"desired position is not available";
                return;                  // return strops the flow of function t, but break just stops the loop
            }            
        }
        newNode->next=temp->next;
        temp->next=newNode;
    }
    //==================================================================================

    void deleteAtBeginning(){
        if(head==nullptr){
            cout<<"List is empty"<<endl;
            return;
        }
        Node* temp;
        temp=head;             //store address/link of head in temporary variable so later it can be erased
        head=head->next;
        delete temp;                             // free used when memory is allocated using malloc free(temp);            

    }

    //==================================================================================

    void deleteAtEnd(){
        if(head==nullptr){
            cout<<"List is empty"<<endl;
            return;
        }

        Node* temp;
        Node* prevTemp;
        temp=head;
        while(temp->next!=nullptr){
            prevTemp=temp;
            temp=temp->next;
        }
        prevTemp->next=nullptr;
        delete temp;
    }

    //==================================================================================
    void DeleteAtPosition(int pos){
        if(head==nullptr){
            return;
        }
        Node* temp=head;
        Node* prevTemp;
        for(int i=0;i<pos-1;i++){
            prevTemp=temp;
            temp=temp->next;
            if(temp==nullptr){
                cout<<"desired position is not available";
                return;
            }
        }
        prevTemp->next=temp->next;
        delete temp;
    }
    //==================================================================================

    void printlist(){
        Node *temp = head;
        while(temp!=nullptr){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        
    }

    //==================================================================================
};
int main(){
    linkedlist l1;
    l1.insertAtBeginning(1);
    l1.insertAtBeginning(2);
    l1.insertAtBeginning(3);
    l1.insertAtEnd(4);
    l1.insertAtBeginning(5);
    l1.insertAtBeginning(6);
    l1.insertAtBeginning(7);
    l1.insertAtBeginning(8);
    l1.deleteAtEnd();
    l1.insertAtPosition(100,2);
    l1.DeleteAtPosition(2);
    l1.printlist();

    return 0;
}
