#include <iostream>
#include "stack.h"

using namespace std;

Stack::Node::Node(int value) {
    this->value = value;
    this->next = NULL;
}

Stack::Node::~Node() {
    cout << "Node has been deleted" << endl;
}

int Stack::Node::getValue() {
    return this->value;
}

Stack::Node* Stack::Node::getNext() {
    return this->next;
}

void Stack::Node::setNext(Node* node) {
    this->next = node;
}

Stack::Stack() {
    Node *sentinal = new Node(0);
    this->top = sentinal;
    this->size = 0;
}

Stack::~Stack() {
    for(int i = 0; i <= this->size; i++) {
        Node* current = this->top;
        this->top = current->getNext();
        delete current;
    }
    cout << "The stack has been delted" << endl;
}

int Stack::getSize() {
    return this->size;
}

Stack::Node* Stack::getTop() {
    if(this->size == 0) 
        cout << "The stack is empty returning sentinal" << endl;

    return this->top; 
}

void Stack::push(int value) {
    Node *node = new Node(value);
    node->setNext(this->top);
    this->top = node;
    this->size++;
}

void Stack::push(Node *node) {
    node->setNext(this->top);
    this->top = node;
    this->size++;
}


int Stack::pop() {
    if(this->size == 0) {
        cout << "The stack is empty returning value of sentinal node" << endl;
        return this->top->getValue();
    }
    Node *poped = this->top;
    this->top = poped->getNext();
    this->size--;
    int value = poped->getValue();
    delete poped;
    return value; 
}

void Stack::printStack() {
    if(this->size == 0) {
        cout << "The stack is currently empty" << endl;
        return;
    }
    Node *current = this->top;
    for(int i = 0; i < this->size; i++) {
        cout << current->getValue() << " ";
        current = current->getNext();
    }
    cout << endl;
}