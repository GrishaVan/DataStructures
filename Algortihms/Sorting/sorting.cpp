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
            /* While the previosy element is smaller keep swapping */
            while(list[same] < list[same - 1]){
                cout << list[same] << " is smaller than " << list[same - 1] << "\n";
                swap(list[same - 1], list[same]);
                same--;
            }         
        }
    }
}