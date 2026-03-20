#include "minheap.h"
#include <stdlib.h>

void DeleteNode(Heap* h, int k) {
	if (HeapIsEmpty(h)) {
		return;
	}

	if (k < 0 || k >= (int)h->size) {
		return;
	}

	if (k != (int)h->size - 1) {
		ElemSwap(HeapGetNodeValue(h, k), HeapGetNodeValue(h, (int)h->size - 1));
	}
	ElemDelete(HeapGetNodeValue(h, (int)h->size - 1));
	h->size--;
	h->data = realloc(h->data, h->size * sizeof(ElemType));

	HeapMinMoveDown(h, k);
}