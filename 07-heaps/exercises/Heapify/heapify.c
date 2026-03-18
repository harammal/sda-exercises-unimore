#include "minheap.h"
#include <stdlib.h>
#include <string.h>

Heap* HeapMinHeapify(const ElemType* v, size_t v_size) {
	if (v == NULL) {
		return HeapCreateEmpty();
	}

	Heap* h = HeapCreateEmpty();

	h->size = v_size;
	h->data = malloc(v_size * sizeof(ElemType));
	memcpy(h->data, v, v_size * sizeof(ElemType));

	for (int i = (int)h->size / 2 - 1; i >= 0; i--) {
		HeapMinMoveDown(h, i);
	}

	return h;
}