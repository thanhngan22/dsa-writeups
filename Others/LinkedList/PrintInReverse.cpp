#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

void printInReverse(Node *head) {
    if (head == NULL) {
        return;
    }
    printInReverse(head->next);
    cout << head->data << " ";
}

int main() {
    // enter a linked list
    int n;
    cin >> n;
    Node *head = NULL;
    for (int i = 0 ; i < n; i++) {
        int x;
        cin >> x;
        Node *temp = new Node();
        temp->data = x;
        temp->next = NULL;
        if (head == NULL) {
            head = temp;

        } else {
            Node *p = head;
            while (p->next != NULL) {
                p = p->next;
            }
            p->next = temp;
        }
    }

    printInReverse(head);

    return 225;

}