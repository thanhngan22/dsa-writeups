#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
    int data;
    Node *next;
};

// insert node at the end of the list
void insert(Node **head, int data) {
    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

bool hasCycle(Node *head) {
    if (head == NULL) {
        return false;
    }
    vector <int> v;
    while (head != NULL) {
        if (find(v.begin(), v.end(), head->data) != v.end()) {
            return true;
        } else {
            v.push_back(head->data);
        }
        head = head->next;
    }
    return false;

    // NOT FINISHED, NEED FIX BUGS LATER

}

int main() {
    int n;
    cin >> n;
    Node *head = NULL;
    for (int i = 0; i < n; i++) {
        int data;
        cin >> data;
        insert(&head, data);
    }

    if (hasCycle(head)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 225;
}