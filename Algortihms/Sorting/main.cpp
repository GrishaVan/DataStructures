#include <iostream>
#include "basic.h"
#include "sorting.h"

using namespace std;

int main() {

    int array[] = {5, 7, 2, 3, 4, 12, 10, 11, 1};
    quicksort(array, 0, 8);
    printList(array, 9);

    return 0;
}