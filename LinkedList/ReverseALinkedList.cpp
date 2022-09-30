#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

Node *reverse(Node *&head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    Node *rest = reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return rest;
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

    head = reverse(head);

    // print the linked list

    Node *p = head;
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }

    return 225;

}