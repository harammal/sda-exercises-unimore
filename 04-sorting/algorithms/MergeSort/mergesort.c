#include "elemtype.h"
#include <stdlib.h>

void Merge(ElemType* A, int first, int middle, int last) {
	int size = last - first + 1;
	ElemType* B = malloc(size * sizeof(ElemType));
	int i = first, j = middle + 1, k = 0;

	while (i <= middle && j <= last) {
		if (ElemCompare(A + i, A + j) < 0) {
			B[k++] = ElemCopy(A + i);
			i++;
		}
		else {
			B[k++] = ElemCopy(A + j);
			j++;
		}
	}

	while (i <= middle) {
		B[k++] = ElemCopy(A + i);
		i++;
	}
	while (j <= last) {
		B[k++] = ElemCopy(A + j);
		j++;
	}
	for (int i = 0; i < size; ++i) {
		ElemDelete(A + (first + i));
		A[first + i] = ElemCopy(B + i);
	}
}

void MergeSort(ElemType* A, int first, int last) {
	if (first < last) {
		int middle = (first + last) / 2;
		MergeSort(A, first, middle);
		MergeSort(A, middle + 1, last);
		Merge(A, first, middle, last);
	}
}