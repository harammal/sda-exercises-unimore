#include "prezzo.h"
#include <stdbool.h>

void TrovaArticoliRec(const Articolo* a, size_t a_size, int sum, bool* vcurr, int i) {

	if (sum == 0) {
		for (int j = 0; j < a_size; ++j) {
			if (vcurr[j]) {
				printf("%s, ", a[j].nome);
			}
		}
		printf("\n");

		return;
	}

	if (i == a_size) {
		return;
	}

	vcurr[i] = 0;
	TrovaArticoliRec(a, a_size, sum, vcurr, i + 1);

	if (sum - a[i].prezzo >= 0) {
		vcurr[i] = 1;
		TrovaArticoliRec(a, a_size, sum - a[i].prezzo, vcurr, i + 1);

		vcurr[i] = 0;
	}
}

void TrovaArticoli(const Articolo* a, size_t a_size, int sum) {
	if (a == NULL || a_size == 0) {
		return;
	}
	bool *vcurr = calloc(a_size, sizeof(bool));

	TrovaArticoliRec(a, a_size, sum, vcurr, 0);

	free(vcurr);
}