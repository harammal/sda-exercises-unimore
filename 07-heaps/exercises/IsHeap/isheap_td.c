#include "minheap.h"

// Approccio Top Down

bool IsHeap(const Heap* h) {
	if (HeapIsEmpty(h)) {
		return true;
	}
	if (h == NULL) {
		return false;
	}

	for (int i = 0; i <= (int)h->size / 2 - 1; ++i) {
		int l = HeapLeft(i);
		int r = HeapRight(i);

		if ((l < (int)h->size) && ElemCompare(HeapGetNodeValue(h, l), HeapGetNodeValue(h, i)) < 0) {
			return false;
		}

		if ((r < (int)h->size) && ElemCompare(HeapGetNodeValue(h, r), HeapGetNodeValue(h, i)) < 0) {
			return false;
		}
	}

	return true;
}