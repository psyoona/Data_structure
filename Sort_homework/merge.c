#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

void merge(int out[], int a[], int sizeA, int b[], int sizeB){
  int i = 0, j = 0, k = 0;

  while(i < sizeA && j < sizeB){
    if(a[i] < b[j]){
      out[k++] = a[i++];

    }else {
      out[k++] = b[j++];
    }
  }

  while(i < sizeA){
    out[k++] = a[i++];
  }

  while(j < sizeB){
    out[k++] = b[j++];
  }

}

void MergeSort(int list[], int n){
  if(n <= 1){
    return ;
  }
  int i;
  int mid = n / 2;

  int sizeA = mid;
  int sizeB = n - mid;

  int* a = (int*) malloc(sizeof(int) * sizeA);
  int* b = (int*) malloc(sizeof(int) * sizeB);

  for(i = 0; i < mid; i++){
    a[i] = list[i];
  }

  for(i = mid; i < n; i++){
    b[i - mid] = list[i];
  }

  MergeSort(a, sizeA);
  MergeSort(b, sizeB);
  merge(list, a, sizeA, b, sizeB);
  free(a);
  free(b);
}
