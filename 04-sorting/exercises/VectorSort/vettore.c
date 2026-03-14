#include "vettore.h"

// Bubble Sort
void VectorSort(Vector* v) {
	if (v == NULL) {
		return;
	}

	size_t dim = v->size;
	int ordinato = 0;

	while (dim > 1 && !ordinato) {
		ordinato = 1;
		for (size_t i = 0; i < dim - 1; ++i) {

			if (ElemCompare(v->data + i, v->data + (i + 1)) > 0) {
				ElemSwap(v->data + i, v->data + (i + 1));
				ordinato = 0;
			}
		}
		dim--;
	}
}