#include "minheap.h"

extern Heap* HeapMinHeapify(const ElemType* v, size_t v_size);

int main(void) {
	int v[] = { 6, 5, 4, 3, 2, 1 };

	Heap* h = HeapMinHeapify(v, 6);

	HeapWriteStdout(h);

	HeapDelete(h);

	return 0;
}