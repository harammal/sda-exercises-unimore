#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool Verifica(int u, int c, int p, bool *usati) {
	if (abs(p - c) <= u && !usati[p]) {
		return true;
	}
	else {
		return false;
	}
}

void CacciatorePredaRec(const char* v, size_t v_size, int u, int i, int* vcurr, int* vbest, int cnt, int* max, bool* usati) {

	if (i == (int)v_size) {
		if (cnt > *max) {
			*max = cnt;
			for (int j = 0; j < (int)v_size; ++j) {
				vbest[j] = vcurr[j];
			}
		}

		for (int j = 0; j < (int)v_size; ++j) {
			if (vcurr[j] < 0) {
				printf("|  %d ", vcurr[j]);
			}
			else {
				printf("|   %d ", vcurr[j]);
			}
		}
		printf("|\n");

		return;
	}

	if (v[i] == 'C' || v[i] == 'c') {
		bool found = false;

		for (int j = 0; j < (int)v_size; ++j) {
			if ((v[j] == 'P' || v[j] == 'p') && Verifica(u, i, j, usati)) {
				int old_i = vcurr[i], old_j = vcurr[j];
				vcurr[i] = j;
				vcurr[j] = -2;
				usati[j] = true;


				CacciatorePredaRec(v, v_size, u, i + 1, vcurr, vbest, cnt + 1, max, usati);

				vcurr[i] = old_i;
				vcurr[j] = old_j;
				usati[j] = false;

				found = true;
			}
		}

		if (!found) {
			vcurr[i] = -1;
			CacciatorePredaRec(v, v_size, u, i + 1, vcurr, vbest, cnt, max, usati);
		}

	} else if (v[i] == 'P' || v[i] == 'p') {
		if (!usati[i]) {
			vcurr[i] = -1;
		}
		CacciatorePredaRec(v, v_size, u, i + 1, vcurr, vbest, cnt, max, usati);

	} else {
		vcurr[i] = -1;
		CacciatorePredaRec(v, v_size, u, i + 1, vcurr, vbest, cnt, max, usati);
	}
}

int* CacciatorePreda(const char* v, size_t v_size, int u) {
	if (v == NULL || v_size == 0 || u <= 0) {
		return NULL;
	}

	int* vcurr = malloc(v_size * sizeof(int));
	int* vbest = malloc(v_size * sizeof(int));
	bool* usati = calloc(v_size, sizeof(bool));
	int max = 0;

	for (int i = 0; i < (int)v_size; ++i) {
		vcurr[i] = -1;
		vbest[i] = -1;
	}

	for (int i = 0; i < (int)v_size; ++i) {
		printf("| %d-%c ", i, v[i]);
	}
	printf("|\n");

	CacciatorePredaRec(v, v_size, u, 0, vcurr, vbest, 0, &max, usati);
	free(vcurr);
	free(usati);

	return vbest;
}