#include "elemtype.h"

void InsertionSort(ElemType* v, int dim) {

	for (int i = 0; i < dim; ++i) {
		ElemType temp = ElemCopy(v + i);
		int j = i;

		while (j > 0 && ElemCompare(v + (j - 1), &temp) > 0) {
			ElemDelete(v + j);
			v[j] = ElemCopy(v + (j - 1));
			j--;
		}
		ElemDelete(v + j);
		v[j] = ElemCopy(&temp);
		ElemDelete(&temp);
	}
}