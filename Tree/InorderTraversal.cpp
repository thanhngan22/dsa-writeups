// print the tree's inorder traversal as a single line of space-separated values.

#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;

        Node (int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

void inOrder(Node *root) {
    if (root == NULL) {
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

int main() {
    Node *root = new Node(1);
    Node *second = new Node(2);
    Node *third = new Node(5);
    root->right = second;
    second->right = third;
    third->right = new Node(6);
    Node *fourth = new Node(3);
    fourth->right = new Node(4);
    third->left = fourth;


    inOrder(root);
    return 225;
}