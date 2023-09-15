#include <iostream>
#include "bubble.h"

using namespace std;

void swap(int *a, int *b) {
    int c = *a;
    a = b;
    *b = c;
}

void bubble(int *list, int size) {
    do {
        for(int i = 0; i < size - 1; i++) {
            if(list[i] > list[i + 1]) {
                swap(list[i], list[i+1]);
            }    
        }
        size--;
    }
    while(size > 1);
}

void printList(int *list, int size) {
    for(int i = 0; i < size; i++) {
        cout << list[i] << " ";
    }
    cout << "\n";
}

int main() {

    int list[] = {3,4,2,1,10,22,5,13,7};
    bubble(list, 9);
    printList(list, 9);

    return 0;
}