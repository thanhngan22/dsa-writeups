// get height of a binary tree

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

int height(Node *root) {
    if (root == NULL) {
        return -1;
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return max(leftHeight, rightHeight) + 1;
}

int main() {
    Node *root = new Node(1);
    Node *second = new Node(2);
    Node *third = new Node(5);
    root->left = second;
    second->left = third;
    Node *fourth = new Node(3);
    fourth->left = new Node(4);
    third->left = fourth;
    third->right = new Node(6);

    cout << height(root);
    return 225;
}