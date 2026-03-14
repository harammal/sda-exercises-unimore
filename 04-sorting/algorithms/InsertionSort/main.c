#include "elemtype.h"
#include <stdio.h>

extern void InsertionSort(ElemType* v, int dim);

int main(void) {
	
	int v[] = { 4, 6, 2, 7, 1 };
	for (int i = 0; i < 5; ++i) {
		printf("%d ", v[i]);
	}
	printf("\n\n");

	InsertionSort(v, 5);

	for (int i = 0; i < 5; ++i) {
		printf("%d ", v[i]);
	}
	printf("\n");

	return 0;
}