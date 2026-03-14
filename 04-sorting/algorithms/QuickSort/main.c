#include "elemtype.h"
#include <stdio.h>

extern void QuickSort(ElemType* A, int first, int last);

int main(void) {

	int v[] = { 4, 7, 4, 2, 1, 6 };
	for (int i = 0; i < 6; ++i) {
		printf("%d ", v[i]);
	}
	printf("\n\n");

	QuickSort(v, 0, 5);

	for (int i = 0; i < 6; ++i) {
		printf("%d ", v[i]);
	}

	return 0;
}