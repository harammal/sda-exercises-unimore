#include "minheap.h"
#include <stdlib.h>

bool HeapMinPop(Heap* h, ElemType* e) {
	if (h->size == 0) {
		return false;
	}

	*e = ElemCopy(HeapGetNodeValue(h, 0));

	ElemSwap(HeapGetNodeValue(h, 0), HeapGetNodeValue(h, (int)h->size - 1));
	ElemDelete(HeapGetNodeValue(h, (int)h->size - 1));
	h->size--;
	h->data = realloc(h->data, sizeof(ElemType) * h->size);

	HeapMinMoveDown(h, 0);

	return true;
}