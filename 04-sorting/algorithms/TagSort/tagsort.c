#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

int TrovaPosMin(const int* v, size_t v_size, bool *usati) {
	int min = INT_MAX;
	int posmin = -1;

	for (size_t i = 0; i < v_size; ++i) {
		if (v[i] <= min && !usati[i]) {
			min = v[i];
			posmin = (int)i;
		}
	}

	usati[posmin] = true;
	return posmin;
}

int* TaggedSort(const int* v, size_t v_size) {
	if (v == NULL) {
		return NULL;
	}
	
	int* v_tagged = malloc(v_size * sizeof(int));
	bool* usati = calloc(v_size, sizeof(bool));

	for (size_t i = 0; i < v_size; ++i) {
		int posmin = TrovaPosMin(v, v_size, usati);

		v_tagged[i] = posmin;
	}

	free(usati);

	return v_tagged;
}