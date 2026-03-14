#include "vettore.h"
#include <stdio.h>

int main(void) {

	Vector *v = VectorRead("input_int_01.txt");

	for (size_t i = 0; i < v->size; ++i) {
		printf("%d ", v->data[i]);
	}
	printf("\n");

	if (v != NULL) {
		free(v->data);
		free(v);
	}

	v = VectorReadSorted("input_int_01.txt");

	for (size_t i = 0; i < v->size; ++i) {
		printf("%d ", v->data[i]);
	}
	printf("\n");

	if (v != NULL) {
		free(v->data);
		free(v);
	}

	return 0;
}