#include "minheap.h"

void HeapMinHeapsort(Heap* h) {
	if (h == NULL) {
		return;
	}
	
	size_t original_size = h->size;

	while ((int)h->size >= 2) {
		ElemSwap(HeapGetNodeValue(h, 0), HeapGetNodeValue(h, (int)h->size - 1));
		h->size--;
		HeapMinMoveDown(h, 0);
	}

	h->size = original_size;
}