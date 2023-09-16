#include <iostream>
#include "basic.h"
#include "sorting.h"

using namespace std;

int main() {

    int array[] = {5, 5, 3, 10, 12, 1, 3};
    insert(array, 7);
    printList(array, 7);

    return 0;
}