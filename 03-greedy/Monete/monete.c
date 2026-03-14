#include <stdlib.h>

int* Monete(const int* tagli, size_t tagli_size, int budget) {
	if (budget <= 0) {
		return NULL;
	}

	int* monete = calloc(tagli_size, sizeof(int));

	for (size_t i = 0; i < tagli_size && budget != 0; ++i) {
		monete[i] = budget / tagli[i];
		budget %= tagli[i];
	}

	return monete;
}