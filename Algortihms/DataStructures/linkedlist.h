#ifndef __LINKEDLIST_H
#define __LINKEDLIST_H


class LinkedList
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
        void setValue(int value);
        int getValue();
        void setNext(Node *next);
        Node* getNext();
    };

private:
    Node *head;
    Node *tail;
    int size;
public:
    LinkedList();
    ~LinkedList();
    Node* getHead();
    Node* getTail();
    int getSize();
    void printList();
    void insertValue(int value);
    void insertNode(Node *node);
    void removeLast();
    void removeValue(int value);
    void reverseList();
};

#endif