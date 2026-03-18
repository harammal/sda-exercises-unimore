#include "get_pop.h"

ElemType* Get(const Heap* h){
	if (HeapIsEmpty(h) || h == NULL) {
		return NULL;
	}
	return HeapGetNodeValue(h, 0);
}

void Pop(Heap* h) {
	if (HeapIsEmpty(h) || h == NULL) {
		return;
	}

	ElemSwap(HeapGetNodeValue(h, 0), HeapGetNodeValue(h, (int)h->size - 1));
	ElemDelete(HeapGetNodeValue(h, (int)h->size - 1));
	h->size--;
	h->data = realloc(h->data, h->size * sizeof(ElemType));

	HeapMinMoveDown(h, 0);
}