#include "minheap.h"

void HeapMinMoveUpRec(Heap* h, int i) {

	if (i == 0 || i > (int)h->size) {
		return;
	}
	
	if (ElemCompare(HeapGetNodeValue(h, i), HeapGetNodeValue(h, HeapParent(i))) < 0) {
		ElemSwap(HeapGetNodeValue(h, i), HeapGetNodeValue(h, HeapParent(i)));
		i = HeapParent(i);

		HeapMinMoveUpRec(h, i);
	}
}