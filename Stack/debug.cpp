#include <bits/stdc++.h>
using namespace std;

struct Node {
    int key;
    char data;
    bool hasKey;
    Node* pNext;
};

struct Stack {
    Node* top;
};

struct Queue {
    Node* front;
    Node* rear;
};

// create node function
Node* createNode(int key) {
    Node* pNode = new Node;
    pNode->key = key;
    // pNode->data = NULL;
    pNode->hasKey = true;
    pNode->pNext = NULL;
    return pNode;
}

Node* createNode(char data) {
    Node* pNode = new Node;
    pNode->data = data;
    // pNode->key = NULL;
    pNode->hasKey = false;
    pNode->pNext = NULL;
    return pNode;
}

// enqueue a element to queue
void enqueue(Queue*& Q, int key) {
    Node* pNode = createNode(key);
    if (Q->front == NULL) {
        Q->front = pNode;
        Q->rear = pNode;
        return;
    }
    pNode->hasKey = true;
    (Q->rear)->pNext = pNode;
    Q->rear = pNode;
}

void enqueue(Queue*& Q, char data) {
    Node* pNode = createNode(data);
    if (Q->front == NULL) {
        Q->front = pNode;
        Q->rear = pNode;
        return;
    }
    Q->rear->pNext = pNode;
    Q->rear = pNode;
}

// pop an element on top of stack out of stack
void pop(Stack* S) {
    Node* temp = S->top;
    S->top = S->top->pNext;
    delete (temp);
}

// push an element to top of stack
void push(Stack*& S, char key) {
    Node* pNode = createNode(key);
    if (S->top == NULL) {
        S->top = pNode;
        return;
    }
    // changes
    (S->top)->pNext = S->top;
    S->top = pNode;
    // end changes
}

// check whether a char is number or not
bool isNumber(char c) {
    if (c >= '0' && c <= '9') {
        return true;
    }
    return false;
}

// check whether a char is one of '+, -, *, /, ^ '
bool isOperator(char c) {
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
        return true;
    }
    return false;
}

// calculate the priority of a operator
int priority(char c) {
    // default:  + (1) - (2)  * (3) / (4) ^ (5)
    switch (c) {
    case '+':
        return 1;
    case '-':
        return 2;
    case '*':
        return 3;
    case '/':
        return 4;
    case '^':
        return 5;
    default:
        return 0;
    }
}

// compare the priority of a operator
bool isMorePriority(char a, char b) {
    if (priority(a) >= priority(b)) {
        return true;
    }
    return false;
}

// print the elements of queue
void printQueue(Queue* Q) {
    if (Q->front == NULL) {
        return;
    }
    cout << "expression: ";
    Node* temp = Q->front;
    while (temp != NULL) {
        if (temp->hasKey == true) {
            cout << temp->key;
        }
        else {
            cout << (char)temp->data;
        }
        temp = temp->pNext;
    }
    cout << endl;
}

// convert expression from string into Queue
Queue* convertExpString_Queue(string exp) {
    Queue* Q = new Queue;
    Q->front = NULL;
    Q->rear = NULL;
    for (int i = 0; i < exp.length(); i++) {
        // changes
        if (exp[i] == ' ') continue;

        if (isOperator(exp[i]) || exp[i] == '(' || exp[i] == ')') {
            enqueue(Q, exp[i]);
        }
        else {
            /*if (isNumber(exp[i])) {
                if ((i + 1) < exp.length() && isNumber(exp[i + 1])) {
                    string s = "";
                    s += exp[i];
                    i++;
                    while (i < exp.length() && isNumber(exp[i])) {
                        s += exp[i];
                        i++;
                    }
                    enqueue(Q, stoi(s));
                    i--;
                }
                else {
                    string s = "";
                    s += exp[i];
                    enqueue(Q, stoi(s));

                }
            }*/
            string num = "";
            while (i < exp.length() && isNumber(exp[i])) {
                num += exp[i]; 
                i++;
            }
            i--;
            enqueue(Q, stoi(num));
        }
        // end changes
    }
    return Q;
}

// convert middle expression into postfix expression
Queue* convertMidExpIntoPostExp(Queue* P) {
    Stack* S = new Stack;
    S->top = NULL;
    Queue* Q = new Queue;
    // changes
    Q->front = Q->rear = NULL;
    // end changes
    Node* temp = P->front;
    while (temp != NULL) {
        if (temp->hasKey == true) {
            enqueue(Q, temp->key);
            //cout << "enqueue " << temp->key << endl;
            //continue; // no need to use continue statement here
        }
        else {
            //cout << "range: " << temp->data << endl;
            if (temp->data == ')') {
                while (S->top != NULL) {
                    if (S->top->data == '(') {
                        pop(S);
                        break;
                    }
                    else {
                        enqueue(Q, S->top->data);
                        pop(S);
                    }
                }
            }
            else if (temp->data == '(') {
                push(S, temp->data);
            }
            else if (isOperator(temp->data)) {
                if (S->top == NULL || (S->top)->data == '(') {
                    push(S, temp->data);
                }
                else {
                    if (isMorePriority(temp->data, (S->top)->data)) {
                        enqueue(Q, (S->top)->data);
                        pop(S);
                    }
                    push(S, temp->data);
                }
                /*while (S->top != NULL && isOperator(S->top->data) && isMorePriority(S->top->data, temp->data)) {
                    enqueue(Q, S->top->data);
                    pop(S);
                }*/
                //push(S, temp->data);
                //continue; // no need 
            }
        }
        temp = temp->pNext;
    }
    
    // case: stack after operation is not empty
    while (S->top != NULL) {
        enqueue(Q, (S->top)->data);
        pop(S);
    }
    cout << "heli";
    return Q;
}

// calculate the value of postfix expressions
int calPostfixExp() {
    return 0;
}


int main() {
    string exp;
    cout << "enter an expression: ";
    fflush(stdin);
    getline(cin, exp);

    Queue* P = convertExpString_Queue(exp);
    // convert middle expression into postfix expression
    cout << "\nMiddle expression: ";
    printQueue(P);
    cout << "Postfix expression: ";
    Queue* Q = convertMidExpIntoPostExp(P);
    printQueue(Q);


    return 0; // zero errors
}