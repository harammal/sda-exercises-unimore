#include <stdlib.h>
#include <stdio.h>

void SumOfSubsetXORsRec(const int* v, size_t v_size, int *somma, size_t i, int curr_xor) {
	if (i == v_size) {
		
		*somma += curr_xor;

		return;
	}

	SumOfSubsetXORsRec(v, v_size, somma, i + 1, curr_xor);

	SumOfSubsetXORsRec(v, v_size, somma, i + 1, curr_xor ^ v[i]);
}

int SumOfSubsetXORs(const int* v, size_t v_size) {
	if (v == NULL) {
		return 0;
	}
	int somma = 0;

	SumOfSubsetXORsRec(v, v_size, &somma, 0, 0);

	return somma;
}