#include<iostream>
#include "linkedlist.h"
#include "stack.h"

using namespace std;

int main() {

    // LinkedList *list = new LinkedList();
    // LinkedList::Node *node = new LinkedList::Node(5);
    
    // list->insertNode(node);
    // list->insertValue(4);
    // list->insertValue(3);
    // list->reverseList();
    // list->printList();

    // delete list;

    Stack *stack = new Stack();
    stack->printStack();
    stack->push(4);
    stack->push(5);
    stack->push(6);
    stack->push(7);
    cout << stack->getSize() << endl;
    stack->printStack();
    cout << stack->pop() << endl;
    stack->printStack();
    cout << stack->getTop()->getValue() << endl;

    delete stack;

    return 0;
}