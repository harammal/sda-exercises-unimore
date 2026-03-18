#include "minheap.h"
#include <stdlib.h>

static Heap* HeapCopy(const Heap* h) {
	if (h == NULL) {
		return NULL;
	}
	Heap* cpy = HeapCreateEmpty();

	if (!HeapIsEmpty(h)) {
		cpy->size = h->size;
		cpy->data = realloc(cpy->data, cpy->size * sizeof(ElemType));
	}

	for (size_t i = 0; i < (int)h->size; ++i) {
		cpy->data[i] = ElemCopy(HeapGetNodeValue(h, i));
	}

	return cpy;
}

ElemType KthLeast(const Heap* h, int k) {
	Heap* cpy = HeapCopy(h);
	
	while (k - 1 > 0) {
		ElemSwap(HeapGetNodeValue(cpy, 0), HeapGetNodeValue(cpy, (int)cpy->size - 1));
		cpy->size--;
		k--;

		HeapMinMoveDown(cpy, 0);
	}

	ElemType e = ElemCopy(HeapGetNodeValue(cpy, 0));
	
	cpy->size = h->size;
	HeapDelete(cpy);

	return e;
}