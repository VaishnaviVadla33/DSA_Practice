#include<bits/stdc++.h>

using namespace std;

class node {
  public:
    int data;
  node * next;
  node * prev;
  node(int val) {
    data = val;
    next = NULL;
    prev = NULL;
  }
};

void insertAtTail(node * & head, int val) {
  node* new_node = new node(val);
  if (head == NULL) {
    head = new_node;
    return;
  }
  node * temp = head;
  while (temp -> next != NULL) {
    temp = temp -> next;
  }
  temp -> next = new_node;
  new_node -> prev = temp;
}

void insertAtHead(node * & head, int val) {
  node * ptr = new node(val);
  ptr -> next = head;
  if (head != NULL) {
    head -> prev = ptr;
  }
  head = ptr;
}

void insertAtMiddle(node * & head, int val, int pos) {
  node * ptr = new node(val);
  node * temp = head;
  for (int i = 0; i < pos - 2; i++) {
    temp = temp -> next;
  }
  ptr -> next = temp -> next;
  temp -> next = ptr;
  ptr -> prev = temp;
  if (ptr -> next != NULL) {
    ptr -> next -> prev = ptr;
  }
}

void deleteAtFirst(node * & head) {
  node * todelete = head;
  head = head -> next;
  head -> prev = NULL;
  delete todelete;
}

void deleteAtLast(node * & head) {
  if (head -> next == NULL) {
    deleteAtFirst(head);
    return;
  }
  node * temp = head;
  while (temp -> next != NULL) {
    temp = temp -> next;
  }
  temp -> prev -> next = NULL;
  free(temp);
}

void deleteAtposition(node * & head, int n) {
  if (n == 1) {
    deleteAtFirst(head);
    return;
  }
  node * temp = head;
  while (temp != NULL && n != 1) {
    temp = temp -> next;
    n--;
  }
  temp -> prev -> next = temp -> next;
  if (temp -> next != NULL) {
    temp -> next -> prev = temp -> prev;
  }
}

void display(node * head) {
  node * temp = head;
  while (temp != NULL) {
    cout << temp -> data << "-->";
    temp = temp -> next;
  }
  cout << "NULL\n";
}

int main() {
  node * head = NULL;
  insertAtTail(head, 2);
  insertAtTail(head, 3);
  insertAtTail(head, 4);
  insertAtTail(head, 5);
  insertAtTail(head, 6);
  display(head);
  insertAtHead(head, 1);
  display(head);
  insertAtMiddle(head, 7, 2);
  display(head);
  cout << "delete at the first:\n";
  deleteAtFirst(head);
  display(head);
  cout << "delete at the last:\n";
  deleteAtLast(head);
  display(head);
  cout << "delete at the particular position:\n";
  deleteAtposition(head, 3);
  display(head);

  return 0;
}