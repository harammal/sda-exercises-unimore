#include "elemtype.h"

void BubbleSort(ElemType* v, int dim) {
	int ordinato = 0;

	while (dim > 1 && !ordinato) {
		ordinato = 1;

		for (int i = 0; i < dim - 1;++i) {
			if (ElemCompare(v + i, v + (i + 1)) > 0) {
				ElemSwap(v + i, v + (i + 1));
				ordinato = 0;
			}
		}
		dim--;
	}
}