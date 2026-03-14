#include <stdio.h>

void SubsetK(int n, int i, int k, int vcurr[], int count, int* nsol)
{	if (count == k) { // stampa soluzione
	printf("%d) ", *nsol);
	(*nsol)++;
	for (int j = 0;j < i;j++) {
		printf("%d ", vcurr[j]);
	}
	for (int j = i;j < n;j++) {
		printf("0 "); }
			printf("\n");
		return;
	}
	if (i == n) return;
	vcurr[i] = 0;
	SubsetK(n, i + 1, k, vcurr, count, nsol);
	vcurr[i] = 1;
	count++;
	SubsetK(n, i + 1, k, vcurr, count, nsol);
}