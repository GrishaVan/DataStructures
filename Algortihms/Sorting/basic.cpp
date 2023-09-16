#include <iostream>
#include "basic.h"

using namespace std;

void swap(int *a, int *b) {
    int c = *a;
    a = b;
    *b = c;
}

void printList(int *list, int size) {
    for(int i = 0; i < size; i++) {
        cout << list[i] << " ";
    }
    cout << "\n";
}
