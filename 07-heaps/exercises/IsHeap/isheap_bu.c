#include "minheap.h"

// Approccio Bottom Up

bool IsHeap(const Heap* h) {
	if (HeapIsEmpty(h)) {
		return true;
	}
	if (h == NULL) {
		return false;
	}

	for (int i = (int)h->size - 1; i > 0; i--) {
		if (ElemCompare(HeapGetNodeValue(h, i), HeapGetNodeValue(h, HeapParent(i))) < 0) {
			return false;
		}
	}

	return true;
}