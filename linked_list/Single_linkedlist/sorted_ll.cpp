#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {  // Constructor to assign data and pointer of next node address to current node
        this->data = data;
        this->next = nullptr;
    }
};

class SortedLinkedList {
private:
    Node* head;

    // Function to swap the nodes
    Node* swap(Node* ptr1, Node* ptr2) {
        Node* tmp = ptr2->next;
        ptr2->next = ptr1;
        ptr1->next = tmp;
        return ptr2;
    }

public:
    SortedLinkedList() {
        this->head = nullptr; // Initializing head having no address as there is no node yet
    }

    // Function to insert a Node at the beginning of the linked list
    void insertAtTheBegin(int data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    // Function to sort the list using Bubble Sort
    void bubbleSort(int count) {
        Node** h;
        int i, j, swapped;

        for (i = 0; i < count; i++) {
            h = &head;
            swapped = 0;

            for (j = 0; j < count - i - 1; j++) {
                Node* p1 = *h;
                Node* p2 = p1->next;

                if (p1->data > p2->data) {
                    // Update the link after swapping
                    *h = swap(p1, p2);
                    swapped = 1;
                }

                h = &(*h)->next;
            }

            // Break if the loop ended without any swap
            if (swapped == 0)
                break;
        }
    }

    // Function to print the list
    void printList() {
        Node* n = head;
        while (n != nullptr) {
            cout << n->data << " -> ";
            n = n->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    int arr[] = { 78, 20, 10, 32, 1, 5 };
    int list_size = sizeof(arr) / sizeof(arr[0]);

    SortedLinkedList list;

    // Create linked list from the array arr[]
    for (int i = list_size - 1; i >= 0; i--) {
        list.insertAtTheBegin(arr[i]);
    }

    // Print list before sorting
    cout << "Linked list before sorting" << endl;
    list.printList();

    // Sort the linked list
    list.bubbleSort(list_size);

    // Print list after sorting
    cout << "Linked list after sorting" << endl;
    list.printList();

    return 0;
}
