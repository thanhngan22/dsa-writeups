// given a pointer to the root of a binary tree, print the top view of the binary tree
// the tree as seen from the top the nodes you will be able to see will be called the top view of the tree

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

void TopView(Node *root) {
    if (root == NULL) return;
    queue<pair<Node*, int>> q;
    map<int, int> m;
    int hd = 0;
    q.push({root, hd});
    while (!q.empty()) {
        pair<Node*, int> temp = q.front();
        q.pop();
        hd = temp.second;
        Node *node = temp.first;
        if (m.count(hd) == 0) m[hd] = node->data;
        if (node->left) q.push({node->left, hd-1});
        if (node->right) q.push({node->right, hd+1});
    }
    for (auto i = m.begin(); i != m.end(); i++) cout << i->second << " ";

}

int main() {

}