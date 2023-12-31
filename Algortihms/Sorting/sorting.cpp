#include <iostream>
#include "basic.h"
#include "sorting.h"

using namespace std;

void bubble(int *list, int size) {
    /**
     * Bubble sort, checks if the next element is bigger than the current one. If it is swap places
     * if its smaller then the next element stay in place and continue the process with the follwing
     * big element.
     * 
     * Parameters
     * ----------
     * 
     * list: Array of integers to be sorted
     * size: int value of the lenght of array to be sorted
     * 
     * Time Complexity
     * ---------------
     * O(n^2): For each element you will need to go through the list another time
     * O(n): best case scenario if list already sorted
     */
    do {
        /*For loop that looks thorugh the array*/
        for(int i = 0; i < size - 1; i++) {
            /*If the following element is smaller swap places*/
            if(list[i] > list[i + 1]) {
                swap(list[i], list[i+1]);
            }    
        }
        size--;
    }
    while(size > 1);
}

void seq(int *list, int size) {
    /**
     * Sequential sort, algorith that tries to find the smallest element in the array and put it as
     * the first element. Then shift the array starting point by 1 and repeat the process
     * 
     * Parameters
     * ----------
     * 
     * list: Array of integers to be sorted
     * size: int value of the lenght of array to be sorted
     * 
     * Time Complexity
     * ---------------
     * O(n^2): For each element you will need to go through the list another time
     * O(n): best case scenario if list already sorted
     */
    int index = 0;
    do{
        int *min = &list[index];
        /*Loop through the array*/
        for(int i = index; i < size; i++) {
            /*If the current numberis smaller then the previous min set it to min */
            if(list[i] < *min) 
                min = &list[i];
        }
        /*Swap the first elemnt in the array with the min number*/
        swap(list[index], *min);
        index++;
    }
    while(index != size - 1);
}

void insert(int *list, int size) {
    /**
     * Insertion sort, algorith that goes through elements in the array in order and if they are
     * smaller than the previosu element swap positions, keep doing that until the previous element
     * is the smaller one. 
     * 
     * Parameters
     * ----------
     * 
     * list: Array of integers to be sorted
     * size: int value of the lenght of array to be sorted
     * 
     * Time Complexity
     * ---------------
     * O(n^2): If list in reverse order you will go thorugh the list anotehr time for each input
     * O(n): best case scenario if list already sorted
     */

    /* For loop going through each element in order */
    for(int i = 1; i < size; i++) {
        /* For loop that goes thorugh eveery previous element */
        for(int j = i - 1; j >= 0; j--) {
            /* Need to make sure we keep track of the element we keep swapping */
            int same = i;
            /* While the previosy element is smaller and there is a previous element keep swapping */
            while(list[same] < list[same - 1] && same - 1 >= 0){
                swap(list[same - 1], list[same]);
                same--;
            }         
        }
    }
}

void quicksort(int *list, int left, int right) {
    if(left < right) {
        int pivotIndex = partition(list, left, right);
        quicksort(list, left, pivotIndex - 1);
        quicksort(list, pivotIndex + 1, right);
    }
}

int partition(int *list, int left, int right) {
    int pivot = list[right]; 
    int i = left - 1; 
    for(int j = left; j <= right - 1; j++) {
        if(list[j] < pivot) {
            i++;
            swap(list[i], list[j]);
        }
    }
    swap(list[i + 1], list[right]);
    return i + 1;
}

void mergesort(int *list, int left, int right) {
    if(left >= right)
        return;

    int mid = left + (right - left) / 2;
    mergesort(list, left, mid);
    mergesort(list, mid + 1, right);
    merge(list, left, mid, right);
}

void merge(int *list, int left, int mid, int right){
    
    int sizeLeft = mid - left + 1;
    int sizeRight = right - mid;

    int *leftSide = new int[sizeLeft];
    int *rightSide = new int[sizeRight];

    for(int i = 0; i < sizeLeft; i++) {
        leftSide[i] = list[left + i];
    }
    for(int i = 0; i < sizeRight; i++) {
        rightSide[i] = list[mid + 1 + i];
    }

    int leftIndex = 0;
    int rightIndex = 0;
    int arrayIndex = left;

    while(leftIndex < sizeLeft && rightIndex < sizeRight) {
        if(leftSide[leftIndex] < rightSide[rightIndex]) {
            list[arrayIndex] = leftSide[leftIndex];
            leftIndex++;
        }else{
            list[arrayIndex] = rightSide[rightIndex];
            rightIndex++;
        }
        arrayIndex++;
    }

    while(leftIndex < sizeLeft) {
        list[arrayIndex] = leftSide[leftIndex];
        leftIndex++;
        arrayIndex++;
    }


    while(rightIndex < sizeRight) {
        list[arrayIndex] = rightSide[rightIndex];
        rightIndex++;
        arrayIndex++;
    }

    delete[] leftSide;
    delete[] rightSide;
}