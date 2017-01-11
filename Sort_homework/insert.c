#include "sort.h"
// 거의 정렬이 돼있을 때 좋음
// 최솟값 하나를 찾아서
void InsertionSort(int list[], int n) {
  int temp; // 임시저장용 변수

  for(int i = 1; i < n; i++){
    temp = list[i];
    int j = i-1;
    while(j >= 0 && list[j] > temp){
      list[j+1] = list[j];
      j = j-1;
    }
    list[j+1] = temp;
  }
}
