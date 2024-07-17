#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class SortedLinkedList {
private:
    Node* head;

    Node* swap(Node* ptr1, Node* ptr2) {
        Node* tmp = ptr2->next;
        ptr2->next = ptr1;
        ptr1->next = tmp;
        return ptr2;
    }

public:
    SortedLinkedList() {
        this->head = nullptr;
    }

    void insertAtTheBegin(int data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

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
                    *h = swap(p1, p2);
                    swapped = 1;
                }

                h = &(*h)->next;
            }

            if (swapped == 0)
                break;
        }
    }

    void printList() {
        Node* n = head;
        while (n != nullptr) {
            cout << n->data << " -> ";
            n = n->next;
        }
        cout << "NULL" << endl;
    }

    // Function to merge two sorted linked lists
    static SortedLinkedList merge(SortedLinkedList& list1, SortedLinkedList& list2) {
        SortedLinkedList mergedList;
        Node* head1 = list1.head;
        Node* head2 = list2.head;
        Node** lastPtrRef = &(mergedList.head);

        while (true) {
            if (head1 == nullptr) {
                *lastPtrRef = head2;
                break;
            } else if (head2 == nullptr) {
                *lastPtrRef = head1;
                break;
            }

            if (head1->data <= head2->data) {
                MoveNode(lastPtrRef, &head1);
            } else {
                MoveNode(lastPtrRef, &head2);
            }

            lastPtrRef = &((*lastPtrRef)->next);
        }

        return mergedList;
    }

    static void MoveNode(Node** destRef, Node** sourceRef) {
        Node* newNode = *sourceRef;
        assert(newNode != nullptr);
        *sourceRef = newNode->next;
        newNode->next = *destRef;
        *destRef = newNode;
    }
};

int main() {
    int arr1[] = { 78, 20, 10, 32, 1, 5 };
    int arr2[] = { 99, 40, 25, 17, 9, 3 };
    int list_size1 = sizeof(arr1) / sizeof(arr1[0]);
    int list_size2 = sizeof(arr2) / sizeof(arr2[0]);

    SortedLinkedList list1;
    SortedLinkedList list2;

    for (int i = list_size1 - 1; i >= 0; i--) {
        list1.insertAtTheBegin(arr1[i]);
    }

    for (int i = list_size2 - 1; i >= 0; i--) {
        list2.insertAtTheBegin(arr2[i]);
    }

    cout << "Linked list 1 before sorting" << endl;
    list1.printList();
    list1.bubbleSort(list_size1);
    cout << "Linked list 1 after sorting" << endl;
    list1.printList();

    cout << "Linked list 2 before sorting" << endl;
    list2.printList();
    list2.bubbleSort(list_size2);
    cout << "Linked list 2 after sorting" << endl;
    list2.printList();

    SortedLinkedList mergedList = SortedLinkedList::merge(list1, list2);
    cout << "Merged linked list" << endl;
    mergedList.printList();

    return 0;
}
