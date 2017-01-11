#include "sort.h"

void SelectSort(int list[], int n) {
  int min; // 최솟값을 저장하기 위함
  int min_index; // 최솟값을 가리키고 있는 인덱스
  int temp; // 임시저장 변수

  for(int i = 0; i < n; i++){
    min = list[i];
    min_index = i;
    for(int j = i+1; j < n; j++){
      if(list[j] < min){
        min = list[j];
        min_index = j;
      }
    }
    if(i != min_index){
      temp = list[i];
      list[i] = list[min_index];
      list[min_index] = temp;
    }
  }
}
