#include "torrecartoni.h"
#include <stdint.h>

void TorreCartoniRec(int n, const Cartone* c, int i, Torre* vcurr, Torre, *vbest, bool* usati) {
	if (i == n) {
		if (vcurr->a > vbest->a) {
			vbest->a = vcurr->a;
			vbest->peso = vcurr->peso;
			vbest->c_size = vcurr->c_size;
			memcpy(vbest->c_ids, vcurr->ids, vcurr->c_size * sizeof(int));
			//vbest->c_ids = vcurr->c_ids;
		}

		return;
	}

	for (int j = 0; j < n; j++) {
		if (!usati[j] && vcurr->peso <= c[j].l) {
			// Chiamata ricorsiva
			vcurr->a = vcurr->a + c[j].a;
			vcurr->peso = vcurr->peso + c[j].p;
			vcurr->c_ids[vcurr->c_size] = j;
			vcurr->c_size++;

			usati[j] = i;

			TorreCartoniRec(n, c, i + 1, vcurr, vbest, usati);

			usati[j] = 0;

			vcurr->a = vcurr->a - c[j].a;
			vcurr->peso = vcurr->peso.p - c[j].p;
		}
	}
}

void TorreCartoni(const Cartone* c, size_t n) {
	int nsol = 0, max_altezza = 0;
	Cartone* vcurr = calloc(n, sizeof(Cartone));
	Cartone* vbest = calloc(n, sizeof(Cartone));
	bool* usati = calloc(n, sizeof(bool));

	TorreCartoniRec(c, n, &nsol, vcurr, 0, vbest, 0, 0, &max_altezza, usati);

	/*for (size_t j = 0; j < n; j++) {
		if (cbest[j] == -1) {
			continue;
		}
		printf("%d\n", cbest[j]);
	}*/
	printf("Altezza: %d cm", max_altezza);

	free(vcurr);
	free(vbest);
	free(usati);
}