#ifndef __SORTING_H
#define __SORTING_H

void bubble(int *list, int size);
void seq(int *list, int size);
void insert(int *list, int size);
void quicksort(int *list, int left, int right);
int partition(int *list, int left, int right);

#endif