#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool Verifica(int n, int k, int *numero) {
	for (int j = 0; j < n - 1; ++j) {
		if (abs(numero[j] - numero[j + 1]) != k) {
			return false;
		}
	}

	return true;
}

void DifferenzeRec(int n, int k, size_t* v_len, size_t* cap, int *numero, int **vcurr, int cnt) {

	if (cnt == n) {
		if (Verifica(n, k, numero)) {
			if (*v_len == *cap) {
				(*cap) *= 2;
				*vcurr = realloc(*vcurr, (*cap) * sizeof(int));
			}

			(*vcurr)[*v_len] = 0;
			for (int j = 0; j < n; ++j) {
				(*vcurr)[*v_len] = ((*vcurr)[*v_len] * 10) + numero[j];
			}

			(*v_len)++;
		}
		return;
	}

	for (int j = 0; j <= 9; ++j) {
		if (cnt == 0 && j == 0) {
			continue;
		}
		else {
			numero[cnt] = j;
			DifferenzeRec(n, k, v_len, cap, numero, vcurr, cnt + 1);
		}
	}
}

int* Differenze(int n, int k, size_t* v_len) {
	*v_len = 0;

	if (n <= 0 || k < 0) {
		*v_len = 0;
		return NULL;
	}

	int* numero = calloc(n, sizeof(int));
	size_t cap = 5;
	int* vcurr = malloc(cap * sizeof(int));

	DifferenzeRec(n, k, v_len, &cap, numero, &vcurr, 0);

	if (*v_len == 0) {
		free(numero);
		free(vcurr);

		return NULL;
	}

	if (*v_len < cap) {
		vcurr = realloc(vcurr, (*v_len) * sizeof(int));
	}
	free(numero);

	return vcurr;
}