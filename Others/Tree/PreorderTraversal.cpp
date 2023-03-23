// Print the tree's preorder traversal as a single line of space-separated values.

#include <iostream>
using namespace std;

class Node {
    public :
        int data;
        Node *left;
        Node *right;

        Node (int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

void preOrder(Node *root) {
    if (root == NULL) {
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

int main () {
    Node *root = new Node(1);
    Node *second = new Node(2);
    Node *third = new Node(5);
    root->left = second;
    second->left = third;
    Node *fourth = new Node(3);
    fourth->left = new Node(4);
    third->left = fourth;
    third->right = new Node(6);

    preOrder(root);
    return 225;

}