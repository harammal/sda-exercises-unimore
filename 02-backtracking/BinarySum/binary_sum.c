#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void BinarySumRec(int n, bool *vcurr, int i, int *cnt) {
	if (i == n) {
		int cifre_d = 0, cifre_s = 0;
		for (int j = 0; j < n; ++j) {
			if ((n % 2) != 0 && j == (n / 2)) {
				continue;
			}
			if (j < (n / 2)) {
				cifre_d += vcurr[j];
			}
			else
				if (j >= (n / 2)) {
					cifre_s += vcurr[j];
				}
		}

		if ((cifre_d - cifre_s) == 0) {
			(*cnt)++;
			for (int j = 0; j < n; ++j) {
				printf("%d", vcurr[j]);
			}
			printf("\n");
			return;
		}
		else {
			return;
		}
	}

	vcurr[i] = 0;
	BinarySumRec(n, vcurr, i + 1, cnt);
	vcurr[i] = 1;
	BinarySumRec(n, vcurr, i + 1, cnt);
}

int BinarySum(int n) {
	if (n <= 0) {
		return 0;
	}
	bool* vcurr = calloc(n, sizeof(bool));
	if (vcurr == NULL) {
		return 0;
	}
	int cnt = 0;
	BinarySumRec(n, vcurr, 0, &cnt);

	free(vcurr);

	return cnt;
}

//int main(void) {
//	printf("\n%d", BinarySum(5));
//
//	return 0;
//}