#include "sort.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

void rxSort(int *data, int size, int p, int k) {
  int* counts; // 특정자리에서 숫자들의 카운트
  int* temp; // 정렬된 배열을 담을 임시장소
  int index, pval, i, j, n;

  if ( (counts = (int *)malloc(k * sizeof(int))) == NULL ){
    return;
  }

  if ( (temp = (int *)malloc(size * sizeof(int))) == NULL ){
    return;
  }

  for (n = 0; n < p; n++) { // 1의 자리, 10의자리, 100의 자리 순으로 진행
    for (i = 0; i < k; i++){
      counts[i] = 0; // 초기화
    }

    pval = (int)pow((double)k, (double)n);

    // 각 숫자의 발생횟수를 세기위한 부분
    for (j = 0; j < size; j++) {
      index = (int)(data[j] / pval) % k;
      counts[index] = counts[index] + 1;
    }

    for (i = 1; i < k; i++) {
      counts[i] = counts[i] + counts[i-1];
    }

    for (j = size-1; j >= 0; j--) {
      index = (int)(data[j] / pval) % k;
      temp[counts[index] -1] = data[j];
      counts[index] = counts[index] - 1;
    }

    memcpy(data, temp, size * sizeof(int));
  }
}

void RadixSort(int list[], int n) {
  rxSort(list, n, 3, 10);
}
