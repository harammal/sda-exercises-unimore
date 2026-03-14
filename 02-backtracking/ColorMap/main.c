#include "colormap.h"

void SetAdjacencies(SquareMatrix* m, int a, const int* b, size_t b_size) {
	for (int i = 0; i < (int)b_size; ++i) {
		m->data[a * m->side + b[i]] = 1;
		m->data[b[i] * m->side + a] = 1;
	}
}

void PrintMatrix(SquareMatrix* m) {
	for (int r = 0; r < (int)m->side; ++r) {
		for (int c = 0; c < (int)m->side; ++c) {
			printf("[%d]", m->data[r * m->side + c]);
		}
		puts("");
	}
}

int main(void) {
	int s;

	size_t mside = 3;
	SquareMatrix m = { .data = calloc(mside * mside, sizeof(bool)), .side = mside };
	int i0[] = { 0, 1, 2 };
	SetAdjacencies(&m, 0, i0, sizeof(i0) / sizeof(int));

	int i1[] = { 0, 1 };
	SetAdjacencies(&m, 1, i1, sizeof(i1) / sizeof(int));
	
	int i2[] = { 0, 2 };
	SetAdjacencies(&m, 2, i2, sizeof(i2) / sizeof(int));

	PrintMatrix(&m);
	puts("");

	s = ColorMap(&m, "rv");

	return s;
}