#include "sort.h"

void BubbleSort(int list[], int n) {
  for(int i = n - 1; i > 0 ; i--) {
    for(int j = 0; j < i; j++) {
      if (list[j] > list[j + 1]) {
        Swap(list, j, j + 1);
      }
    }
  }
}
