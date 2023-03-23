#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int data) {
        this->data = data;
        left = right = NULL;
    }
};

int height (Node *root) {
    if (root == NULL) return -1;
    return 1 + max(height(root->left), height(root->right));
}

void printLevel(Node *root, int level) {
    if (root == NULL) return;
    if (level == 0) cout << root->data << " ";
    else {
        printLevel(root->left, level - 1);
        printLevel(root->right, level - 1);
    }
}

void levelOrder(Node *root) {
    int h = height(root);
    for (int i = 0; i <= h; i++) {
        printLevel(root, i);
    }
}

int main() {
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    levelOrder(root);

    return 0;
}