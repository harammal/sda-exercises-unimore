#include "minheap.h"
#include <stdlib.h>
#include <string.h>

Heap* Heapify(const ElemType* v, size_t v_size) {
	if (v == NULL) {
		return HeapCreateEmpty();
	}

	Heap* h = HeapCreateEmpty();

	h->size = v_size;
	h->data = malloc(v_size * sizeof(ElemType));
	memcpy(h->data, v, v_size * sizeof(ElemType));

	return h;
}

extern void HeapMinMoveDownRec(Heap* h, int i);

int main(void) {
	int v[] = { 9, 3, 2, 7, 5};

	Heap* h = Heapify(v, 5);
	HeapWriteStdout(h);

	HeapMinMoveDownRec(h, 0);
	HeapWriteStdout(h);

	HeapDelete(h);

	return 0;
}