#include "minheap.h"

void HeapMaxMoveDown(Heap* h, int i) {
    int l, r, larger = i;
    bool done;
    do {
        done = true;
        l = HeapLeft(i);
        r = HeapRight(i);

        if ((l < (int)h->size) && ElemCompare(HeapGetNodeValue(h, l), HeapGetNodeValue(h, larger)) > 0) {
            larger = l;
        }

        if ((r < (int)h->size) && ElemCompare(HeapGetNodeValue(h, r), HeapGetNodeValue(h, larger)) > 0) {
            larger = r;
        }

        if (larger != i) {
            ElemSwap(HeapGetNodeValue(h, i), HeapGetNodeValue(h, larger));
            i = larger;
            done = false;
        }

    } while (!done);
}


void HeapMin2HeapMax(Heap* h) {
	if (HeapIsEmpty(h) || h == NULL) {
		return;
	}

	for (int i = (int)h->size / 2 - 1; i >= 0; i--) {
        HeapMaxMoveDown(h, i);
	}
}