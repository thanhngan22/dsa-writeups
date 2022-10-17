
// viết hàm kiểm tra xem một cây nhị phân tìm kiếm có cân bằng hay không và tiến hành cân bằng lại nếu cây bị lệch

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

// viết hàm in ra giá trị lớn nhất trong cây
int maxNode(BST *tree) {
    if (tree->root == NULL) {
        exit(225);
    }
    Node *temp = tree->root;
    while (temp->pRight != NULL) {
        temp = temp->pRight;
    }
    return temp->key;
}

// viết hàm tìm 1 số có trong cây hay không
bool isExistNode(BST *tree, int key) {
    Node *temp = tree->root;
    while (temp != NULL) {
        if (key == temp->key) {
            return true;
        } else if (key < temp->key) {
            temp = temp->pLeft;
        } else {
            temp = temp->pRight;
        }
    }
    return false;
}

// viết hàm kiểm tra xem một cây nhị phân có phải là cây nhị phân tìm kiếm hay không
bool isBST(Node *root) {
    if (root->pLeft == NULL && root->pRight == NULL) {
        return 1;
    }
    if (root->pLeft != NULL && root->pRight != NULL ) {
        if (root->pLeft->key < root->key && root->pRight->key > root->key) {
            return isBST(root->pLeft) + isBST(root->pRight);
        } else {
            return false;
        }
    } else {
        if (root->pLeft != NULL) {
            if (root->pLeft->key < root->key) {
                return isBST(root->pLeft);
            }
        }
        if (root->pRight != NULL) {
            if (root->pRight->key > root->key) {
                return isBST(root->pRight);
            }
        }
    }
}

// xóa một node trong cây nhị phân tìm kiếm 
void deleteNode(BST *&tree) {

}

// viết hàm xoay trái một node trong cây nhị phân tìm kiếm
void rotateLeft(Node *&root) {

}

// viết hàm xoay phải một node trong cây nhị phân tìm kiếm
void rotateRight(Node *&root) {

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

    // max value of tree
    cout << "max value of BST tree: " << maxNode(tree) << endl;

    // check whether existing 27 , 35, 5 and 103 or not
    cout << "27: " << isExistNode(tree, 27) << endl;
    cout << "35: " << isExistNode(tree, 35) << endl;
    cout << "5: " << isExistNode(tree, 5) << endl;
    cout << "103: " << isExistNode(tree, 103) << endl;

    // is BST
    // create a tree to check
    Node *nodeTree2 = createNode(22);
    BST *tree2 = createBST(nodeTree2);
    Node *tree2Left = createNode(2003);
    Node *tree2Right = createNode(5);
    tree2->root->pLeft = tree2Left;
    tree2->root->pRight = tree2Right;

    cout << "is BST ? " <<  isBST(tree->root) << endl;
    cout << "is BST ? " << isBST(tree2->root) << endl;



    return 225;
}