#include "minheap.h"

void HeapMinHeapSort(Heap* h) {
	if (h == NULL) {
		return;
	}

	size_t original_size = h->size;

	while (h->size > 1) {
		ElemSwap(HeapGetNodeValue(h, 0), HeapGetNodeValue(h, (int)h->size - 1));
		h->size--;

		HeapMinMoveDown(h, 0);
	}

	h->size = original_size;
}

// Se infine volessi l'ordinamento opposto posso implementare una funzione Reverse Array

void HeapReverseArray(Heap* h) {
	if (h == NULL || h->size <= 1) {
		return;
	}

	for (size_t i = 0; i < h->size / 2; ++i) {
		ElemSwap(HeapGetNodeValue(h, i), HeapGetNodeValue(h, h->size - 1 - i));
	}
}
