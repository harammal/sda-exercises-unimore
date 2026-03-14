#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

void SubsetKRec(int n, int k, bool *vcurr, int i, int *nsol, int cnt) { // i si manda per copia perché nel backtracking bisogna tornare all' i = 0, per indirizzo quando si ritorna i = ultimo livello
	
		//int cnt = 0;
		//for (int j = 0; j < n; ++j) {
		//	if (vcurr[j]) {
		//		cnt++;
		//	}
		//} // tolta per ottimizzazione del conteggio

	if (cnt == k) {
		// La soluzione è valida e posso stamparla
		(*nsol)++;
		printf("{ ");
		for (int j = 0; j < i; ++j) {
			if (vcurr[j]) {
				printf("%i ", j);
			}
		}
		printf("}, ");
		return;
	}
	
	if (i == n) {
		return;
	}
	
	vcurr[i] = 0;
	SubsetKRec(n, k, vcurr, i + 1, nsol, cnt);

	vcurr[i] = 1;
	SubsetKRec(n, k, vcurr, i + 1, nsol, cnt + 1);
}

int SubsetK(int n, int k) {

	bool* vcurr = malloc(sizeof(bool) * n);
	int nsol = 0;
	SubsetKRec(n, k, vcurr, 0, &nsol, 0);

	return nsol;
}

int main(void) {
	int nsol = SubsetK(4, 2);

	return 0;
}