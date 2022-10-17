// viết hàm in ra giá trị lớn nhất trong cây

// viết hàm tìm 1 số có trong cây hay không

// xóa một node trong cây nhị phân tìm kiếm 

// viết hàm kiểm tra xem một cây nhị phân có phải là cây nhị phân tìm kiếm hay không

// viết hàm kiểm tra xem một cây nhị phân tìm kiếm có cân bằng hay không và tiến hành cân bằng lại nếu cây bị lệch

// viết hàm xoay trái một node trong cây nhị phân tìm kiếm

// viết hàm xoay phải một node trong cây nhị phân tìm kiếm

// tạo cây nhị phân hoàn chỉnh từ dãy số cho trước

// viết hàm max-heapify

// viết hàm min-heapify

// viết hàm sắp xếp thuật toán vun đống

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int key;
    Node *pLeft, *pRight;
};

struct BST {
    Node *root;
};

// hàm tạo node
Node *createNode (int key) {
    Node *pNode = new Node;
    pNode->key = key;
    pNode->pLeft = NULL;
    pNode->pRight = NULL;
    return pNode;
}

// hàm khởi tạo BST
BST *createBST(Node *&pNode) {
    BST *Tree = new BST;
    Tree->root = pNode;
    return Tree;
} 

// viết hàm thêm node mới vào trong cây
void addNode(Node *&root, int key) {
    if (root->pLeft == NULL) {
        if (root->key > key) {
            Node *pNode = createNode(key);
            root->pLeft = pNode;
            return;
        }
    }

    if (root->pRight == NULL) {
        if (root->key < key) {
            Node *pNode = createNode(key);
            root->pRight = pNode;
            return;
        }
    }
    
    if (key == root->key) {
        cout << "key existed ! " << endl;
        return;
    } 
    if (key < root->key) {
        addNode(root->pLeft, key);
    } else {
        addNode(root->pRight, key);
    }
}

// phép duyệt NLR
void NLR(Node *root) {
    if (root == NULL) {
        return;
    }
    cout << root->key << " ";
    NLR(root->pLeft);
    NLR(root->pRight);
}

// phép duyệt LNR
void LNR (Node *root) {
    if (root == NULL) {
        return;
    }
    LNR(root->pLeft);
    cout << root->key << " ";
    LNR(root->pRight);
}

// phép duyệt LRN
void LRN(Node *root) {
    if (root == NULL) {
        return;
    }
    LRN(root->pLeft);
    LRN(root->pRight);
    cout << root->key << " ";
}

int main() {
    // tạo cây nhị phân tìm kiếm từ dãy số sau:
    // 33 14 15 92 64 35 79 27 38 9 105 99 120 5 8

    Node *pNode = createNode(33);
    BST *tree = createBST(pNode);
    addNode(tree->root, 14);
    addNode(tree->root, 15);
    addNode(tree->root, 92);
    addNode(tree->root, 64);
    addNode(tree->root, 35);
    addNode(tree->root, 79);
    addNode(tree->root, 27);
    addNode(tree->root, 38);
    addNode(tree->root, 9);
    addNode(tree->root, 105);
    addNode(tree->root, 99);
    addNode(tree->root, 120);
    addNode(tree->root, 5);
    addNode(tree->root, 8);

    cout << "NLR: ";
    NLR(tree->root);

    cout << endl;
    cout << "LNR: ";
    LNR(tree->root);

    cout << endl;
    cout << "LRN: ";
    LRN(tree->root);
    
    return 225;
}