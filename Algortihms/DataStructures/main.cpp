#include<iostream>
#include "linkedlist.h"

using namespace std;

int main() {

    LinkedList *list = new LinkedList();
    LinkedList::Node *node = new LinkedList::Node(5);
    
    list->insertNode(node);
    list->insertValue(4);
    list->insertValue(3);
    list->reverseList();
    list->printList();

    delete list;

    return 0;
}