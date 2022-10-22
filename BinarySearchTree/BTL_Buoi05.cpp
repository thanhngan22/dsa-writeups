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
        if (key == root->key) {
        cout << "key existed ! " << endl;
        return;
    } 
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
bool isExistNode(Node *root, int key) {
    Node *temp = root;
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

// hàm tìm giá trị trái nhất của cây  
int mostLeft(Node *root) {
    while (root->pLeft != NULL) {
        root = root->pLeft;
    }
    return root->key;
}

// hàm tìm giá trị phải nhất của cây 
int mostRight(Node *root) {
    while (root->pRight != NULL) {
        root = root->pRight;
    }
    return root->key;
}

// hàm giải phóng 1 node
void freeNode (Node *&node) {
    delete (node);
    node = NULL;
}

// hàm giải phóng 1 cây 
void freeTree (Node *&root) {
    if (root == NULL) {
        return;
    }
    freeTree(root->pLeft);
    freeTree(root->pRight);
    free(root);
}


// xóa một node trong cây nhị phân tìm kiếm 
void deleteNode(Node *&root, int key) {
    Node *temp = root;
    Node *prev = NULL;
    if ( ! isExistNode(root, key)) {
        cout << key << "is not exist in BST" << endl;
        return ;
    }
    while (temp != NULL) {
        if (temp->key == key) {
            // node là node lá 
            if (temp->pLeft == NULL && temp->pRight == NULL) {
                if (prev->pLeft != NULL && prev->pLeft->key == key) {
                    prev->pLeft = NULL;
                    freeNode(temp);
                    return;
                } else {
                    prev->pRight = NULL;
                    freeNode(temp);
                    return ;
                }
            }

            // node có đủ 2 con 
            if (temp->pLeft != NULL && temp->pRight != NULL) {
                // tìm phần tử thế mạng : node trái nhất của cây con phải
                int replaceNode = mostLeft(temp->pRight);
                deleteNode(temp, replaceNode);
                temp->key = replaceNode;
                return;
            }

            // node có 1 con
            if (temp->pLeft != NULL) {
                if (prev == NULL) {
                    // trường hợp temp là root
                    root = root->pLeft;
                    freeNode(temp);
                    return;
                } else {
                    if (prev->pLeft != NULL && prev->pLeft->key == key) {
                        // trường hợp temp là cây con trái của node cha prev
                        prev->pLeft = temp->pLeft;

                        freeNode(temp);
                        return;
                    } else {
                        // temp là cây con phải của node cha prev
                        prev->pRight = temp->pLeft;
                        freeNode(temp);
                        return;
                    }
                }
            } else {
                if (prev == NULL) {
                    // trường hợp temp là root
                    root = root->pRight;
                    freeNode(temp);
                    return;
                } else {
                    if (prev->pLeft != NULL && prev->pLeft->key == key) {
                        // trường hợp node cần xóa là node con trái của node cha prev
                        prev->pLeft = temp->pRight;
                        freeNode(temp);
                        return;
                    } else {
                        // node cần xóa là node con phải của node cha prev
                        prev->pRight = temp->pRight;
                        freeNode(temp);
                        return;
                    }
                }
            }
        } else {
            if (key < temp->key) {
                prev = temp;
                temp = temp->pLeft;
            } else {
                prev = temp;
                temp = temp->pRight;
            }
        }
    }
}

// viết hàm xoay trái một node trong cây nhị phân tìm kiếm (mặc định là node cần xoay có node con phải khỏi cần kiểm tra)
void rotateLeft(Node *&root, int key) {
    Node *temp = root;
    Node *prev = NULL;
    while (temp->key != key) {
        if (temp->key < key) {
            prev = temp;
            temp = temp->pRight;
        } else {
            prev = temp;
            temp = temp->pLeft;
        }
    }
        if (temp->pRight->pLeft != NULL) {
            Node *abandonNode = temp->pRight->pLeft;
            if (prev == NULL) {
                // trường hợp đó là node root
                root = temp->pRight;
            } else {
                if (prev->pRight->key == key) {
                    prev->pRight = temp->pRight;

                } else {
                    prev->pLeft = temp->pRight;
                }
            }
            temp->pRight->pLeft = temp;
            temp->pRight = abandonNode;
            return;
        } else {
            if (prev == NULL) {
                // trường hợp đó là node root
                root = temp->pRight;
            } else {
                if (prev->pRight->key == key) {
                    prev->pRight = temp->pRight;

                } else {
                    prev->pLeft = temp->pRight;
                }
            }           
            temp->pRight->pLeft = temp;
            return;
        }
}

// viết hàm xoay phải một node trong cây nhị phân tìm kiếm
void rotateRight(Node *&root, int key) {
    Node *temp = root;
    Node *prev = NULL;
    while (temp->key != key) {
        if (temp->key < key) {
            prev = temp;
            temp = temp->pRight;
        } else {
            prev = temp;
            temp = temp->pLeft;
        }
    }
        if (temp->pLeft->pRight != NULL) {
            Node *abandonNode = temp->pLeft->pRight;
            if (prev == NULL) {
                // trường hợp đó là node root
                root = temp->pLeft;
            } else {
                if (prev->pRight->key == key) {
                    prev->pRight = temp->pLeft;

                } else {
                    prev->pLeft = temp->pLeft;
                }
            }
            temp->pLeft->pRight = temp;
            temp->pLeft = abandonNode;
            return;
        } else {
            if (prev == NULL) {
                // trường hợp đó là node root
                root = temp->pLeft;
            } else {
                if (prev->pRight->key == key) {
                    prev->pRight = temp->pLeft;

                } else {
                    prev->pLeft = temp->pLeft;
                }
            }           
            temp->pLeft->pRight = temp;
            return;
        }
}

// viết hàm tính chiều cao của cây nhị phân tìm kiếm
int height (Node *root) {
    if (root == NULL) {
        return -1;
    }
    return max(height(root->pLeft), height(root->pRight)) + 1;
}

// viết hàm kiểm tra xem một cây nhị phân tìm kiếm có cân bằng hay không 
bool isBalanceBST (Node *root) {
    if (root == NULL) {
        return true;
    }
    if (abs(height(root->pLeft) - height(root->pRight)) <= 1) {
        return isBalanceBST(root->pLeft) && isBalanceBST(root->pRight);
    } else {
        return false;
    }
}

// viết hàm kiểm tra xem cây nhị phân mất cân bằng tại node nào
int keyMakingNotBalance(Node *root) {
    if (root == NULL) {
        return -1;
    }
    if (abs(height(root->pLeft) - height(root->pRight)) > 1) {
        return root->key;
    } else {
        int left = keyMakingNotBalance(root->pLeft);
        int right = keyMakingNotBalance(root->pRight);
        if (left != -1) {
            return left;
        } else {
            return right;
        }
    }
}

// viết hàm kiểm tra xem có đường đi từ root đến node lá mà có tổng bằng sum không
bool hasPathSum(Node *root, int sum) {
    if (root == NULL) {
        if (sum == 0) {
            return true;
        } else {
            return false;
        }
    }
    bool left = hasPathSum(root->pLeft , sum - root->key);
    bool right = hasPathSum(root->pRight, sum - root->key);

    if (left == true || right == true) {
        return true;
    } else {
        return false ;
    }
}


// viết hàm kiểm tra xem cây nhị phân tìm kiếm bị lệch kiểu gì: RR -> 1; RL -> 2; LL -> 3; LR -> 4
int typeNotBalanceBST (Node *root) {

}

// viết hàm cân bằng lại cây nhị phân tìm kiếm nếu cây bị lệch
void balanceBST (Node *&root) {
 
}

// tạo cây nhị phân hoàn chỉnh từ dãy số cho trước
Node * makeCompleteBST (int *arr, int i, int n) {
    Node *pNode = NULL;
    if (i < n) {
        pNode = createNode(arr[i]);
        pNode->pLeft = makeCompleteBST(arr, 2 * i + 1, n);
        pNode->pRight = makeCompleteBST(arr, 2 * i + 2, n);
    }
    return pNode;
}

// hàm hoán đổi giá trị
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// viết hàm max-heapify
void maxHeapify (Node *root) {
    if (root->pLeft != NULL && root->pRight != NULL) {
        int l = root->pLeft->key;
        int r = root->pRight->key;
        if (l > r && l > root->key) {
            swap(root->key, root->pLeft->key);
        } else if (l < r && root->key < r) {
            swap(root->key, root->pRight->key);
        }
        return;
    }
    if (root->pLeft != NULL) {
        if (root->pLeft->key > root->key) {
            swap(root->key, root->pLeft->key);
            return;
        }
    }
    if (root->pRight != NULL) {
        if (root->key < root->pRight->key) {
            swap(root->key, root->pRight->key);
        }
    }
}

// viết hàm min-heapify
void minHeapify (Node *root) {
    if (root->pLeft != NULL && root->pRight != NULL) {
        int l = root->pLeft->key;
        int r = root->pRight->key;
        if (l < r && l < root->key) {
            swap(root->key, root->pLeft->key);
        } else if (l > r && root->key > r) {
            swap(root->key, root->pRight->key);
        }
        return;
    }
    if (root->pLeft != NULL) {
        if (root->pLeft->key < root->key) {
            swap(root->key, root->pLeft->key);
            return;
        }
    }
    if (root->pRight != NULL) {
        if (root->key > root->pRight->key) {
            swap(root->key, root->pRight->key);
        }
    }
}

// viết hàm sắp xếp thuật toán vun đống
void heapSort_max (Node *root) {

}

void heapSort_min (Node *root) {

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

    // // max value of tree
    // cout << "max value of BST tree: " << maxNode(tree) << endl;

    // // check whether existing 27 , 35, 5 and 103 or not
    // cout << "27: " << isExistNode(tree->root, 27) << endl;
    // cout << "35: " << isExistNode(tree->root, 35) << endl;
    // cout << "5: " << isExistNode(tree->root, 5) << endl;
    // cout << "103: " << isExistNode(tree->root, 103) << endl;

    // // is BST
    // // create a tree to check
    // Node *nodeTree2 = createNode(22);
    // BST *tree2 = createBST(nodeTree2);
    // Node *tree2Left = createNode(2003);
    // Node *tree2Right = createNode(5);
    // tree2->root->pLeft = tree2Left;
    // tree2->root->pRight = tree2Right;

    // cout << "is BST ? " <<  isBST(tree->root) << endl;
    // cout << "is BST ? " << isBST(tree2->root) << endl;

    // // value of most left and most right
    // cout << "most left: " << mostLeft(tree->root) << endl;
    // cout << "most right: " << mostRight(tree->root) << endl;

    // // delete 8
    // deleteNode(tree->root, 8);
    // cout << "NLR: ";
    // NLR(tree->root);
    // cout << endl;

    // // delete 9
    // deleteNode(tree->root, 9);
    // cout << "NLR: ";
    // NLR(tree->root);
    // cout << endl;

    // // delete 64
    // deleteNode(tree->root, 64);
    // cout << "NLR: ";
    // NLR(tree->root);
    // cout << endl;

    // // delete 33
    // deleteNode(tree->root, 33);
    // cout << "NLR: ";
    // NLR(tree->root);
    // cout << endl;

    // // rotate node 92 toward left
    // rotateLeft(tree->root, 92);
    // cout << "NLR: ";
    // NLR(tree->root);
    // cout << endl;

    // // rotate node 33 toward left
    // rotateLeft(tree->root, 33);
    // cout << "NLR: ";
    // NLR(tree->root);
    // cout << endl;

    
    // // rotate node 33 toward right
    // rotateRight(tree->root, 33);
    // cout << "NLR: ";
    // NLR(tree->root);
    // cout << endl;
    
    // // rotate node 92 toward right
    // rotateRight(tree->root, 92);
    // cout << "NLR: ";
    // NLR(tree->root);
    // cout << endl;

    // // test height of tree function
    // Node *pHeight = createNode(22);
    // pHeight->pLeft = createNode(5);
    // pHeight->pLeft->pLeft = createNode(2003);
    // pHeight->pRight = createNode(11);

    // cout << "height : " << height(pHeight) << endl;

    // // test whether a BST is balance
    // cout << "tree is balance: " << isBalanceBST(tree->root) << endl;
    // cout << "pHeight is balance: " << isBalanceBST(pHeight) << endl;

    // cout << "tree is not balance at key: " << keyMakingNotBalance(tree->root) << endl;

    // // test whether has a path from root to leaf that sum of key of all node in that path equal to sum
    // cout << "has path sum = 69: " << hasPathSum(tree->root, 69) << endl;
    // cout << "has path sum = 89: " << hasPathSum(tree->root, 89) << endl;
    // cout << "has path sum = 262: " << hasPathSum(tree->root, 262) << endl;
    // cout << "has path sum = 268: " << hasPathSum(tree->root, 268) << endl;
    // cout << "has path sum = 329: " << hasPathSum(tree->root, 329) << endl;
    // cout << "has path sum = 350: " << hasPathSum(tree->root, 350) << endl;
    // cout << "has path sum = 225: " << hasPathSum(tree->root, 225) << endl;
    // cout << "has path sum = 2003: " << hasPathSum(tree->root, 2003) << endl;

    // // test making complete tree from a given array function
    // int arr[] = {22, 5, 2003, 11, 4, 2011, 13 ,4, 1999};
    // Node *root = makeCompleteBST(arr, 0, sizeof(arr)/sizeof(int));
    // cout << "NLR: ";
    // NLR(root);
    // cout << endl;

    return 225;
}