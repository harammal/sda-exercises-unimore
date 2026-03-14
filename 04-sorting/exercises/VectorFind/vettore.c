#include "vettore.h"

int BinarySearch(const Vector* v, int first, int last, ElemType target) {
	int mid;
	ElemType middle;

	while (first <= last) {
		mid = (first + last) / 2;
		middle = ElemCopy(v->data + mid);

		if (ElemCompare(&middle, &target) == 0) {
			while (mid >= 1 && ElemCompare(&middle, v->data + (mid - 1)) == 0) {
				mid--;
			}
			return mid;
		}
		else if (ElemCompare(&middle, &target) < 0) {
			first = mid + 1;
		}
		else {
			last = mid - 1;
		}

		ElemDelete(&middle);
	}
	return -1;
}

int VectorFind(const Vector* v, const ElemType* e) {
	if (v == NULL) {
		return -1;
	}

	return BinarySearch(v, 0, (int)v->size - 1, *e);
}