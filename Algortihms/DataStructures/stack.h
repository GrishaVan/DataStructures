#ifndef __STACK_H
#define __STACK_H

class Stack 
{
public:
    class Node 
    {
    private:
        int value;
        Node *next;
    public:
        Node(int value);
        ~Node();
        int getValue();
        Node* getNext();
        void setNext(Node *node);
    };
private:
    Node *top;
    int size;
public:
    Stack();
    ~Stack();
    int getSize();
    Node* getTop();
    void push(int value);
    void push(Node* node);
    int pop();
    void printStack();
};

#endif