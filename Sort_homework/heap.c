#include "sort.h"

void HeapSort(int[],int);
void build_Heap(int[],int);
void adjust(int[],int);


void build_Heap(int list[], int n){
	int k,i,j,item;
	for (k = 1; k < n; k++) {
		item = list[k];
		i = k;
		j = (i-1)/2;
		while((i > 0) && (item > list[j])) {
			list[i] = list[j];
			i = j;
			j = (i-1)/2;
		}
		list[i] = item;
	}
}


void HeapSort(int list[], int n) {
	int i,t;
	build_Heap(list,n);
	for (i = n-1; i > 0; i--) {
		t = list[0];
		list[0] = list[i];
		list[i] = t;
		adjust(list, i);
	}
}

void adjust(int list[],int n) {
	int i,j,item;
	j = 0;
	item = list[j];
	i = 2*j+1;
	while(i <= n-1) {
		if(i+1 <= n-1)
		   if(list[i] <list[i+1])
		    i++;
		if(item < list[i]) {
			list[j] = list[i];
			j = i;
			i = 2*j+1;
		} else
		   break;
	}
	list[j] = item;
}
