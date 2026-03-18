#include "minheap.h"
#include <stdlib.h>
#include <string.h>

Heap* HeapCopy(const Heap* h) {
	if (h == NULL) {
		return NULL;
	}

	Heap* cpy = HeapCreateEmpty();

	if (h->size > 0) {
		cpy->size = h->size;
		cpy->data = realloc(cpy->data, cpy->size * sizeof(ElemType));
	}
	
	for (size_t i = 0; i < h->size; ++i) {
		cpy->data[i] = ElemCopy(HeapGetNodeValue(h, i));
	}

	return cpy;
}