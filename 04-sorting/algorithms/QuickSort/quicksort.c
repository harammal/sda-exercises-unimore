#include "elemtype.h"

void QuickSort(ElemType* A, int first, int last) {
	if (first < last) {
		int i = first, j = last;
		ElemType pivot = ElemCopy(A + last);

		do {
			while (ElemCompare(A + i, &pivot) < 0) {
				i++;
			}
			while (ElemCompare(A + j, &pivot) > 0) {
				j--;
			}
			if (i <= j) {
				ElemSwap(A + i, A + j);
				i++;
				j--;
			}
		} while (i <= j);

		QuickSort(A, first, j);
		QuickSort(A, i, last);
	}
}