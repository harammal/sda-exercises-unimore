#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int* Divisori(int n, size_t *size_div) {
	size_t cap = 5;
	int* div = calloc(cap, sizeof(int));

	for (int i = 1; i <= n/2; ++i) {
		if (n % i == 0) {
			if (*size_div == cap) {
				cap *= 2;
				div = realloc(div, cap * sizeof(int));
			}
			div[*size_div] = i;
			(*size_div)++;
		}
	}
	if (*size_div == 0) {
		free(div);
		return NULL;
	}
	return div;
}

void VerificaPseudoperfettoRec(int n, int *div, size_t size_div, int i, bool *ris, int somma) {

	if (*ris) {
		return;
	}

	if (somma == n) {
		*ris = true;
		return;
	}

	if (i == (int)size_div) {
		return;
	}

	if (somma + div[i] <= n) {
		VerificaPseudoperfettoRec(n, div, size_div, i + 1, ris, somma + div[i]);
	}
	VerificaPseudoperfettoRec(n, div, size_div, i + 1, ris, somma);
}

bool VerificaPseudoperfetto(int n) {
	if (n <= 0) {
		return false;
	}

	size_t size_div = 0;
	int* div = Divisori(n, &size_div);
	if (div == NULL) {
		return false;
	}
	bool ris = false;

	VerificaPseudoperfettoRec(n, div, size_div, 0, &ris, 0);

	free(div);

	return ris;
}