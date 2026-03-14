#include "elemtype.h"
#include <stdio.h>

extern void BubbleSort(ElemType* v, int dim);

int main(void) {
	
	int v[] = { 4, 4, 2, 7, 1 , 6};
	for (int i = 0; i < 6; ++i) {
		printf("%d ", v[i]);
	}
	printf("\n\n");

	BubbleSort(v, 6);

	for (int i = 0; i < 6; ++i) {
		printf("%d ", v[i]);
	}
	printf("\n");

	return 0;
}