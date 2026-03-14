#include "torrecartoni.h"
#include <stdio.h>
#include <stdbool.h>

extern void TorreCartoniRec(const Cartone* c, size_t n, int *nsol, int *vcurr, size_t i, int *cbest, unsigned int peso, int altezza, int *max_altezza, bool *usati)
{
	if (i == n) {
		(*nsol)++;

		if (altezza > *max_altezza) {
			*max_altezza = altezza;
			for (size_t j = 0; j < n; j++) {
				cbest[j] = vcurr[j];
			}
		}
		return;
	}

	for (size_t j = 0; j < n; j++) {
		if (!usati[j] && peso <= c[j].l) {
			vcurr[i] = j;
			usati[j] = true;

			TorreCartoniRec(c, n, nsol, vcurr, i + 1, cbest, peso + c[j].p, altezza + c[j].a, max_altezza, usati);
		
			usati[j] = false;
		}
	}

	vcurr[i] = -1;
	TorreCartoniRec(c, n, nsol, vcurr, i + 1, cbest, peso, altezza, max_altezza, usati);
}

extern void TorreCartoni(const Cartone* c, size_t n)
{
	int nsol = 0, max_altezza = 0;
	int* vcurr = calloc(n, sizeof(int));
	int* cbest = calloc(n, sizeof(int));
	bool* usati = calloc(n, sizeof(bool));

	TorreCartoniRec(c, n, &nsol, vcurr, 0, cbest, 0, 0, &max_altezza, usati);

	for (size_t j = 0; j < n; j++) {
		if (cbest[j] == -1) {
			continue;
		}
		printf("%d\n", cbest[j]);
	}
	printf("Altezza: %d cm", max_altezza);

	free(vcurr);
	free(cbest);
	free(usati);
}