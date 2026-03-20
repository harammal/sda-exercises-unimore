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

extern void HeapMinMoveUpRec(Heap* h, int i);

int main(void) {
	int v[] = { 1, 4, 3, 2, 6, 5 };

	Heap* h = Heapify(v, 6);
	HeapWriteStdout(h);

	HeapMinMoveUpRec(h, 3);
	HeapWriteStdout(h);

	HeapDelete(h);

	return 0;
}