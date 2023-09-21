#include <iostream>
#include "linkedlist.h"

using namespace std;

LinkedList::Node::Node(int value) {
    this->value = value;
    this->next = NULL;
    cout << "Node created with a value of " << value << endl;
}

LinkedList::Node::~Node() {
    cout << "Node object has been destroyed" << endl;
}

void LinkedList::Node::setValue(int value) {
    this->value = value; 
}

int LinkedList::Node::getValue() {
    return this->value;
}

void LinkedList::Node::setNext(Node *next) {
    this->next = next;
}

LinkedList::Node* LinkedList::Node::getNext() {
    return this->next;
}

LinkedList::LinkedList() {
    Node *sentinal = new Node(0);
    this->head = sentinal;
    this->tail = sentinal;
    this->size = 0;
    cout << "LinkedList created with a sentinal node" << endl;
}

LinkedList::~LinkedList() {
    Node *current = this->head;
    for(int i = 0; i <= this->size; i++) {
        Node *next = current->getNext();
        delete current;
        current = next;
    }
    cout << "Linked list destroyed" << endl;
}

LinkedList::Node* LinkedList::getHead() {
    return this->head;
}

LinkedList::Node* LinkedList::getTail() {
    return this->tail;
}

int LinkedList::getSize() {
    return this->size;
}

void LinkedList::printList() {
    Node *current = this->head->getNext();

    if(this->tail == this->head) {
        cout << "The linked list is empty" << endl;
        return;
    }

    int i = 0;
    while(i < this->size) {
        cout << current->getValue() << " ";
        current = current->getNext();
        i++;
    }
    cout << endl;
}

void LinkedList::insertValue(int value) {
    Node *node = new Node(value);
    this->tail->setNext(node);
    this->tail = node;
    this->size++;
}

void LinkedList::insertNode(Node *node) {
    this->tail->setNext(node);
    this->tail = node;
    this->size++;
}

void LinkedList::removeLast() {
    if(this->head == this->tail) {
        cout << "There is nothing to remove" << endl;
        return;
    }
    if(this->size == 1) {
        delete this->head->getNext();
        this->head->setNext(NULL);
        this->tail = this->head;
        return;
    }
    Node *current = this->head->getNext();
    while(current->getNext()->getNext() != nullptr) {
        current = current->getNext();
    } 
    delete this->tail;
    this->size--;
    this->tail = current;
    this->tail->setNext(NULL);
}

void LinkedList::removeValue(int value) {
    if(this->head == this->tail) {
        cout << "There is nothing to remove" << endl;
        return;
    }else if(this->size == 1) {
        delete this->head->getNext();
        this->head->setNext(NULL);
        this->tail = this->head;
        this->size--;
        return;
    }
    Node *current = this->head;
    Node *previous;
    Node *next;
    bool found = false;
    for(int i = 0; i < size; i++) {
        if(current->getNext()->getValue() == value) {
            found = true;
            previous = current;
            current = current->getNext();
            if(current == this-> tail)
                next = NULL;
            else
                next = current->getNext();
            break;
        }
        current = current->getNext();
    }
    if(!found) {
        cout << "No such value found in the Linked List" << endl;
        return;
    }else if(found && next == NULL) {
        this->tail = previous;
        previous->setNext(NULL);
        delete current;
    }else{
        previous->setNext(next);
        delete current;
    }
    this->size--;
}

void LinkedList::reverseList() {
    Node *reference = this->head;
    for(int i = 0; i < this->size; i++) {
        Node *rev = new Node(this->tail->getValue());
        Node *rest = reference->getNext();
        this->removeLast();  
        reference->setNext(rev);
        rev->setNext(rest);
        size++;
        reference = rev;
    }
}