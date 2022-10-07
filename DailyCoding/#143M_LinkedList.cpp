/*
Given a pivot x, and a list lst, partition the list into three parts.

The first part contains all elements in lst that are less than x
The second part contains all elements in lst that are equal to x
The third part contains all elements in lst that are larger than x
Ordering within a part can be arbitrary.

For example, given x = 10 and lst = [9, 12, 3, 5, 14, 10, 10], one partition may be [9, 3, 5, 10, 10, 12, 14].
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

// hàm đẩy phần tử vào cuối danh sách liên kết mà vẫn giữ nguyên liên kết ban đầu
void pushBackNode (Node *prev, Node *node) {
    prev->next = node->next;
    Node *temp = prev;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = node;
    node->next = NULL;
}

void devidePartition(Node *head, int x) {
    Node *temp = head;
    
    // đẩy phần tử x vào cuối list

    // trường hợp x đứng đầu list
    while (head->data == x) {
        Node *prev = head->next;
        temp = head->next;
        while (temp != NULL && temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = head;
        temp->next->next = NULL;
        head = prev;
    }

    // trường hợp x đứng giữa list
    temp = head;
    while (temp->next != NULL) {
        if (temp ->next->data == x) {
            pushBackNode(temp, temp->next);
        }
        temp = temp->next;
    }
    printList(head);

    // dò từ đầu mảng đến cuối mảng nếu phần tử lớn hơn x thì đẩy về cuối danh sách
    temp = head;
    while (head->data > x) {
        Node *prev = head->next;
        pushBackNode(head, temp);
        head = prev;
        printList(head);
    }

    temp = head;
    while (temp->next != NULL && temp->data != x) {
        if (temp->next->data > x) {
            pushBackNode(temp, temp->next);
            printList(head);
        }
        temp = temp->next;
    }  
}

int main() {
    Node *head = new Node(9);
    head->next = new Node(12);
    head->next->next = new Node(3);
    head->next->next->next = new Node(5);
    head->next->next->next->next = new Node(14);
    head->next->next->next->next->next = new Node(10);
    head->next->next->next->next->next->next = new Node(10);

    Node *root = new Node(10);
    root->next = new Node(10);
    root->next->next = new Node(3);
    root->next->next->next = new Node(5);
    root->next->next->next->next = new Node(14);
    root->next->next->next->next->next = new Node(9);
    root->next->next->next->next->next->next = new Node(12);

    Node *root2 = new Node(17);
    root2->next = new Node(5);
    root2->next->next = new Node(3);
    root2->next->next->next = new Node(15);
    root2->next->next->next->next = new Node(10);
    root2->next->next->next->next->next = new Node(9);
    root2->next->next->next->next->next->next = new Node(12);

    printList(head);
    devidePartition(head, 10);

    cout << endl;

    printList(root);
    devidePartition(root, 10);

    cout << endl;

    printList(root2);
    devidePartition(root2, 10);

    return 225;

}