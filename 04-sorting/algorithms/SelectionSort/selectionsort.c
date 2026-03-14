#include "elemtype.h"

int TrovaPosMax(ElemType* v, int dim) {
	int posmax = 0;
	for (int i = 0; i < dim; ++i) {
		if (ElemCompare(v + i, v + posmax) > 0) {
			posmax = i;
		}
	}
	return posmax;
}

void SelectionSort(ElemType* v, int dim) {
	while (dim > 1) {
		int posmax = TrovaPosMax(v, dim);

		if (posmax < dim - 1) {
			ElemSwap(v + posmax, v + (dim - 1));
		}
		dim--;
	}
}