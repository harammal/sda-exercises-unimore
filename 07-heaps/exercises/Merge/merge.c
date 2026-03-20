#include "minheap.h"
#include <stdlib.h>

Heap* HeapMerge(const Heap* h1, const Heap* h2) {
	Heap* h3 = HeapCreateEmpty();
	
	if (!HeapIsEmpty(h1)) {
		for (size_t i = 0; i < h1->size; ++i) {
			HeapMinInsertNode(h3, HeapGetNodeValue(h1, i));
		}
	}

	if (!HeapIsEmpty(h2)) {

		for (size_t i = 0; i < h2->size; ++i) {
			HeapMinInsertNode(h3, HeapGetNodeValue(h2, i));
		}
	}

	return h3;
}