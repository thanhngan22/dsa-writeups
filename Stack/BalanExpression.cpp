#include <bits/stdc++.h>
using namespace std;

struct Node {
    int key;
    char data;
    bool hasKey;
    Node *pNext;
};

struct Stack {
    Node *top;
};

struct Queue {
    Node *front;
    Node *rear;
};

// create node function
Node * createNode (int key) {
    Node *pNode = new Node;
    pNode->key = key;
    pNode->hasKey = true;
    pNode->pNext = NULL; 
    return pNode;   
}

Node * createNode(char data) {
    Node *pNode = new Node;
    pNode->data = data;
    pNode->hasKey = false;
    pNode->pNext = NULL;
    return pNode;
}

// create new stack function
Stack *createStack (Node *&pNode) {
    Stack *S = new Stack;
    S->top = pNode;
}

// create new queue function
Queue *createQueue(Node *&pNode) {
    Queue *Q = new Queue;
    Q->front = pNode;
    Q->rear = pNode;
}

// enqueue a element to queue
void enqueue (Queue *&Q, int key) {
    if (Q->front == NULL) {
        Node *pNode = createNode(key);
        Q->front = pNode;
        Q->rear = pNode;
        return;
    }
    Node *pNode = createNode(key);
    Q->rear->pNext = pNode;
    Q->rear = pNode;
}

void enqueue (Queue *&Q, char data) {
    if (Q->front == NULL) {
        Node *pNode = createNode(data);
        Q->front = pNode;
        Q->rear = pNode;
        return;
    }
    Node *pNode = createNode(data);
    Q->rear->pNext = pNode;
    Q->rear = pNode;
}

// check whether a char is number or not
bool isNumber (char c) {
    if (c >= '0' && c <= '9') {
        return true;
    }
    return false;
}

// check whether a char is one of '+, -, *, /, ^ '
bool isOperator (char c) {
    if (c == '+' || c == '-' || c == '*' ||  c == '/' || c == '^') {
        return true;
    }
    return false;
}

// calculate the priority of a operator
int priority (char c) {
    // default:  + (1) - (2)  * (3) / (4) ^ (5)
    switch (c) {
        case '+' :
            return 1;
        case '-' :
            return 2;
        case '*' :
            return 3;
        case '/' :
            return 4;
        case '^' :
            return 5;
        default: 
            return 0;
    }
}

// compare the priority of a operator
bool isMorePriority (char a, char b) {
    if (priority(a) >= priority(b) ) {
        return true;
    }
    return false;
}

// print the elements of queue
void printQueue (Queue *Q) {
    if (Q->front == NULL) {
        return;
    }
    cout << "expression: ";
    Node *temp = Q->front;
    while (temp != NULL) {
        if (temp->hasKey == true) {
            cout << temp->key << " ";
        } else {
            cout << (char) temp->data << " ";
        }
        temp = temp->pNext;
    }
    cout << endl;
}

// convert expression from string into Queue
Queue *convertExpString_Queue (string exp) {
    Queue *Q = new Queue;
    Q->front = NULL;
    Q->rear = NULL;
    for (int i = 0; i < exp.length(); i++) {
        if ( isOperator( exp[i] ) || exp[i] == '(' || exp[i] == ')' ) {
            enqueue(Q, exp[i]);
        } else {
            if (isNumber(exp[i])) {
                if ( i + 1 < exp.length() && isNumber(exp[i+1])) {
                    string s = "";
                    s += exp[i];
                    i++;
                    while ( i < exp.length() && isNumber(exp[i])) {
                        s += exp[i];
                        i++;
                    }
                    enqueue(Q, stoi(s));
                    i--;
                } else {
                    string s = "";
                    s += exp[i];
                    enqueue(Q, stoi(s));

                }
            }

        }
    }
    return Q;
}

// convert middle expression into postfix expression
Queue *convertMidExpIntoPostExp () {

}

// calculate the value of postfix expressions
int calPostfixExp () {

}


int main() {
    string exp;
    cout << "enter an expression: ";
    fflush(stdin);
    getline(cin, exp);

    Queue *Q = convertExpString_Queue(exp);
    if (Q->front->hasKey == true) {
        cout << "hi: ";
        cout << Q->front->key << endl;
    }
    printQueue(Q);

    return 225;
}