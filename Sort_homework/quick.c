#include "sort.h"
#include <stdio.h>

void swap(int* a, int* b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void quick_sort(int list[], int start, int end){
  if( start >= end ) return ;

  int mid = (start+end)/2;
  int pivot = list[mid];

  swap(&list[start], &list[mid]);

  int p = start+1, q = end;

  while(1){
    while(list[p] <= pivot){ p++; }
    while(list[q] > pivot){ q--; }    

    if(p > q) break;

    swap(&list[p], &list[q]);
  }

  swap(&list[start], &list[q]);

  quick_sort(list, start, q-1);
  quick_sort(list, q+1, end);
}

void QuickSort(int list[], int n) {
  int start = 0;
  int end = n-1;
  quick_sort(list, start, end);
}
