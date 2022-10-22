#include <bits/stdc++.h>
using namespace std;

struct Node {
    float result;
    int key ;
    char data ;
    bool hasKey;
    Node *pNext;
};

struct Stack {
    Node *top = NULL;
};

struct Queue {
    Node *front = NULL;
    Node *rear = NULL;
};

// create a node having integer type
Node * createNode (int key) {
    Node *pNode = new Node;
    pNode->key = key;
    pNode->hasKey = true;
    pNode->pNext = NULL; 
    return pNode;   
}

// create a node having char type
Node * createNode(char data) {
    Node *pNode = new Node;
    pNode->data = data;
    pNode->hasKey = false;
    pNode->pNext = NULL;
    return pNode;
}

// init a empty stack
Stack *initStack() {
    Stack *S = new Stack;
    S->top = NULL;
    return S;
}

// create a new stack function
Stack *createStack (Node *&pNode) {
    Stack *S = new Stack;
    S->top = pNode;
    pNode->pNext = NULL;
    return S;
}

// create a new queue function
Queue *createQueue(Node *&pNode) {
    Queue *Q = new Queue;
    Q->front = pNode;
    Q->rear = pNode;
    Q->rear->pNext = NULL;
    return Q;
}

// enqueue a element having integer type
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

// enqueue a element having char type
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

// pop an element on top of stack out of stack
void pop (Stack *S) {
    Node *temp = S->top;
    S->top = S->top->pNext;
    delete (temp);
}

// pop a node having integer type
int pop (Stack  *&S, bool hasKey) {
    if (hasKey == true) {
        Node *temp = S->top;
        int key = S->top->key;
        S->top = S->top->pNext;
        delete temp;
        return key;
    } else {
        cout << "not has key\n";
        exit(225);
    }
}

// pop a node having float type
float popFloat (Stack *&S) {
    Node *temp = S->top;
    S->top = S->top->pNext;
    float f = temp->result;
    delete temp;
    return f;
} 

// pop a node having char type
char popChar (Stack *&S) {
    Node *temp = S->top;
    S->top = S->top->pNext;
    char c = temp->data;
    delete temp;
    return c;
}

// push an element to top of stack
void push (Stack *&S, char data) {
    if (S->top == NULL) {
        Node *pNode = createNode(data);
        S = createStack(pNode);
        return ;
    }
    Node *pNode = new Node;
    pNode->data = data;
    pNode->hasKey = false;
    pNode->pNext = S->top;
    S->top = pNode;
}

// push a integer into stack
void push (Stack *&S, int key) {
    if (S->top == NULL) {
        Node *pNode = createNode(key);
        S = createStack(pNode);
        return ;
    }
    Node *pNode = createNode(key);
    pNode->pNext = S->top;
    S->top = pNode;
}

// convert Integer into float and push to stack
void pushIntToFloat (Stack *&S, int key) {
    if (S->top == NULL) {
        Node *pNode = new Node;
        pNode->result = (float) key;
        pNode->pNext = NULL;
        S = initStack();
        S->top = pNode;
        return ;
    }
    Node *pNode = new Node;
    pNode->result = (float) key;
    pNode->pNext = S->top;
    S->top = pNode;
}

// push a stack into stack
void push (Stack *&S, float result) {
    if (S->top == NULL) {
        Node *pNode = new Node;
        S = initStack();
        pNode->result = result;
        pNode->pNext = NULL;
        S->top = pNode;
        return ;
    }
    Node *pNode = new Node;
    pNode->result = result;
    pNode->pNext = S->top;
    S->top = pNode;
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
            // if it is operator such as + - * / ^ or ( ) : enqueue 
            enqueue(Q, exp[i]);
        } else {
            if (isNumber(exp[i])) {
                // if it is a number: 
                if ( i + 1 < exp.length() && isNumber(exp[i+1])) {
                    // if that number >= 10 : find next other number and concat them, then create node with that value and enqueue
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
                    // if it only has a number such as 0 -> 9
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
Queue *convertMidExpIntoPostExp (Queue *P) {
    Stack *S = new Stack;
    S->top = NULL;
    Queue *Q = new Queue;
    Node *temp = P->front;
    while (temp != NULL) {
        if (temp->hasKey == true) { 
            // if it is a number: 
            enqueue(Q, temp->key);
            temp = temp->pNext;
            continue;
        } else {
            if (temp->data == ')') { 
                // when meeting a ' ) ' :
                while (S->top != NULL) {
                    // pop element of of stack and enqueue to queue until meeting ')'
                        if (S->top->data == '(') {
                            pop(S);
                            temp = temp->pNext;
                            break;
                        } else {
                            enqueue(Q, S->top->data);
                            pop(S);
                        }
                }
            }
            if (temp->data == '(') {
                // just need to push it into stack
                push(S, temp->data);
                temp = temp->pNext;
                continue;
            }
            if (isOperator(temp->data)) {
                // if it is a operator such as: + - * / ^
                if (S->top == NULL || ! isOperator(S->top->data) || isMorePriority(temp->data, S->top->data)) {
                    // if the element in top of stack isn't a operator or being a operator but has less priority than current operator or not having any element in stack
                    push(S, temp->data);
                    temp = temp->pNext;
                    continue;
                }
                while (S->top != NULL && isOperator(S->top->data) && isMorePriority(S->top->data, temp->data)) {
                    // if the operator in top of stack has more priority than current operator: pop until the condition get false value
                    enqueue(Q, S->top->data);
                    pop(S);
                } 
                push(S, temp->data);
                temp = temp->pNext;
                continue;
            }
        }
    }
    while (S->top != NULL) {
        // get other operators in stack 
        char c = popChar(S);
        enqueue(Q, c);
    }
    return Q;
}

// calculate the value of expression
float calculate (float a, float b, char _operator) {
    switch (_operator) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*' : 
            return a * b;
        case '/':
            return  (a * 1.0) /b ;
        case '^':
            return pow (a,b);
    }
} 

// calculate the value of postfix expressions
float calPostfixExp (Queue *Q) {
    Stack *S = initStack();
    S->top = Q->front;
    Stack *P = initStack();  // used to save the numbers
    while (S->top != NULL) {
        if (S->top->hasKey == true) {
            pushIntToFloat(P, S->top->key);
            pop (S);
        } else {
            float b = popFloat(P);
            float a = popFloat(P);
            // cout << "a,b: " << a << " " << b << endl;
            push(P, calculate(a, b, S->top->data));
            // cout << "result: " << P->top->result << endl;
            pop(S);
        }
    }
    return P->top->result;
}


int main() {
    string exp;
    cout << "enter an expression: ";
    fflush(stdin);
    getline(cin, exp);

    Queue *P = convertExpString_Queue(exp);
    printQueue(P);

    // convert middle expression into postfix expression
    cout << "Middle expression: " ;
    printQueue(P);
    cout << "Postfix expression: ";
    Queue *Q = convertMidExpIntoPostExp(P);
    printQueue(Q);

    // calculate the value of postfix expression
    cout << "Value: " << calPostfixExp(Q) << endl;

    /* Code rối nhưng mà lười sửa, ai đọc code tôi hiểu là thiên thần :) */

    return 225;
}