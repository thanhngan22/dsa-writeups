#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

// function enter a linked list
void enterLinkedList(Node *&head, int data) {
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
    } else {
        Node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// function print a linked list
void printLinkedList(Node *head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// function merge two sorted linked list
Node *mergeTwoSortedLinkedList(Node *head1, Node *head2) {
    Node *mergeList = NULL;
    while (head1 != NULL && head2 != NULL) {
        if (head1->data < head2->data) {
            enterLinkedList(mergeList, head1->data);
            head1 = head1->next;
        } else {
            enterLinkedList(mergeList, head2->data);
            head2 = head2->next;
        }
    }
    if (head1 != NULL ) {
        while (head1 != NULL) {
            enterLinkedList(mergeList, head1->data);
            head1 = head1->next;
        }
    } 
    if (head2 != NULL) {
        while (head2 != NULL) {
            enterLinkedList(mergeList, head2->data);
            head2 = head2->next;
        }
    }
    
    return mergeList;
}

int main() {
    // enter the first linked list
    int n1;
    cout << "Enter the number of elements in the first linked list: ";
    cin >> n1;
    Node *head1 = NULL;
    cout << "Enter the elements: ";
    for (int i = 0; i < n1; i++) {
        int data;
        cin >> data;
        enterLinkedList(head1, data);
    }

    // enter the second linked list
    int n2;
    cout << "Enter the number of elements in the second linked list: ";
    cin >> n2;
    Node *head2 = NULL;
    cout << "Enter the elements: ";
    for (int i = 0; i < n2; i++) {
        int data;
        cin >> data;
        enterLinkedList(head2, data);
    }

    Node *mergeList = mergeTwoSortedLinkedList(head1, head2);

    // print the merged linked list
    cout << "The merged linked list is: ";
    printLinkedList(mergeList);

    return 225;
}