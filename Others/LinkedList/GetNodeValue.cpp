// determine the data value at the given position counting from the tail

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

// insert node function
void insertNode(Node *&head, int data) {
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

// get value node function
int getNode(Node *head, int pos) {
    // get the value of the node at a given position counting from the tail
    Node *temp = head;
    int count = 0;
    while (temp != NULL) {
        temp = temp->next;
        count++;
    }
    int posFromHead = count - pos - 1;
    temp = head;
    for (int i = 0; i < posFromHead; i++) {
        temp = temp->next;
    }
    return temp->data;

}

int main() {
    int n;
    cin >> n;
    Node *head = NULL;
    for (int i = 0; i < n; i++) {
        int data;
        cin >> data;
        insertNode(head, data);
    }
    int pos;
    cout << "Enter the position: ";
    cin >> pos;
    cout << "value of " << pos << "th element: " << getNode(head, pos);

    return 225;

}