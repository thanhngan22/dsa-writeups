#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node (int data) {
        this->data = data;
        next = NULL;
    }
};

// insert node at the end of the list
void insert(Node **head, Node *&node) {
    if (*head == NULL) {
        *head = node;
        return;
    }
    Node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = node;
}

bool hasCycle(Node *head) {
   Node *temp = head;
   if (head == NULL || head->next == NULL) {
         return false;
   }

   Node *p = head;
   while (head != NULL && head->next != NULL) {
    while (p != head) {
        if (p == head->next) {
            return true;
        }
        p = p->next;
    }
    head = head->next;
    p = temp;
   }
   return false;
}

int main() {
    Node *head = NULL;
    Node *first = new Node(1);
    Node *second = new Node(2);
    Node *third = new Node(3);

    insert(&head, first);
    insert(&head, second);
    insert(&head, third);
    third->next = second;

    if (hasCycle(head)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 225;
}