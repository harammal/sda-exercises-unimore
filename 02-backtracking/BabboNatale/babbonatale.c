#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

void BabboNataleRec(const int* pacchi, size_t pacchi_size, int p, unsigned int i, bool *vcurr, bool *vbest, int *max, int cnt) {

	if (i == pacchi_size) {
		if (cnt > *max) {
			*max = cnt;
			for (size_t j = 0; j < pacchi_size; ++j) {
				vbest[j] = vcurr[j];
			}
		}

		return;
	}


	vcurr[i] = 0;
	BabboNataleRec(pacchi, pacchi_size, p, i + 1, vcurr, vbest, max, cnt);

	if (pacchi[i] <= p) {
		vcurr[i] = 1;
		BabboNataleRec(pacchi, pacchi_size, p - pacchi[i], i + 1, vcurr, vbest, max, cnt + 1);
	}

}

void BabboNatale(const int* pacchi, size_t pacchi_size, int p) {

	bool* vcurr = malloc(sizeof(bool) * pacchi_size);
	bool* vbest = malloc(sizeof(bool) * pacchi_size);

	int max = 0;

	BabboNataleRec(pacchi, pacchi_size, p, 0, vcurr, vbest, &max, 0);

	for (size_t i = 0; i < pacchi_size; i++) {
		printf("%d", vbest[i]);
		if (i != pacchi_size - 1) {
			printf(" ");
		}
	}
	printf("\n");

	free(vcurr);
	free(vbest);
}