/*
Given the head of a singly linked list, swap every two nodes and return its head.

For example, given 1 -> 2 -> 3 -> 4, return 2 -> 1 -> 4 -> 3
*/


#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node (int data) {
        this->data = data;
        this->next = NULL;
    }
};


void printList(Node *head) {
    Node *temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void swapTwoNodes(Node *&head) {
    Node *swap = head;
    Node *prev = NULL;

    while (swap->next != NULL && swap != NULL) {
        Node *temp = swap->next;
        swap->next = temp->next;
        temp->next = swap;

        if (swap == head) {
            head = temp;
        } else {
            prev->next = temp;
        }
        prev = swap;
        swap = swap->next;

        printList(head); 
    }
}


int main() {
    Node *head = new Node(1);
    Node *second = new Node(2);
    Node *third = new Node(3);
    Node *fourth = new Node(4);

    head->next = second;
    second->next = third;
    third->next = fourth;

    fourth->next = new Node(5);
    fourth->next->next = new Node(6);
    fourth->next->next->next = new Node(7);
    fourth->next->next->next->next = new Node(8);

    swapTwoNodes(head);

    return 225;

}